/********************************************************************
*
*                
*
*********************************************************************
* FileName:        Main.c
* Dependencies:    See INCLUDES section below
* Processor: 	   PIC18F46K22      
* Compiler: 	   C-18       
* Company:         Microchip Technology, Inc.
*
* Software License Agreement:
*
* The software supplied herewith by Microchip Technology Incorporated
* (the "Company") for its PICmicro® Microcontroller is intended and
* supplied to you, the Company's customer, for use solely and
* exclusively on Microchip PICmicro Microcontroller products. The
* software is owned by the Company and/or its supplier, and is
* protected under applicable copyright laws. All rights are reserved.
* Any use in violation of the foregoing restrictions may subject the
* user to criminal sanctions under applicable laws, as well as to
* civil liability for the breach of the terms and conditions of this
* license.
*
* THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
* WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
* TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
* IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
* CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
*********************************************************************/

/*


* File Description: Main module with the main() function. It includes
*                   the application code with the main state machine
*                   controlling the application's behavior.
*
* Change History:
* Author               Date        Comment
* Chris Tucker      10/18/2010  First version of module code
*********************************************************************

//*****************************************************************************
// Include and Header files
//*****************************************************************************/

#include "Lcd.h"
#include "I2c.h"
#include "rtc.h"
#include "Buttons.h"
#include "General.h"
#include "Serial.h"
#include "Sound.h"
#include "Voltmeter.h"
#include "DisplayMacros.h"

#include <p18cxxx.h>
#include <GenericTypeDefs.h>

//*****************************************************************************
// PIC Configuration
//*****************************************************************************
#pragma config FOSC = INTIO67   // Internal OSC block, Port Function on RA6/7
#pragma config PLLCFG = OFF     // OSC used Directly; PLL -Disabled
#pragma config PRICLKEN = OFF   // Primary clock can be disabled by software
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor disabled
#pragma config IESO = OFF       // OSC switch mode disabled
#pragma config PWRTEN = OFF     // Power Up Timer is disabled
#pragma config BOREN = OFF      // Brown-out Reset disabled in Hardware and Soft
#pragma config BORV = 250       // VBOR set to 2.50 V nominal
#pragma config WDTEN = OFF      // Watch Dog Timer disabled. SWDTEN no effect
#pragma config WDTPS = 1        // Watch Dog Timer Postscale 1:1
#pragma config CCP2MX = PORTC1   // CCP2 input/output is multiplexed with RC1
#pragma config PBADEN = OFF     // PORTB<5:0> pins are Config as Digital I/O on Reset
#pragma config CCP3MX = PORTE0  // P3A/CCP3 input/output is multiplexed with RE0
#pragma config HFOFST = OFF     // HFINTOSC ouput and ready status are delayed by OSC stable status
#pragma config T3CMX = PORTB5   // T3CKl is on RB5
#pragma config P2BMX = PORTC0   // P2B is on RC0
#pragma config MCLRE = EXTMCLR  // MCLR pin enabled, RE3 input pin disabled
#pragma config STVREN = OFF     // Stack full/underflow will not cause Reset
#pragma config LVP = OFF        // Single-Supply ICSP disabled
#pragma config XINST = OFF      // Instruction set Extension and indexed Addressing mode disabled
#pragma config DEBUG = OFF      // Disabled
#pragma config CP0 = OFF        // Block 0 (000800 - 001FFFh) not code-protected
#pragma config CP1 = OFF        // Block 1 (002000 - 003FFFh) not code-protected
#pragma config CP2 = OFF        // Block 2 (004000 - 005FFFh) not code-protected
#pragma config CP3 = OFF        // Block 3 (006000 - 007FFFh) not code-protected
#pragma config CPB = OFF        // Boot Block (000000 - 0007FFh) not code-protected
#pragma config CPD = OFF        // Data EEPROM not code-protected
#pragma config WRT0 = OFF       // Block 0 (000800-001FFFh) not write-protected
#pragma config WRT1 = OFF       // Block 1 (002000-003FFFh) not write-protected
#pragma config WRT2 = OFF       // Block 2 (004000-005FFFh) not write-protected
#pragma config WRT3 = OFF       // Block 3 (006000-007FFFh) not write-protected
#pragma config WRTC = OFF       // Configuration registers (300000-3000FFh) not write protected
#pragma config WRTB = OFF       // Boot Block (000000-0007FFh) not write-protected
#pragma config WRTD = OFF       // Data EEPROM not write-protected
#pragma config EBTR0 = OFF      // Block 0 (000800 - 001FFFh) not protected from table reads executed in other blocks
#pragma config EBTR1 = OFF      // Block 0 (002000 - 003FFFh) not protected from table reads executed in other blocks
#pragma config EBTR2 = OFF      // Block 0 (004000 - 005FFFh) not protected from table reads executed in other blocks
#pragma config EBTR3 = OFF      // Block 0 (006000 - 007FFFh) not protected from table reads executed in other blocks
#pragma config EBTRB = OFF      // Block 0 (000000 - 0007FFh) not protected from table reads executed in other blocks

//*****************************************************************************
// Program Version Number
//*****************************************************************************

#define Version_1_0_A

//*****************************************************************************
// Typedefs
//*****************************************************************************
	
	UINT8_T	tick;			///< Variable used to watch and store Timer 0 event flag.

//*****************************************************************************
// Definitions and Equates
//*****************************************************************************

#define TickOff		   tick	  ///< Timer0 Event flag (Set each timer0 goes off)

#define VOLTAGE_CHANGE 49                  ///< Factor for voltage calculation

///	@brief	APPLICATION'S STATE LIST FOR THE MAIN STATE MACHINE
enum State_Machine
{
 	ST_INIT        =	0,              ///< Application's state just after Start/Reset
 	ST_VOLTMETER   =	1,       		///< App is handling the Voltmeter functionality
 	ST_BUZZER      =	2,              ///< App is handling the Buzzer fonction
 	ST_TEMPERATURE =	3,     			///< App is processing Ambient temperature display
 	ST_CLOCK       =	4              	///< App is handling Clock display/Adjust
};

// Used to prevent buffer overflow
#define TEMP_UPD       	20         ///< Temperature update interval = 20*4 ms ~ 1s

#define TIMER0		0b11010111;       ///< Configure TMR0 for 4 mS increment

#define SYS_OSC		0b01010110; ///< PLL is disabled;4 MHz; Fosc is Internal

//*****************************************************************************
// Global Variables
//*****************************************************************************

 UINT8_T nState = ST_INIT,///< State machine buffer w/ initial state at start up
     	 tmrCount = 0;                               ///< Software timer counter
 UINT8_T Temp_Update = TEMP_UPD;                  ///< Temperature reading delay
 UINT8_T PWM_Freq = 5;				      ///< Preload of PWM Period

// Global Constant Strings
//*****************************************************************************

//*****************************************************************************
// Global Variable Strings
//*****************************************************************************

//*****************************************************************************
//Local Function Prototypes
//*****************************************************************************

void SysInit(void);                 ///< General system configuration and setup
void Wait2s(void);					///< 2s delay used to display splash screen

void DisplaySplashText(void);				      ///< Display the welcome Text
void StateInitial(void);					           ///< Go to initial state

void DisplayVoltMenu(void);			 ///< Displays the voltmeter selection text	
void DisplayVoltage(UINT16_T Volt);		///< Displays specified conversion data
void StateVoltage(void);					           ///< Go to voltage state

void DisplayBuzMenu(void);					///< Displays buzzer selection text
void DisplayBuzzerData(volatile UINT8_T PWM_Freq);///< Displays current buzzer parameters
void StateBuzzer (void);					            ///< Go to buzzer state

void DisplayTempMenu(void);			   ///< Displays temperature selection text
void DisplayTemperature(UINT8_T Thermal, UINT8_T Type);///< Displays current temp reading
void StateTemperature(void);			           ///< Go to temperature state

void DisplayClockMenu(void);				 ///< Displays clock selection text
void DisplayTime(void);			///< Displays current system time and selection
void Set_Time(UINT8_T Val,UINT8_T cMenu);		       ///< Go to set time function
void StateClock	(void);						         ///< Go to the clock state
void StateClock_Set (void);					         ///< Make time adjustments
void StateClock_Min (void);					                ///< Adjust minutes
void StateClock_Hrs (void);					                  ///< Adjust hours

void High_Priority_ISR(void);				///< Interrupt High Priority
void Low_Priority_ISR(void);				///< Interrupt Low Priority

///////////////////////////////////////////////////////////////////////////////
//*****************************************************************************
// INTERRUPT
//*****************************************************************************
///////////////////////////////////////////////////////////////////////////////

/********************************************************************
* Function:         Interrupt High
* 
* PreCondition: 	None
*
* Side Effects: 	None                                            
*/
/**
* @brief	        When a Interrupt occurs Function High_Priority_ISR
*					is called.
*
* @param[in]		None.
*
* @param[out]		None.
*
* @note        		THIS ROUTINE IS ONLY CALLED BY THE HARDWARE. ITS
*                   EXECUTION SHOULD REMAIN AS QUICK AS POSSIBLE.
*/
/*******************************************************************/

/** D E C L A R A T I O N S *******************************************/
#pragma code    // declare executable instructions

//----------------------------------------------------------------------------
// High priority interrupt vector

#pragma code InterruptVectorHigh = 0x08
void InterruptVectorHigh (void)
{
  _asm
    goto High_Priority_ISR 			// Jump to ISR Interrupt funciton.
  _endasm				// ISR name is unimportant but must match.
}

/********************************************************************
* Function:         Interrupt Low
* 
* PreCondition: 	None
*
* Side Effects: 	None                                            
*/
/**
* @brief	        When a Interrupt occurs Function Low_Priority_ISR
*					is called.
*
* @param[in]		None.
*
* @param[out]		None.
*
* @note        		THIS ROUTINE IS ONLY CALLED BY THE HARDWARE. ITS
*                   EXECUTION SHOULD REMAIN AS QUICK AS POSSIBLE.
*/
/*******************************************************************/

#pragma code InterruptVectorLow = 0x18
void InterruptVectorLow (void)
{
  _asm
    goto Low_Priority_ISR //jump to interrupt routine
  _endasm
}

/********************************************************************
* Function:         High Priority Interrupt 
* 
* PreCondition: 	None
*
* Side Effects: 	None                                            
*/
/**
* @brief	        The is the application's main ISR. It is called by any
*                   enabled hardware interrupt to service it. High Priority
*					Interrupt can interrupt a Low Priority Interrupt.
*
* @param[in]		None.
*
* @param[out]		None.
*
* @note        		THIS ROUTINE IS ONLY CALLED BY THE HARDWARE. ITS
*                   EXECUTION SHOULD REMAIN AS QUICK AS POSSIBLE.
*/
/*******************************************************************/

#pragma interrupt High_Priority_ISR  // "Interrupt" pragma for high priority
void High_Priority_ISR(void)		   // Interrupt fuction. Name is unimportant. 
{
/******************************* RTC EVENT EVERY SECOND ***********************/

	RTC_ISR();
}

/********************************************************************
* Function:         Low Priority Interrupt 
* 
* PreCondition: 	None
*
* Side Effects: 	None                                            
*/
/**
* @brief	        The is the application's main ISR. It is called by any
*                   enabled hardware interrupt to service it. Low Priority
*					Interrupt can be interrupted by a High Priority Interrupt.
*
* @param[in]		None.
*
* @param[out]		None.
*
* @note        		THIS ROUTINE IS ONLY CALLED BY THE HARDWARE. ITS
*                   EXECUTION SHOULD REMAIN AS QUICK AS POSSIBLE.
*/
/*******************************************************************/

#pragma interrupt Low_Priority_ISR  // "Interrupt" pragma for high priority
void Low_Priority_ISR(void)		   // Interrupt fuction. Name is unimportant. 
{
/*************************** TEMPERATURE READ INTERVAL ************************/

  if(INTCONbits.TMR0IF)                         // If Timer0 Interrupt event
  {
	    if (tmrCount)                               // If Counter Set by application
		{
	      	tmrCount--;                               // The Software timer is running
		}
    CheckButtons();                             // Go process button press

	if (!Temp_Update--)
	{
		Temp_Update = TEMP_UPD;
    	TickOff = ENABLE;                            // 16.3 ms tick just went off
	}

    INTCONbits.TMR0IF = CLEAR;                  // Interrupt has been serviced
	INTCONbits.INT0IF = CLEAR;
  }                                             // If Timer0 Interrupt

/********************************* SERIAL ISR ****************************/

	Serial_ISR();
}

///////////////////////////////////////////////////////////////////////////////
//*****************************************************************************
// MAIN FUNCTION
//*****************************************************************************
///////////////////////////////////////////////////////////////////////////////

/********************************************************************
* Function:         main
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        Main function of the application.It includes the main state
*                   machine, controlling the application behavior.
*
* @note        		None.
*/
/*******************************************************************/

void main(void)
{    	
  SysInit();                        // System Initialization

  for (;;)                          // Main Infinite loop
  {
    switch(nState)                  // Depending on current state
    {
      case ST_INIT:                 // Initialization State
		StateInitial();
		break;

      case ST_VOLTMETER:            // Voltmeter Selection mode
		StateVoltage();
		break;

      case ST_BUZZER:               // Buzzer Selection mode
		StateBuzzer();
		break;

      case ST_TEMPERATURE:          // Temperature Selection mode 
        StateTemperature();
		break;

      case ST_CLOCK:                // Clock mode selection display
        StateClock();       
		break;                            
    }                        		// Depending on current state (Main state machine)
  }                                 // Main infinite loop
}

///////////////////////////////////////////////////////////////////////////////
//*****************************************************************************
// SUPPORT FUNCTIONS
//*****************************************************************************
///////////////////////////////////////////////////////////////////////////////

/********************************************************************
* Function:         SysInit
* 
* PreCondition: 	None
*
* Side Effects: 	None                                                   
*/
/**
* @brief	        This function is called to setup all GPIOs according to
*                   their utilization by the application. It also sets the
*                   main clock frequency Fosc to 16 MHz. It finally calls all
*                   peripheral initialization routines (Comm, I2C, LCD, ...).
*
* @note        		Called by main() once at start up.
*/
/*******************************************************************/


void SysInit(void)
{
  TRISA = 0xFF;                        // All PortA pins as inputs
  TRISB = 0x01;
  TRISC = 0xBB;
  TRISD = 0x00;
  TRISE = 0xFF;

  LATA = 0x00;
  LATB = 0x00;
  LATC = 0x80;

//*****************************************************************************
// Analog Select; Analog = 1; Digital = 0;
//*****************************************************************************
  ANSELA = 0x01;
  ANSELB = 0x00;
  ANSELCbits.ANSC3 = 0;			// <-- Used In I2C. SCL
  ANSELCbits.ANSC4 = 0;			// <-- Used In I2C. SDA
  ANSELD = 0x00;
  ANSELE = 0x00;

// PLL is disabled; 4 MHz; Clock determined by FOSC in Config Word 1.
  OSCCON = SYS_OSC;                 	             // Set Internal RC to X MHz

//*****************************************************************************
// Timer and Interrupts
//*****************************************************************************

/*************** default clock on 16F1937 is 500 KHz at startup ***************/

// All weak pull-ups are disabled; Interrupt on rising edge of RB0/INT pin;
// Internal Instruction Cycle clock (FOSC/4); 
// Increment on high-to-low Transition on RA4/T0CKl pin; Prescaler is assigned
// to TMR0; Prescaller is set to: 1:256.

    T0CON = TIMER0;						// Configure TMR0 for 4 mS increment

    // Set up Interrupts for timer		// Set up timer itself
    TMR0H = CLEAR;                      	// Clear timer - always write upper byte first
    TMR0L = CLEAR;							// Clear Timer - lower bits
	INTCONbits.TMR0IF = CLEAR;				// Timer 0 Interrupt Flag
    INTCONbits.TMR0IE = ENABLE;				// Timer 0 Interrupt Enabled

    // Set up switch interrupt on INT0
    INTCON2bits.INTEDG0 = CLEAR;    	// Interrupt on falling edge of INT0 (switch pressed)
    INTCONbits.INT0IF = CLEAR;      	// Ensure flag is cleared
    INTCONbits.INT0IE = ENABLE;      		// Enable INT0 interrupt
    // NOTE: INT0 is ALWAYS a high priority interrupt

    // Set up global interrupts
	RCONbits.IPEN	= ENABLE;				// Enable priority levels on interrupts
    INTCONbits.GIEL = ENABLE;        		// Peripheral Interrupt enable
    INTCONbits.GIEH = ENABLE;        		// General Interrupt enable

    // Interrupt Priority
    INTCON2bits.TMR0IP = CLEAR;             // Timer0 is low priority interrupt
	IPR1bits.RC1IP	= CLEAR;				// EUSART1 Receive Interrupt Priority bit
	IPR1bits.TX1IP	= CLEAR;				// EUSART1 Transmit Interrupt Priority bit

//*****************************************************************************
// Initial Conditions
//*****************************************************************************

  VOLTInit();            // Go Initialize ADC Module For Voltmeter Functionality
  RTCInit();			 // Go Initialize the clock
  LCDInit();			 // Go Initialize the LCD
  I2CInit();             // Go Initialize Temp Sensor Interface
  SNDInit();             // Go Initilize the sound module
  ButtonsInit();         // Go initilize the Buttons module for input operations

#ifdef SERIAL_COM		 // If Serial Com is being used do action; else skip
  SERInit();			 // Initialized Serieal Come
  SERTxSave('\r');		 // Carriage return
  SERTxSave('\n');		 // Line Feed
  SERSendNext();  		 // Go send next available character To initialize Transmission
#endif
}

/********************************************************************
* Function:         Wait2s
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This function is called to take and keep control of the CPU
*                   for 2 seconds & return to caller. It uses a software Timer
*                   (tmrCount) that's decremented by the TIMER0 interrupt
*                   (every 16.3 ms).
*
* @note        		None.
*/
/*******************************************************************/

void Wait2s(void)
{
  tmrCount = 50;              // Timer0 tick is 16.3 ms => 123*16.3 = 2.0049 s
  while(tmrCount)              // While still counting
  {    ;	}                  // Wait here
}

///////////////////////////////////////////////////////////////////////////////
//*****************************************************************************
// State Machine FUNCTIONS
//*****************************************************************************
///////////////////////////////////////////////////////////////////////////////

/******************************************************************************
* Function: void StateInitial(void)
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This function is called when the application starts and enters the
*           		Splash display mode for 2 seconds before automatically moving on to
*           		the Voltmeter mode (state). The main state machine enters this state
*           		only once at start up. 
*
* @note        		None.
*/
/*******************************************************************/

void StateInitial (void)
{
	DisplaySplashText();                // Welcome message
	Wait2s();                  			// Leave splash screen for 2 s
    LCDClear();                         // Clear LCD for next display
    nState = ST_VOLTMETER;              // Move to next state
}

/******************************************************************************
* Function: void StateVoltage(void)
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This routine is called each time the user selects the Voltmeter
*          		 mode (e.g. state). This is the main handler for the Voltmeter. It
*          		 first displays the correct text (Voltmeter menu) and either goes to
*          		 the actual voltage display (actual reading) or moves to next mode
*          		 (Buzzer), depending on what the user selects.
*
* @note        		None.
*/
/*******************************************************************/

void StateVoltage (void)
{
  DisplayVoltMenu();                                           // Voltmeter menu
  if (BUT_PRESSED())            	         // If a button press is pending
  {
    if (RB0_PRESSED())                            // If Voltmeter mode confirmed
    {
      RESET_RB0();                                        // Event has been used
      for(;;)                                       // Voltmeter Menu Input Loop
      { 
        UINT16_T Volt = VOLTGetV(); 	      // Go get voltage on potentiometer
        DisplayVoltage(Volt);            // Go convert and display voltage value
        if (BUT_PRESSED())                     // If a button press was recorded
        {            
          if (RB0_PRESSED())                                 // If exit selected
          {
            RESET_RB0();                                  // Event has been used
            nState = ST_VOLTMETER; // Move back to Voltmeter menu selection mode
            LCDClear();                            // Clear LCD for next display
            break;                                         // Exit infinite Loop
          }                               
        }                                 
      }                                   
    }                             		
    else if (RA4_PRESSED())       	      // If Next Mode Selected (by user)
         {
           RESET_RA4();                                   // Event has been used
           nState = ST_BUZZER;                  // Move to buzzer selection mode
           LCDClear();                             // Clear LCD for next display
         } 
  }                                                  // Voltmeter selection mode
}

/******************************************************************************
* Function: void StateBuzzer(void)
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This routine is called each time the user selects the Buzzer
*           		mode (e.g. state). This is the main handler for the Buzzer. It
*           		first displays the correct text (Buzzer menu) and either goes to
*           		the buzzer activation/adjustment screen or moves on to next mode
*           		(Temperature), depending on what the user selects.
*
* @note        		None.
*/
/*******************************************************************/

void StateBuzzer(void)
{
  DisplayBuzMenu();                                               // Buzzer menu

  if (BUT_PRESSED())                             // If a button press is pending
  {
    if (RB0_PRESSED())                               // If buzzer mode confirmed
    {
      RESET_RB0();                                        // Event has been used
      LCDClear();

      for (;;)                                              // Buzzer Input loop
      {
        UINT8_T Sound = ENABLE;
        SNDSound(Sound,PWM_Freq);                           // Turn the sound On
        DisplayBuzzerData(PWM_Freq);                       // Display parameters

        if (BUT_PRESSED())                     // If a button press was recorded
        {   
          if (RB0_PRESSED())                   // If buzzer parameter alteration
          {
            RESET_RB0();                                  // Event has been used
            Sound = DISABLE;
            SNDSound(Sound,PWM_Freq);                      // Turn the sound off
            nState = ST_BUZZER;                      // Move to next menu option
            LCDClear();                                      // Clear the screen
            break;                                     // Exit the infinite loop
          }                                    // If buzzer parameter alteration
          else if (RA4_PRESSED())                       // If user wants to exit
               {
                 RESET_RA4();                             // Event has been used
			  // Ensure PWM_Freq is at correct value
		 if (PWM_Freq >= 251)
		 {
                   PWM_Freq = 5;
                 }
		 else if (PWM_Freq <= 4)
	              {
                        PWM_Freq = 5;
                      }
		      else
		      {
		        PWM_Freq += 5;
            		LCDClear();
		      }
               }                                  
        }                                     
      }                                                  
    }
    else if (RA4_PRESSED())                 // If next temp menu selected (Next)
	 {
           RESET_RA4();                                   // Event has been used
           nState = ST_TEMPERATURE;                      // Move on to next menu
	 }
  }                                                // If button press is pending
}

/******************************************************************************
* Function: void StateTemperature(void)
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This routine is called each time the application enters the
*           		temperature mode (e.g. state). This is the Temperature state handler.
*           		It first displays the correct text (or menu) where the user can either 
*           		selct to goes to display the temperature readings or move go to the 
*           		next mode (Clock). This is depending on what the user has chosen. 
*
* @note        		None.
*/
/*******************************************************************/

void StateTemperature(void)
{
	UINT8_T temp_Value;
	UINT8_T degree_Type = CLEAR;
	UINT8_T sChange = CLEAR;

	DisplayTempMenu();                           // Temperature menu text
        if (BUT_PRESSED())                                // If a button press is pending
        {
          if (RB0_PRESSED())                             // If temperature mode confirmed
          {
            RESET_RB0();                                           // Event has been used
            LCDClear();                          // Clear the screen
            for (;;)                             // Infinite loop
            {
                temp_Value = I2CReadTemp();      // Get the temperature reading
                DisplayTemperature(temp_Value, degree_Type);   // Display current reading
        		if (BUT_PRESSED())                        // If a button press is pending
        		{
                  if (RB0_PRESSED())                              // User chooses to exit
                  {
                    RESET_RB0();                                   // Event has been used
                    nState = ST_TEMPERATURE;     // Move on to temperature mode
                    LCDClear();                  // Wipe display for next mode
                    break;                       // Exit the infinite loop
                  }
				  if (RA4_PRESSED())                              // User chooses to exit
                  {	
                    RESET_RA4();                                   // Event has been used
					if (sChange == ENABLE)
					{	
						sChange = CLEAR;	
						degree_Type = ENABLE;
					}
					else
					{	
						sChange = ENABLE;	
						degree_Type = CLEAR;
					}
                  }                                                          
                }                                
            }                                    
          }                                		 
          else if (RA4_PRESSED())                      // If next mode selected (by user)
          {
                  RESET_RA4();                                     // Event has been used
                  nState = ST_CLOCK;             // Move to clock selection mode
                  LCDClear();                    // Clear LCD for next display
          } 
        }                                        // If button press recorded
                                             	 // Temperature selection mode
}

/******************************************************************************
* Function: void StateClock(void)
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This routine is called each time the user selects the clock
*          			mode (e.g. state). This is the clock states main handler. It first
*           		displays the selection menu text and either goes to displaying current
*           		system time or returns to original state (Voltmeter), depending on the
*           		option the user picks. 
*
* @note        		None.
*/
/*******************************************************************/

void StateClock (void)
{
        DisplayClockMenu();                	// Go show the clock selection screen
        if (BUT_PRESSED())                              	// If a button press is pending
        {
          if (RB0_PRESSED())         	                    // If user confirmed clock mode
          {
            RESET_RB0();                                             // Event has been used
            LCDClear();                    	// Clear the screen

            for (;;)                       	// Infinite loop
            {
              	DisplayTime();               // Display current time hh:mm:ss
        	if (BUT_PRESSED())                              // If a button press is pending
        	{
                if (RB0_PRESSED())                    // If user chose to exit (Menu Option)
                {
                  RESET_RB0();                                        // Event has been used
                  nState = ST_CLOCK;       // Circle back to first menu
                  LCDClear();              // Prepare the display for next mode
                  break;                   // Exit the infinite loop
                }                          

                else if (RA4_PRESSED())      	// If clock setting selected
                {
                            RESET_RA4();                             // Event has been used
					   		StateClock_Set();
							LCDClear();						
                }
             }                                 	
			}                                                 
          }                                     

          else if (RA4_PRESSED())             // User pressed next
		  {
                 RESET_RA4();                                         // Event has been used
                 nState = ST_VOLTMETER;             // Move on to Voltmeter option
				 LCDClear();    					// Prepare the display for next mode
		  } 
        }       
}
/******************************************************************************
* Function: void StateClock_Set(void)
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This routine is called when the user selects to set the time, after entering
*          		 the time display mode (e.g. state). It first waits for the user to specify
*          		 whether the hours or minutes are to be updated. Then calls the related
*          		 time update routine.
*
* @note        		None.
*/
/*******************************************************************/

void StateClock_Set (void)
{
	UINT8_T Val = CLEAR;
	UINT8_T cMenu = CLEAR;
	UINT8_T sChange = CLEAR;

	LCDClear();
	
	for(;;)
	{      
		if (sChange)
		{
			sChange = FALSE;
			return;
		}
		else
		{
		    Set_Time(Val,cMenu);
		}
		
        if (BUT_PRESSED())                        // If a button press is pending
        {
			if (RB0_PRESSED())  	     	// If user selects to set the minutes
            {
                RESET_RB0();                                     // Event has been used
				sChange = TRUE;
				LCDClear();                 // Clear the screen
				StateClock_Min();           // Go set system time minutes
            }                                     
            else if (RA4_PRESSED())                         // If hour setting selected
            {
                RESET_RA4();                                     // Event has been used
				sChange = TRUE;
				LCDClear();                 // Clear the screen
				StateClock_Hrs();			// Go set hours
            }
         }                                 	
	} 
}

/******************************************************************************
* Function: void StateClock_Min(void)
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This routine is called after the user has selected to enter the system
*           		minutes update mode. One button is used to set the time while the other is 
*					used to select between increment/decrement/exit. 
*
* @note        		None.
*/
/*******************************************************************/

void StateClock_Min (void)
{
	UINT8_T Val = 1;
	UINT8_T cMenu = 0;

	LCDClear();
	
	for(;;)
	{      
		Set_Time(Val,cMenu);

        if (BUT_PRESSED())                                     // If a button press is pending
        {
			if (RB0_PRESSED())                          // If user chose to exit (Menu Option)
            {
                RESET_RB0();                                     // Event has been used
				cMenu++;
				if (cMenu == 2)
				{
				  nState = ST_CLOCK;       // Circle back to first menu
                  LCDClear();              // Prepare the display for next modeStateClock
                  break;                   // Exit the infinite loop
				}          
            }                                     
            else if (RA4_PRESSED())                               // If clock setting selected
            {
                RESET_RA4();                                            // Event has been used
				if (cMenu == 0)
            	{	RTCIncMinutes();   }    // Setting the time	
				else if (cMenu == 1)
               {	RTCDecMinutes();   }	// Setting the time			
            }
         }                                 
	} 
}

/******************************************************************************
* Function: void StateClock_Hrs(void)
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This routine is called after the user has selected to enter the system
*           		hours update mode. One button is used to set the time while the other is 
*					used to select between increment/decrement/exit. 
*
* @note        		None.
*/
/*******************************************************************/

void StateClock_Hrs (void)
{
	UINT8_T Val = 2;
	UINT8_T cMenu = 0;

	LCDClear();
	
	for(;;)
	{      
		Set_Time(Val, cMenu);

        if (BUT_PRESSED())                                   // If a button press is pending
        {
			if (RB0_PRESSED())  		               // If user chose to exit (Menu Option)
            {
                RESET_RB0();                                           // Event has been used
				cMenu++;
				if (cMenu == 2)
				{
				  nState = ST_CLOCK;        // Circle back to first menu
                  LCDClear();               // Prepare the display for next mode
                  break;                    // Exit the infinite loop
				}                
            }                                     

            else if (RA4_PRESSED())                              // If clock setting selected
            {
                RESET_RA4();                                           // Event has been used
				if (!cMenu)
				{  	RTCIncHrs();    }        // Setting the time		
				else if (cMenu == 1)
				{  	RTCDecHrs();    }        // Setting the time     		
            }
         }                                 	// If a button press is pending
	} 
}

///////////////////////////////////////////////////////////////////////////////
//*****************************************************************************
// LCD Display FUNCTIONS
//*****************************************************************************
///////////////////////////////////////////////////////////////////////////////

/******************************************************************************
* Function:          DisplaySplashText
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This function is called to just display the splash screen when
*                   the app starts up, then immediately returns to the caller (state
*                   main handler).
*
* @note        		None.
*/
/*******************************************************************/

void DisplaySplashText(void)
{
  	LCDClear();
	MICROCHIP();
}

/******************************************************************************
* Function: void DisplayVoltMenu(void)
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This function is called to only display the Voltmeter selection screen,
*           		then directly returns control to the caller.
*
* @note        		None.
*/
/*******************************************************************/

void DisplayVoltMenu(void)
{
	VOLTMETER();
	BIGMENU();
}

/******************************************************************************
* Function: void DisplayVoltage(void)
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This function is called to display the current voltage on the
*           		potentiometer. It gets the raw A/D reading and converts it into a
*           		real voltage data before displaying it.
*
* @param			Volt	Raw voltage data (from ADC).
*
* @note        		If serial transmission is enabled, this function will output the
*           		the displayed data to the serial communication line regularly.
*/
/*******************************************************************/

void DisplayVoltage(UINT16_T Volt)
{
	UINT16_T ADC_Conversion;
	
	ADC_Conversion = Volt;
	Volt = ((Volt*VOLTAGE_CHANGE)/10)/10;   // Convert to real voltage

		VOLTAGE();                          // Display the voltage

    if (TickOff)                			// Slow serial transmit to allow time for buffer
    {      									// TickOff is set every 16.3 ms => Avoids overflowing the comm buffer
    	TickOff = FALSE;                 	// Permission used
	#ifdef SERIAL_COM 						// The communication option can be de-activated at compile
		SERIALVOLTS();                      // Output voltage to serial
	#endif
	}		   
}

/******************************************************************************
* Function: void DisplayBuzMenu(void)
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This function is called to display the Buzzer selection screen only,
*           		then return to the caller.
*
* @note        		None.
*/
/*******************************************************************/

void DisplayBuzMenu(void)
{
	BUZZER();
	BIGMENU();
}

/******************************************************************************
* Function: void DisplayBuzzerData(void)
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This function is called to display current buzzer settings and activate
*           		the sound on the buzzer. It starts by setting a duty cycle of 46% to be
*           		able to get an audible sound, then waits for a user action: Either they
*           		selects to alter the duty cycle, or exits the buzzer mode.
*
* @param			PWM_Freq  Duty cycle to be set and displayed.
*
* @note        		If the serial transmission is enabled, this function will output the
*           		the displayed data (duty cycle valuer) to the serial communication line
*           		regularly.
*/
/*******************************************************************/

void DisplayBuzzerData(volatile UINT8_T PWM_Freq)
{
	DUTYCYCLE();
	KEYS();
	BUZZMENU();

    if (TickOff)       					// Making sure we wait 16.3 ms between readings
    {
       	TickOff = FALSE;                // Permission used
		#ifdef SERIAL_COM
		SERIALBUZZ();
		SERIAL_KEYS();
		#endif
	}
}

/******************************************************************************
* Function: void DisplayTempMenu(void)
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This function is called to display the temperature selection screen
*           		only, then return to the caller.
*
* @note        		None.
*/
/*******************************************************************/


void DisplayTempMenu(void)
{
	TEMPERATURE();
	BIGMENU();
}

/******************************************************************************
* Function: void DisplayTemperature(unsigned char Thermal)
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This function is called to display current temperature reading from
*           		the probe. It takes the specified raw reading, converts it into a real
*           		displayable ASCII value, and sends it out to the LCD.
*
* @param			Thermal 	Raw reading acquired from the probe (through I2C).
*
* @note        		If the serial transmission is enabled, this function will output the
*           		the displayed data (converted temperature value) to the serial
*           		communication line regularly.
*/
/*******************************************************************/

void DisplayTemperature(UINT8_T Thermal, UINT8_T Type)
{
	volatile UINT8_T negValue;
	static UINT16_T prevTherm;

		if (Thermal >= 128)					// Check to see if Celsius Temperature is Negative
		{ 
			Thermal = 256 - Thermal;
			negValue = ENABLE;
		}
		else
		{
			Thermal = Thermal;
			negValue = DISABLE;
		}

	// Display the Celsius Temperature as a Fahrenheit value
	if (Type == 1)
	{
		if (negValue == DISABLE)
		{	Thermal = (((Thermal*9)/5)+32);	}
		else if (negValue == ENABLE) 
		{	
			if (Thermal < 18)			// Values larger then 18; Fahrenheit goes negative.
			{	
				Thermal = (((Thermal)*9)/5);
				Thermal = 32-Thermal;
				negValue = DISABLE;
			}
			else
			{
				Thermal = ((((Thermal)*9)/5)-32);
				negValue = ENABLE;
			}
		}
	}

		TEMPREADING();

	if (TickOff)       					 // Making sure we wait 16.3 ms between readings
	{
		TickOff = FALSE;                 // Permission used
	#ifdef SERIAL_COM
		SERIALTEMP();
	#endif
	}
}

/******************************************************************************
* Function: void DisplayClockMenu(void)
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This function is called to display the clock selection screen
*           		only, then returns to the caller.
*
* @note        		None.
*/
/*******************************************************************/

void DisplayClockMenu(void)
{
	CLOCK();
	BIGMENU();
}

/******************************************************************************
* Function: void DisplayTime(void)
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This function is called after the user has confirmed the "Clock"
*            		mode to display current system time. The user is offered the
*            		possibility to set the time using the RA4 button.
*
* @note        		If the serial transmission is enabled, this function will output the
*           		the displayed data (actual system time) to the serial
*           		communication line regularly.
*/
/*******************************************************************/

void DisplayTime(void)
{
	SHOWTIME();
	CLOCKSET();

#ifdef SERIAL_COM							// If Data transmission enabled
	SERIALTIME();
#endif
}

/******************************************************************************
* Function: void Set_Time(void)
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @brief	        This function is called after the user has selected to set the system
*           		time. Depending on the the user's choice, it offers either additional
*           		clock setting options, allowing the setting of minutes or hours.
*
* @param			Val 	User selection (minutes/sec, ...)
*
* @param 			cMenu 	Current menu (or level).
*
* @note        		None.
*/
/*******************************************************************/

void Set_Time(UINT8_T Val,UINT8_T cMenu)
{
	if (!Val)
	{
		CLOCKOPT();				// Options menu for clock set
	}
	else if (Val == 1)
	{
		CLOCK_MIN();			// Set minutes on clock
	}
	else if (Val == 2)
	{
		CLOCK_HRS();			// Set hours on clock
	}
}