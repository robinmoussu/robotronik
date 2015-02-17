/********************************************************************
*
*                
*
*********************************************************************
* FileName: Buttons.c
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
* File Description: This module contains all the code related to a button 
*                   press management on the PicDem 2 Plus demo board.
*
* Change History:
* Author               Date        Comment
* Chris Tucker       10/18/2010   First version of the module (all
*                                  initial code)
********************************************************************/

/**
*   @file Buttons.c
*   @brief This module contains all the code related to a button 
*          press management on the PicDem 2 Plus demo board.
*   @defgroup Buttons	Button Detection
*   
*/

#include <p18cxxx.h>
#include "General.h"
#include "Buttons.h"

#define DEB_TIMEOUT  2                    ///< Debounce value (# of Timer0 ticks)

#define RA4_BUTTON	 PORTAbits.RA4		
#define RB0_BUTTON	 PORTBbits.RB0

BUTMSK_T TempButtons;        // Temporary Buffer (just local) For up to 8 buttons
BUTMSK_T Buttons;          // Buffer for up to 8 buttons

#define RA4_ARMED()   (TempButtons.But1Pressed == 1)
#define RB0_ARMED()   (TempButtons.But2Pressed == 1)

#define ARM_RA4()     TempButtons.But1Pressed = 1
#define NEUT_RA4()    TempButtons.But1Pressed = 0
#define ARM_RB0()     TempButtons.But2Pressed = 1
#define NEUT_RB0()    TempButtons.But2Pressed = 0

UINT8_T debCnt1 = 0,                      ///< Debounce counter for button 1
      	debCnt2 = 0;                      ///< Debounce counter for button 2

///////////////////////////////////////////////////////////////////////////////
//*****************************************************************************
// SUPPORT FUNCTIONS
//*****************************************************************************
///////////////////////////////////////////////////////////////////////////////

/********************************************************************
* Function:         ButtonsInit
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		Buttons
*
* @brief    		This function is called to initialize the button management
*                   environment, for proper operation. It mainly resets the buton
*                   state flags, so they start n the released mode.
*
* @note    			This routine should be called only once at start up.
*/
/*******************************************************************/

void ButtonsInit(void)
{
  Buttons.But1Pressed = Buttons.But2Pressed = Buttons.But3Pressed = Buttons.But4Pressed =
  Buttons.But5Pressed = Buttons.But6Pressed = Buttons.But7Pressed = Buttons.But8Pressed =
  TempButtons.But1Pressed = TempButtons.But2Pressed = TempButtons.But3Pressed =
  TempButtons.But4Pressed = TempButtons.But5Pressed = TempButtons.But6Pressed =
  TempButtons.But7Pressed = TempButtons.But8Pressed = 0;         ///< Initialize all Buttons
}

/********************************************************************
* Function:        CheckButtons
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  	   Buttons
*
* @brief           This function monitors RB0 and RA4 buttons on the PicDem 2
*                  Plus board. It starts a debounce period (filtering
*                  mechanical bounces) before validating a button press. Key
*                  presses are memorized in the mskKey global variable. 
*
* @note            This routine is meant to be called on a regular basis. In
*                  this application, it is called when Timer0 interrupt (TMR0IF) 
*                  occurs (every 4.xx ms)
*/
/*******************************************************************/

void CheckButtons(void)
{
  if (!RA4_BUTTON)                               // If button 1 (RA4) is pressed
  {
    if (debCnt1)                                        // If already debouncing
    {
      if (!--debCnt1)                                     // If time out elapsed
      {
        SET_RA4();              // Set the mask for button 1 (RA4) (Valid press)
        NEUT_RA4();                    // Neutralize temporary mask for button 1
      }                            
    }                              
    else                                // Not yet debouncing => first detection
    {
      debCnt1 = DEB_TIMEOUT;                        // Initialize debounce count
      ARM_RA4();                                 // Save temporary state for RA4
    }                               
  }                                 
  else                                             // Button 1 (RA4) is released
  {
    debCnt1 = 0;                                      // Reset debounce time out
    NEUT_RA4();                        // Neutralize temporary mask for button 1
  }                                 

  if (!RB0_BUTTON)                               // If button 2 (RB0) is pressed
  {
    if (debCnt2)                                        // If already debouncing
    {
      if (!--debCnt2)                                   // If debounce time's up
      {
        SET_RB0();             // Set the mask for buttone 2 (RB0) (Valid press)
        NEUT_RB0();              // Neutralize temporary mask for button 2 (RB0)  
      }                                               
    }                                                  
    else                                 // Not yet debouncing => first detection
    {
      debCnt2 = DEB_TIMEOUT;                         // Initialize debounce count
      ARM_RB0();                               // Arm The temporary key detection
    }                                                 
  }                                                        
  else                                              // Button 2 (RB0) is released
  {
    debCnt2 = 0;                                       // Reset debounce time out
    NEUT_RB0();                        // Clear temporary mask for button 2 (RB0)
  }                                                         
}

/********************************************************************
* Function:         GetButtons
* 
* PreCondition: 	None
*
* Input:        	None
*
* Output:     		All pressed buttons since last button read.
*
* Side Effects: 	None
*/
/**
* @ingroup  	   Buttons
*
* @brief	        This function returns to the caller what buttons have been
*                   pressed.
*
* @result			{Res}	*[Butn] USED in Main.c
*
* @note        		This function is capable of returning a button press from 
*                   RA4 or RB0 or both depending on the buttons pressed.
*******************************************************************/

UINT8_T GetButtons(void)
{
                          // Read all buttons
  UINT8_T Res = (7 << Buttons.But8Pressed) | (6 << Buttons.But7Pressed) |
                (5 << Buttons.But6Pressed) | (4 << Buttons.But5Pressed) |
                (3 << Buttons.But4Pressed) | (2 << Buttons.But3Pressed) |
                (1 << Buttons.But2Pressed) | (0 << Buttons.But1Pressed);
  return(Res);                         // Return memorized keys 
}
