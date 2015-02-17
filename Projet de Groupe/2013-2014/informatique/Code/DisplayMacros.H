/********************************************************************
*
*                
*
*********************************************************************
* FileName:        DisplayMacros.h
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
* File Description:
*
* Change History:
* Author               Date        Comment
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Chris Tucker      10/18/2010  First version of module code
********************************************************************/

/**
*   @file DisplayMacros.h
*   @brief This file contains the macros created to create the display's
*          used on the LCD for menus and sensor values.
*   
*/

#ifndef _DISPLAYMACROS_H
#define _DISPLAYMACROS_H

#include "General.h"

///////////////////////////////////////////////////////////////////////////////
//*****************************************************************************
// MACROS
//*****************************************************************************
///////////////////////////////////////////////////////////////////////////////

/***************************** MACROS CONSTANTS ************************************/


/***************************** LABEL MACROS ****************************************/

/// @brief	Boot up info screen. [Splash Menu]
#define MICROCHIP()					\
	do								\
	{								\
	LCDWriteStr("   Microchip");	\
	LCDGoto(0,1);					\
	LCDWriteStr(" PICDEM 2 PLUS");	\
	} while(0);	

/// @brief	Voltmeter function select display.
#define	VOLTMETER()   				\
	do								\
	{								\
	LCDGoto(0,0);         			\
	LCDWriteStr("   Voltmeter");	\
	} while(0);		

/// @brief	Buzzer function select display.
#define BUZZER()  					\
	do								\
	{								\
	LCDGoto(0,0);           		\
	LCDWriteStr("     Buzzer");		\
	} while(0);	

/// @brief	Temperature function select display.
#define TEMPERATURE()				\
	do								\
	{								\
	LCDGoto(0,0);     				\
	LCDWriteStr("  Temperature");	\
	} while(0);	

/// @brief	Clock function select display.
#define CLOCK()						\
	do								\
	{								\
	LCDGoto(0,0);					\
	LCDWriteStr("     Clock");		\
	} while(0);	

/***************************** FAULT MACROS ****************************************/

/// @brief	I2C Communication Error. Check Address in I2C.C
#define COMFAULT()					\
	do								\
	{								\
	LCDGoto(0,0);					\
	LCDWriteStr("   Temp Sensor  ");	\
	LCDGoto(0,1);					\
	LCDWriteStr("   Comms Error  ");	\
	} while(1);	

/// @brief	I2C Timout Fault. Increase TO_MAX value in I2C.C
#define TOFAULT()					\
	do								\
	{								\
	LCDGoto(0,0);					\
	LCDWriteStr("   Temp Sensor  ");	\
	LCDGoto(0,1);					\
	LCDWriteStr(" Timeout  Fault ");	\
	} while(1);		

/***************************** VALUE MACROS ****************************************/

/// @brief	Display Voltage and convert Volt value to be displayed on screen.
#define VOLTAGE()						\
	do									\
	{									\
	LCDGoto(0,0);						\
	LCDWriteStr("Volts = ");			\
	LCDPutChar(Volt/100+'0');			\
	LCDPutChar('.');					\
	LCDPutChar((Volt / 10)%10+'0');		\
	LCDPutChar((Volt /1)% 10+'0');		\
	LCDWriteStr(" V   ");				\
	LCDGoto(0,1);						\
	LCDPutChar('[');					\
	LCDPutChar((ADC_Conversion/1000)+'0');		\
	LCDPutChar(((ADC_Conversion/100)%10)+'0');	\
	LCDPutChar(((ADC_Conversion/10)%10)+'0');	\
	LCDPutChar((ADC_Conversion%10)+'0');		\
	LCDWriteStr("] RB0= Exit");					\
	} while(0);	

/// @brief	Display and convert Duty Cycle Period which affects the buzzer audio output.
#define DUTYCYCLE()												\
	do															\
	{															\
	LCDGoto(0,0);												\
	LCDWriteStr("PWM:");										\
	LCDPutChar(((((PWM_Freq/5)-1)*2) / 100) + '0');			\
	LCDPutChar(((((((PWM_Freq/5)-1)*2) /10)/1) % 10) + '0');	\
	LCDPutChar(((((PWM_Freq/5)-1)*2) % 10) + '0');			\
	LCDPutChar('%');											\
	} while(0);	

/// @brief	Look up table for Key based on Frequency change resulting from PWM Period change.
// -PWM:0%		Case 5: 	[Frequency:	10 KHz]			
// -PWM:2%		Case 10: 	[Frequency:	5 KHz]
// -PWM:4%		Case 15: 	[Frequency:	4 KHz] 
// -PWM:6%		Case 20: 	[Frequency:	3 KHz] 
// -PWM:8%		Case 25: 	[Frequency:	2.45 KHz]
// -PWM:10%		Case 30: 	[Frequency:	2 KHz]
// -PWM:12%		Case 35: 	[Frequency:	1.73 KHz] 
// -PWM:14%		Case 40: 	[Frequency:	1.52 KHz] 
// -PWM:16%		Case 45: 	[Frequency:	1.36 KHz]
// -PWM:18%		Case 50: 	[Frequency:	1.23 KHz]
// -PWM:20%		Case 55: 	[Frequency:	1.16 KHz] 
// -PWM:22%		Case 60: 	[Frequency:	1.03 KHz] 
// -PWM:24%		Case 65: 	[Frequency:	950 Hz]
// -PWM:26%		Case 70: 	[Frequency:	880 Hz]
// -PWM:28%		Case 75: 	[Frequency:	823 Hz] 
// -PWM:30%		Case 80: 	[Frequency:	775 Hz] 
// -PWM:32%		Case 85: 	[Frequency:	730 Hz]
// -PWM:34%		Case 90: 	[Frequency:	690 Hz]
// -PWM:36%		Case 95: 	[Frequency:	653 Hz] 
// -PWM:38%		Case 100: 	[Frequency:	620 Hz] 
// -PWM:40%		Case 105: 	[Frequency:	590 Hz]
// -PWM:42%		Case 110: 	[Frequency:	560 Hz]
// -PWM:44%		Case 115: 	[Frequency:	530 Hz] 
// -PWM:46%		Case 120: 	[Frequency:	510 Hz] 
// -PWM:48%		Case 125: 	[Frequency:	495 Hz] 
// -PWM:50%		Case 130: 	[Frequency:	478 Hz] 
// -PWM:52%		Case 135: 	[Frequency:	460 Hz]
// -PWM:54%		Case 140: 	[Frequency:	442 Hz]
// -PWM:56%		Case 145: 	[Frequency:	427 Hz] 
// -PWM:58%		Case 150: 	[Frequency:	414 Hz] 
// -PWM:60%		Case 155: 	[Frequency:	400 Hz] 
// -PWM:62%		Case 160: 	[Frequency:	390 Hz]
// -PWM:64%		Case 165: 	[Frequency:	375 Hz]
// -PWM:66%		Case 170: 	[Frequency:	365 Hz] 
// -PWM:68%		Case 175: 	[Frequency:	355 Hz] 
// -PWM:70%		Case 180: 	[Frequency:	345 Hz]
// -PWM:72%		Case 185: 	[Frequency: 335 Hz] 
// -PWM:74%		Case 190: 	[Frequency:	326 Hz]
// -PWM:76%		Case 195: 	[Frequency:	318 Hz]
// -PWM:78%		Case 200: 	[Frequency:	310 Hz] 
// -PWM:80%		Case 205: 	[Frequency:	300 Hz] 
// -PWM:82%		Case 210: 	[Frequency:	295 Hz] 
// -PWM:84%		Case 215: 	[Frequency:	290 Hz]
// -PWM:86%		Case 220: 	[Frequency:	284 Hz]
// -PWM:88%		Case 225: 	[Frequency:	277 Hz] 
// -PWM:90%		Case 230: 	[Frequency:	270 Hz] 
// -PWM:92%		Case 235: 	[Frequency:	264 Hz]
// -PWM:94%		Case 240: 	[Frequency:	259 Hz]
// -PWM:96%		Case 245: 	[Frequency:	254 Hz] 
// -PWM:98%		Case 250: 	[Frequency: 249 Hz] 
// -PWM:100%	Case 255: 	[Frequency:	245 Hz]

#define KEYS()													\
	do															\
	{															\
	LCDWriteStr(" Key:");										\
	switch (PWM_Freq)											\
	{															\
		case 10: 	LCDWriteStr("D8#");	break;					\
		case 15: 	LCDWriteStr("B7 ");	break;					\
		case 20: 	LCDWriteStr("F7#");	break;					\
		case 25: 	LCDWriteStr("D7#");	break;					\
		case 30: 	LCDWriteStr("C7 ");	break;					\
		case 35: 	LCDWriteStr("A6 ");	break;					\
		case 40: 	LCDWriteStr("G6 ");	break;					\
		case 45: 	LCDWriteStr("F6 ");	break;					\
		case 50: 	LCDWriteStr("D6#");	break;					\
		case 55: 	LCDWriteStr("D6 ");	break;					\
		case 60: 	LCDWriteStr("C6");	break;					\
		case 65: 	LCDWriteStr("A5#");	break;					\
		case 70: 	LCDWriteStr("A5 ");	break;					\
		case 75: 	LCDWriteStr("G5#");	break;					\
		case 80: 	LCDWriteStr("G5 ");	break;					\
		case 85: 	LCDWriteStr("F5#");	break;					\
		case 90: 	LCDWriteStr("F5 ");	break;					\
		case 95: 	LCDWriteStr("E5 ");	break;					\
		case 100: 	LCDWriteStr("D5#");	break;					\
		case 105: 	LCDWriteStr("D5 ");	break;					\
		case 110: 	LCDWriteStr("C5#");	break;					\
		case 115: 	LCDWriteStr("C5 ");	break;					\
		case 125: 	LCDWriteStr("B4 ");	break;					\
		case 135: 	LCDWriteStr("A4#");	break;					\
		case 140: 	LCDWriteStr("A4 ");	break;					\
		case 150: 	LCDWriteStr("G4#");	break;					\
		case 160: 	LCDWriteStr("G4 ");	break;					\
		case 170: 	LCDWriteStr("F4#");	break;					\
		case 180: 	LCDWriteStr("F4 ");	break;					\
		case 190: 	LCDWriteStr("E4 ");	break;					\
		case 200: 	LCDWriteStr("D4#");	break;					\
		case 210: 	LCDWriteStr("D4 ");	break;					\
		case 220: 	LCDWriteStr("C4#");	break;					\
		case 240: 	LCDWriteStr("C4 ");	break;					\
		case 255: 	LCDWriteStr("B3 ");	break;					\
		default: 	LCDWriteStr("---");	break;					\
	}															\
	} while(0);	


/// @brief	Display and convert TC74 temperature reading.
#define TEMPREADING()							\
	do											\
	{											\
	LCDGoto(0,0);								\
	LCDWriteStr("Temp = ");             		\
	if (negValue == ENABLE)							\
	{	LCDPutChar('-');	}					\
	else										\
	{											\
		if (!(Thermal/100))						\
		{ 	LCDPutChar(' ');	}				\
		else									\
		LCDPutChar(Thermal/100+'0'); 			\
	}											\
	LCDPutChar(Thermal/10+'0');					\
	LCDPutChar(Thermal % 10+'0');				\
	LCDPutChar(223);							\
	if (Type == 1)								\
	{	LCDWriteStr("[F]   ");  }           	\
	else if (!Type)								\
	{	LCDWriteStr("[C]   ");  }           	\
	LCDGoto(0,1);								\
	if (Type == 1)									\
	{	LCDWriteStr("RA4=[C] RB0=Exit");  }     \
	else if (!Type)							\
	{	LCDWriteStr("RA4=[F] RB0=Exit");  }     \
	} while(0);	
// Character [223] creates the degree symbol

/// @brief	Display the RTC time value.					  
#define SHOWTIME()				\
	do							\
	{							\
	LCDGoto(0,0);				\
	LCDWriteStr("TIME  ");		\
	LCDPutByte(dateTime.Hour);	\
	LCDPutChar(':');			\
	LCDPutByte(dateTime.Min);	\
	LCDPutChar(':');			\
	LCDPutByte(dateTime.Sec);	\
	} while(0);	

/// @brief	Display the RTC time value available for value change.
#define SHOWTIME_SET()			\
	do							\
	{							\
	LCDGoto(0,0);	  			\
	LCDPutByte(dateTime.Hour);	\
	LCDPutChar(':');	  		\
	LCDPutByte(dateTime.Min);	\
	LCDPutChar(':');	 		\
	LCDPutByte(dateTime.Sec);	\
	LCDPutChar(' ');	 		\
	LCDPutChar(' ');			\
	} while(0);	

/***************************** MENU MACROS *****************************************/

/// @brief	Display menu select options.
#define BIGMENU()						\
	do									\
	{									\
	LCDGoto(0,1);						\
	LCDWriteStr("RA4=Next RB0=Now");	\
	} while(0);	

/// @brief	Display exit menu options.
#define SMALLMENU()						\
	do									\
	{									\
	LCDGoto(0,1);						\
	LCDWriteStr("      RB0 = Exit");	\
	} while(0);	

/// @brief	Display Duty Cycle menu options.
#define BUZZMENU()	  					\
	do									\
	{									\
	LCDGoto(0,1);						\
  	LCDWriteStr("RA4=+2% RB0=Exit");	\
	} while(0);	

/// @brief	Display Clock setting options.
#define CLOCKSET()						\
	do									\
	{									\
	LCDGoto(0,1);						\
	LCDWriteStr("RA4=Set RB0=Menu");	\
	} while(0);			

/// @brief	Display Clock_Set select options.
#define CLOCKOPT()				\
	do							\
	{							\
	LCDGoto(0,0);				\
	LCDWriteStr("RA:[HR] ");	\
	LCDPutByte(dateTime.Hour);	\
	LCDPutChar(':');			\
	LCDPutByte(dateTime.Min);	\
	LCDPutChar(':');			\
	LCDPutByte(dateTime.Sec);	\
	LCDGoto(0,1);				\
	LCDWriteStr("RB:[MIN]  TIME ");	\
	} while(0);		

/// @brief	Display Hour setting options.
#define	CLOCK_HRS()				\
	do							\
	{							\
	LCDGoto(0,0);				\
	LCDPutByte(dateTime.Hour);	\
	LCDPutChar(':');			\
	LCDPutByte(dateTime.Min);	\
	LCDPutChar(':');			\
	LCDPutByte(dateTime.Sec);	\
	LCDWriteStr("  *[HRS]");	\
	LCDGoto(0,1);				\
	LCDWriteStr("RA:");			\
	if (cMenu == 0)				\
	{							\
		LCDPutChar('+');		\
		LCDPutChar('+');		\
	}							\
	else if (cMenu == 1)		\
	{							\
		LCDPutChar('-');		\
		LCDPutChar('-');		\
	}							\
	LCDWriteStr("    RB:Next");	\
	} while(0);	

/// @brief	Display Minute setting options.
#define	CLOCK_MIN()				\
	do							\
	{							\
	LCDGoto(0,0);				\
	LCDPutByte(dateTime.Hour);	\
	LCDPutChar(':');			\
	LCDPutByte(dateTime.Min);	\
	LCDPutChar(':');			\
	LCDPutByte(dateTime.Sec);	\
	LCDWriteStr("  *[MIN]");	\
	LCDGoto(0,1);				\
	LCDWriteStr("RA:");			\
	if (cMenu == 0)				\
	{							\
		LCDPutChar('+');		\
		LCDPutChar('+');		\
	}							\
	else if (cMenu == 1)		\
	{							\
		LCDPutChar('-');		\
		LCDPutChar('-');		\
	}							\
	LCDWriteStr("    RB:Next");	\
	} while(0);	


/***************************** SERIAL MACROS **********************************/

/// @brief	Send Voltage info over serial RS232 connector.
#define SERIALVOLTS()				\
	do								\
	{								\
	SERTxSave('\r');                \
	SERTxSave('\n');                \
	SERSendStr("Volts = ");			\
	SERTxSave(Volt/100+'0');	    \
	SERTxSave('.');					\
	SERTxSave((Volt / 10)%10+'0');	\
	SERTxSave((Volt /1)% 10+'0');	\
	SERSendStr(" V    ADC Count:");				\
	SERTxSave('[');								\
	SERTxSave((ADC_Conversion/1000)+'0');		\
	SERTxSave(((ADC_Conversion/100)%10)+'0');	\
	SERTxSave(((ADC_Conversion/10)%10)+'0');	\
	SERTxSave((ADC_Conversion%10)+'0');			\
	SERTxSave(']');								\
	} while(0);		
// Carriage return
// Line Feed

/// @brief	Send Buzzer info over serial RS232 connector.
#define SERIALBUZZ()											\
	do															\
	{															\
	SERTxSave('\r');                								\
	SERTxSave('\n');                								\
	SERSendStr("PWM: ");									\
	SERTxSave(((((PWM_Freq/5)-1)*2) / 100) + '0');			\
	SERTxSave(((((((PWM_Freq/5)-1)*2) /10)/1) % 10) + '0');	\
	SERTxSave(((((PWM_Freq/5)-1)*2) % 10) + '0');				\
	SERSendStr("%");											\
	} while(0);	
// Carriage return
// Line Feed

/// @brief See KEYS()
#define SERIAL_KEYS()											\
	do															\
	{															\
	SERSendStr("          Key:");								\
	switch (PWM_Freq)											\
	{															\
		case 10: 	SERSendStr("D8#");	break;					\
		case 15: 	SERSendStr("B7 ");	break;					\
		case 20: 	SERSendStr("F7#");	break;					\
		case 25: 	SERSendStr("D7#");	break;					\
		case 30: 	SERSendStr("C7 ");	break;					\
		case 35: 	SERSendStr("A6 ");	break;					\
		case 40: 	SERSendStr("G6 ");	break;					\
		case 45: 	SERSendStr("F6 ");	break;					\
		case 50: 	SERSendStr("D6#");	break;					\
		case 55: 	SERSendStr("D6 ");	break;					\
		case 60: 	SERSendStr("C6");	break;					\
		case 65: 	SERSendStr("A5#");	break;					\
		case 70: 	SERSendStr("A5 ");	break;					\
		case 75: 	SERSendStr("G5#");	break;					\
		case 80: 	SERSendStr("G5 ");	break;					\
		case 85: 	SERSendStr("F5#");	break;					\
		case 90: 	SERSendStr("F5 ");	break;					\
		case 95: 	SERSendStr("E5 ");	break;					\
		case 100: 	SERSendStr("D5#");	break;					\
		case 105: 	SERSendStr("D5 ");	break;					\
		case 110: 	SERSendStr("C5#");	break;					\
		case 115: 	SERSendStr("C5 ");	break;					\
		case 125: 	SERSendStr("B4 ");	break;					\
		case 135: 	SERSendStr("A4#");	break;					\
		case 140: 	SERSendStr("A4 ");	break;					\
		case 150: 	SERSendStr("G4#");	break;					\
		case 160: 	SERSendStr("G4 ");	break;					\
		case 170: 	SERSendStr("F4#");	break;					\
		case 180: 	SERSendStr("F4 ");	break;					\
		case 190: 	SERSendStr("E4 ");	break;					\
		case 200: 	SERSendStr("D4#");	break;					\
		case 210: 	SERSendStr("D4 ");	break;					\
		case 220: 	SERSendStr("C4#");	break;					\
		case 240: 	SERSendStr("C4 ");	break;					\
		case 255: 	SERSendStr("B3 ");	break;					\
		default: 	SERSendStr("---");	break;					\
	}															\
	} while(0);	

/// @brief	Send TC74 Temperature info over serial RS232 connector.
#define SERIALTEMP()					\
	do									\
	{									\
	SERTxSave('\n');      				\
	SERTxSave('\r');                    \
	SERSendStr("Temp = ");            	\
	if (negValue == ENABLE)				\
	{	SERTxSave('-');	}				\
	else								\
	{									\
		if (!(Thermal/100))				\
		{ 	SERTxSave(' ');	}			\
		else							\
			SERTxSave(Thermal/100+'0');	\
	}									\
	SERTxSave(Thermal/10+'0');      	\
	SERTxSave(Thermal % 10+'0');    	\
	SERTxSave(248);                   	\
	if (Type == 1)						\
	{	SERSendStr("[F]   ");  }        \
	else if (!Type)						\
	{	SERSendStr("[C]   ");  }        \
	} while(0);	   
/// @brief	Send Clock info over serial RS232 connector.
				 
#define	SERIALTIME()	  					\
	do										\
	{										\
	if (timeHasChgd == TRUE)				\
	{										\
		SERTxSave('\r');                      \
		SERTxSave('\n');                      \
		SERSendStr("System Time : ");		\
		SERTxSave(dateTime.Hour/10+'0');	\
		SERTxSave(dateTime.Hour % 10+'0');	\
		SERTxSave(':');						\
		SERTxSave(dateTime.Min/10+'0');		\
		SERTxSave(dateTime.Min % 10+'0');	\
		SERTxSave(':');						\
		SERTxSave(dateTime.Sec/10+'0');		\
		SERTxSave(dateTime.Sec % 10+'0');	\
		timeHasChgd = FALSE;				\
	}  										\
	} while(0);		



#endif