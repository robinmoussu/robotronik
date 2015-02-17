/********************************************************************
*
*                
*
*********************************************************************
* FileName:        Voltmeter.c
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
* File Description: This module contains the functions used to activate the 
*			ADC and monitor the POT input as an analog signal. The input 
*			voltage is then displayed on the LCD.
*
* Change History:
* Author               Date        Comment
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Chris Tucker      10/18/2010  First version of module code
********************************************************************/

//*****************************************************************************
// Include and Header files
//*****************************************************************************

/**
*   @file Voltmeter.c
*   @brief 	This module contains the functions used to activate the 
*			ADC and monitor the POT input as an analog signal. The input 
*			voltage is then displayed on the LCD.
*   @defgroup Voltmeter		Voltage 
*   
*/

//*****************************************************************************
// Include and Header files
//*****************************************************************************

#include <p18cxxx.h>
#include <GenericTypeDefs.h>

#include "General.h"

//*****************************************************************************
// Global Constant Strings
//*****************************************************************************

//*****************************************************************************
// Global Variable Strings
//*****************************************************************************

//*****************************************************************************
//Local Function Prototypes
//*****************************************************************************

///////////////////////////////////////////////////////////////////////////////
//*****************************************************************************
// SUPPORT FUNCTIONS
//*****************************************************************************
///////////////////////////////////////////////////////////////////////////////

/********************************************************************
* Function:         VOLTInit
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  		Voltmeter
*
* @brief    		This routine is called to initialize the ADC module, I/Os
*                   to get voltage readings from the potentiometer on the
*                   PicDem 2 Plus board.
*
* @note    			Designed to be called once at start up.
*/
/*******************************************************************/

void VOLTInit(void)
{
	//Configure the ADC module:
	//Select ADC conversion clock Frc

	ADCON2bits.ADCS0 = SET;
	ADCON2bits.ADCS1 = SET;
	ADCON2bits.ADCS2 = SET;

	//Configure voltage reference using VDD

	ADCON1bits.PVCFG0 = CLEAR;
	ADCON1bits.PVCFG1 = CLEAR;

	//Select ADC input channel

	ADCON0bits.CHS0 = CLEAR;
	ADCON0bits.CHS1 = CLEAR;
	ADCON0bits.CHS2 = CLEAR;
	ADCON0bits.CHS3 = CLEAR;

	//Select result format right justified

	ADCON2bits.ADFM = SET;

	//Turn on ADC module

	ADCON0bits.ADON = ENABLE;
}

/********************************************************************
* Function:        VOLTGetV
* 
* PreCondition: 	None
*
* Input:        	None
*
* Output:     		Latest voltage reading on the potentiometer
*
* Side Effects: 	None
*/
/**
* @ingroup  		Voltmeter
*
* @brief    		Obtains all off-chip inputs. It performs an acquisition
*                   of the voltage on the potentiometer connected to pin 13.
*
* @note    			None
*/
/*******************************************************************/

UINT16_T VOLTGetV(void)
{
	Nop();
	Nop();
	Nop();
  ADCON0bits.GO_NOT_DONE = ENABLE;      //Start conversion by setting the GO/DONE bit
  while(ADCON0bits.GO_NOT_DONE) 		// Wait For Conversion to complete (0 = Completed, 1 = In progress
	{	;	}

	return (ADRESH << 8) | ADRESL;		// Return the new value
										// Make sure to go to Project --> Build Options --> Project
										// --> MPLABC18 --> (Click the box for): Enable Integer Promotions
}
