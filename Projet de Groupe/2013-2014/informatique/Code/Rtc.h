/********************************************************************
*
*                
*
*********************************************************************
* FileName:        Rtc.h
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
*   @file Rtc.h
*   @brief This file contains the function prototypes for the Real Time
*		   Clock. Allowing for a change in Hours/Minutes while tracking Secounds.
*   
*/

#ifndef _rtc_H
#define _rtc_H

//*****************************************************************************
// Include and Header files
//*****************************************************************************
#include "Lcd.h"

//*****************************************************************************
// Global Knobs
//*****************************************************************************

/// @brief	Structure used to create a accurate clock.
typedef struct
        {
          UINT8_T  	Sec,                            ///< Buffer for seconds
                	Min,                            ///< Buffer for minutes
                 	Hour,                           ///< Buffer for hours
                 	Day,                            ///< Buffer for day of the month
                 	Month;                          ///< Buffer for month
          UINT16_T 	Year;                           ///< Buffer for the year
        } DATE_TIME;

//*****************************************************************************
// Global Definitions and Equates
//*****************************************************************************

//*****************************************************************************
// Global Variables
//*****************************************************************************

extern DATE_TIME dateTime;                         // Buffer for internal clock
extern BOOL   	timeHasChgd;			           	///< Time update flag

//*****************************************************************************
// Global Constant Strings
//*****************************************************************************

//*****************************************************************************
// Global Variable Strings
//*****************************************************************************

//*****************************************************************************
// Global Function Prototypes
//*****************************************************************************

void RTCInit(void);             ///< Configuration and setup for the clock
void RTCIncDateTime(void);      ///< Increments Date/Time (every second)

void RTCIncMinutes(void);       ///< Adds 1 mn to Date/Time (User time setting)
void RTCDecMinutes(void);		///< Subt 1 mn to Date/Time (User time setting)
void RTCIncHrs(void);			///< Adds 1 hr to Date/Time (User time setting)
void RTCDecHrs(void);			///< Subt 1 hr to Date/Time (User time setting)

void RTC_ISR (void);			///< When Serial Interrupt is detected

#endif
