/********************************************************************
*
*                
*
*********************************************************************
* FileName:        Rtc.c
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
*********************************************************************
* File Description: This module includes services to create the Real
*                   Time Clock and managing system for time.
*
* Change History:
* Author               Date        Comment
* Chris Tucker      10/18/2010  First version of module code
********************************************************************/

/**
*   @file Rtc.c
*   @brief 	This module includes services to create the Real
*           Time Clock and managing system for time.
*   @defgroup RTC Real Time Clock
*   
*/

//*****************************************************************************
// Include and Header files
//*****************************************************************************

#include "Lcd.h"
#include "rtc.h"
#include "General.h"
#include "Serial.h"

#include <p18cxxx.h>
#include <GenericTypeDefs.h>

//*****************************************************************************
// Definitions and Equates
//*****************************************************************************
   
#define One_Sec  0x80 	///< Pre-Load TMR1H to create a 1 secound counter.

// Timer 1 clock source is crystal oscillator on T1OS1/T1OS0, 1:1, 
// Dedicated enabled, Do Not Synch, Enable Timer1
#define Timer1  0x89	///< Timer 1 Preload
 
//*****************************************************************************
// Global Constant Strings
//*****************************************************************************

//*****************************************************************************
// Global Variable Strings
//*****************************************************************************

DATE_TIME dateTime;                             ///< Buffer for internal clock
BOOL   	timeHasChgd = FALSE;			           	///< Time update flag

#define Max_Sec		60	///< Max Sec in a Minute
#define Max_Min		60	///< Max Min in a Hr
#define Max_Hr		24	///< Max Hr in a Day
#define Roll_Back  255	///< If decrement goes below 0

///////////////////////////////////////////////////////////////////////////////
//*****************************************************************************
// INTRRUPT
//*****************************************************************************
///////////////////////////////////////////////////////////////////////////////

/********************************************************************
* Function:         Serial_ISR
* 
* PreCondition: 	None
*
* Side Effects: 	None                                            
*/
/**
* @brief	        This function is called within the Interrupt Service
*					routine in main.c. All Real time Clock related Interrupts are 
*					stored here and called from the main ISR.
*
* @note        		THIS ROUTINE IS ONLY CALLED BY THE HARDWARE. ITS
*                   EXECUTION SHOULD REMAIN AS QUICK AS POSSIBLE.
*/
/*******************************************************************/

void RTC_ISR (void)
{

/******************************* RTC EVENT EVERY SECOND ***********************/

  if (PIR1bits.TMR1IF)                     	// If RTC Interrupt
  {
    TMR1H  |= One_Sec;                     	// Re-arm the Timer of another second
    RTCIncDateTime();                      	// Count a new second
	timeHasChgd	= TRUE;				   		// Update Time
    PIR1bits.TMR1IF = CLEAR;                // Timer 1 Flag is clears
	INTCONbits.INT0IF = CLEAR;				// Interrupt Flag is cleared
  }                                        	// If RTC interrupt
}

///////////////////////////////////////////////////////////////////////////////
//*****************************************************************************
// SUPPORT FUNCTIONS
//*****************************************************************************
///////////////////////////////////////////////////////////////////////////////

/******************************************************************************
* Function: void RTCInit (void)
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		RTC
*
* @brief    		This function configures and initializes the real time clock
*
* @note    			None.
*/
/*******************************************************************/

void RTCInit(void)
{
	TMR1H  = One_Sec;                           // Load timer to count 1s
	TMR1L  = CLEAR;

/******************************************************************************
 *                           TIMER1 CONFIGURATION                             *
 ******************************************************************************
 * 10xx1xxx = 101 => External oscillator clock 32.768 KHz                     *
 * xx00xxxx => 1:1 Prescale no division                                       *
 * xxxxxxx1 => Enable timer 1                                                 *
 ******************************************************************************/

	T1CON  = Timer1;							// Configure Timer 1 
	T1GCON = DISABLE;                       // Timer 1 Gate function disabled
	PIR1bits.TMR1IF = CLEAR;                // Clear any pending Timer 1 Interrupt indication
	PIE1bits.TMR1IE = ENABLE;               // Enable Timer 1 Interrupt

	dateTime.Hour  = CLEAR;
	dateTime.Min   = CLEAR;
	dateTime.Sec   = CLEAR;
}	
	
/********************************************************************
* Function:         RTCIncDateTime
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		RTC
*
* @brief    		This function is called every second to increment the
*                   system date/time.
* 
* @note    			Time is handled in 24 hours format. 
*/
/*******************************************************************/

void RTCIncDateTime(void)
{
  if (++dateTime.Sec == Max_Sec)   		// Count 1 more second and Check if 1 more minute
  {
    dateTime.Sec = CLEAR;              	// Reset Seconds
    if (++dateTime.Min == Max_Min)  	// Count 1 more minute & check If 1 more hour
    {
      dateTime.Min = CLEAR;            	// Reset Minutes
      if (++dateTime.Hour == Max_Hr)	// Count one more hour and check if day change
      {
        dateTime.Hour = CLEAR;         	// Reset Hours
      }                                 
    }                                   
  }                                     
}

/********************************************************************
* Function:         RTCIncMinutes
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		RTC
*
* @brief    		This funciton is called from within the Clock_Set menu
*					allowing the user to adjust minutes. This function will 
*					increment the clock.
*
* @note    			None.
*/
/*******************************************************************/

void RTCIncMinutes(void)
{
  dateTime.Sec = CLEAR;           	// If time is set, restart seconds
  if (++dateTime.Min == Max_Min)    // Increment minutes & check if an hour elapsed
  {
    dateTime.Min = CLEAR;           // Reset minutes, hour has elapsed
    if (++dateTime.Hour == Max_Hr)  // Increment hour if needed, check for day change
	{
	  	dateTime.Hour = CLEAR;      // Reset hours if day has changed
	}
  }                               
}

/********************************************************************
* Function:         RTCDecMinutes
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		RTC
*
* @brief    		This funciton is called from within the Clock_Set menu
*					allowing the user to adjust minutes. This function will 
*					decrement the clock.
* 
* @note    			None.
*/
/*******************************************************************/

void RTCDecMinutes(void)
{
  dateTime.Sec = CLEAR;                       // If time is set, restart seconds
  if (--dateTime.Min == Roll_Back)            // Decrement minutes & check if an hour elapsed
  {
    dateTime.Min = (Max_Min - 1);             // Reset minutes, hour has elapsed
    if (--dateTime.Hour == Roll_Back)         // Decrement hour if needed, check for day change
	{
	  	dateTime.Hour = (Max_Hr - 1);         // Reset hours if day has changed
	}
  }                                     
}

/********************************************************************
* Function:         RTCIncHours
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		RTC
*
* @brief    		This funciton is called from within the Clock_Set menu
*					allowing the user to adjust hours. This function will 
*					increment the clock.
*
* @note    			None.
*/
/*******************************************************************/

void RTCIncHrs(void)
{
  dateTime.Sec = CLEAR;                     // If time is set, restart seconds
  if (++dateTime.Hour == Max_Hr)            // Increment hours & check if an day elapsed
  {
    dateTime.Hour = CLEAR;                  // Reset hours if day has changed
  }                                     
}

/********************************************************************
* Function:         RTCDecHours
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		RTC
*
* @brief    		This funciton is called from within the Clock_Set menu
*					allowing the user to adjust hours. This function will 
*					decrement the clock.
*
* @note    			None.
*/
/*******************************************************************/

void RTCDecHrs(void)
{
  dateTime.Sec = CLEAR;                  // If time is set, restart seconds
  if (--dateTime.Hour == Roll_Back)      // Decrement hours & check if an day elapsed
  {
    dateTime.Hour = (Max_Hr - 1);        // Reset hours if day has changed
  }    
}