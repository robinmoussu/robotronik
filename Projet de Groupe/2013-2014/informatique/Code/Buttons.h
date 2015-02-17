/********************************************************************
*
*                
*
*********************************************************************
* FileName: Buttons.h
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
* File Description: This file contains the function prototypes for input
*          switchs used to determine a single or multiple button push.
*
* Change History:
* Author               Date        Comment
* Chris Tucker      10/18/2010   First version of the module (all
*                                  initial code)
********************************************************************/

/**
*   @file Buttons.h
*   @brief This file contains the function prototypes for input
*          switchs used to determine a single or multiple button push.
*   @defgroup Buttons Button Detection
*   
*/

#ifndef _BUTTONS_H
#define _BUTTONS_H

typedef struct
        {
          unsigned char But1Pressed : 1;
          unsigned char But2Pressed : 1;
          unsigned char But3Pressed : 1;
          unsigned char But4Pressed : 1;
          unsigned char But5Pressed : 1;
          unsigned char But6Pressed : 1;
          unsigned char But7Pressed : 1;
          unsigned char But8Pressed : 1;
        } BUTMSK_T; 
 
extern BUTMSK_T Buttons;          // Buffer for up to 8 buttons

#define RA4_PRESSED()  (Buttons.But1Pressed)
#define RB0_PRESSED()  (Buttons.But2Pressed)
#define BOTH_PRESSED() ((Buttons.But1Pressed) && (Buttons.But2Pressed))
#define BUT_PRESSED()  ((Buttons.But1Pressed) || (Buttons.But2Pressed) || \
                        (Buttons.But3Pressed) || (Buttons.But4Pressed) || \
                        (Buttons.But5Pressed) || (Buttons.But6Pressed) || \
                        (Buttons.But7Pressed) || (Buttons.But8Pressed)) 

#define SET_RA4()     Buttons.But1Pressed = 1
#define RESET_RA4()   Buttons.But1Pressed = 0
#define SET_RB0()     Buttons.But2Pressed = 1
#define RESET_RB0()   Buttons.But2Pressed = 0

void CheckButtons(void);					// Routine used to debounce and determine button press.
UINT8_T GetButtons(void);						// Service routine returns which button has been pressed.
void ButtonsInit(void);

#endif