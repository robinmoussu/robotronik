/********************************************************************
*
*                
*
*********************************************************************
* FileName:        I2c.c
* Dependencies:    See INCLUDES section below
* Processor: 	   PIC18F46K22      
* Compiler: 	   C-18       
* Company:         Microchip Technology, Inc.
*
* Software License Agreement:
*
* The software supplied herewith by Microchip Technology Incorporated
* (the "Company") for its PICmicro� Microcontroller is intended and
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
* File Description: This module includes all the code related to manageing
*                   the TC74 temperature probe. Communication with the
*                   chip are done in I2C.
*
* Change History:
* Author               Date        Comment
* Chris Tucker      10/18/2010  First version of module code
********************************************************************/

/**
*   @file I2c.c
*   @brief This module includes all the code related to manageing
*          the TC74 temperature probe. Communication with the
*          chip are done in I2C.
*   @defgroup I2C	I2C Communication
*   
*/

//*****************************************************************************
// Include and Header files
//*****************************************************************************

#include <p18cxxx.h>
#include <GenericTypeDefs.h>

#include "General.h"
#include "I2c.h"
#include "Lcd.h"
#include "DisplayMacros.h"

//#define TC74_U5   ///< Defines board revision for TC74 communication

/***************************** DEFINE CONSTANTS ************************************/
/*
#ifdef TC74_U5
  #define I2C_ADDR	 0x9A                   ///< I2C Address
#endif

#ifndef TC74_U5
  #define I2C_ADDR	 0x90                   //< I2C Address
#endif
*/
#define TO_MAX			 5000		///< Max count for TimeOut Fault.
// Set to 50 to simulate Fault.

// Common Baud Rates (16MHz & 4 MHz) 
// Fclock is equal to 100kHz in both cases					
#define BAUD100_16MHZ 	 0x27				
#define BAUD100_4MHZ	 0x09					

// SSP1 Configuration
#define SSP1_Config		0b00101000	///< SSP1 configuration
///< No collision detection; No overflow indication; SDA & SCL pins as the source; Clock stretching enabled; I2C Master Mode [BRG = Fclock = Fosc/(4*(SSPADD+1))]

UINT16_T	I2C_Address = 0x90;
#define PASS	1
#define FAIL	0
///////////////////////////////////////////////////////////////////////////////
//*****************************************************************************
// SUPPORT FUNCTIONS
//*****************************************************************************
///////////////////////////////////////////////////////////////////////////////

/********************************************************************
* Function:         I2CInit
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  I2C
*
* @brief    		This routine is meant to be called at start to prepare
*           		the MCU to operate the TC74 temp probe. 
*
* @note     When finished the TC74 is ready to provide probing data.
*/
/*******************************************************************/

void I2CInit(void)
{
    UINT16_T	TO_Counter = CLEAR;

    I2C_CONFIG();                         // Initialize I2C operation
    SSPADD=BAUD100_4MHZ;
    Nop();
    Nop();
    Nop();
/*
  I2C_START();		 		// Initiate & wait for start condition
	Nop();
	Nop();
	Nop();

  SSP1BUFbits.SSP1BUF = (I2C_ADDR + WRITE);	// Issue a write command
  I2C_WRITE_WAIT();                             // Wait until write is completed
*/
    I2CAddressChange();
    Nop();
    Nop();
    Nop();

    SSP1BUFbits.SSP1BUF = READ;			// Specify config register as destination
    I2C_WRITE_WAIT();                             // Wait until write completed

    Nop();
    Nop();
    Nop();

    SSP1BUFbits.SSP1BUF = READ;			// Set chip for continuous read
    I2C_WRITE_WAIT();                             // Write & wait until completed
    Nop();
    Nop();
    Nop();

    I2C_STOP();				        // Go issue a STOP command
    Nop();
    Nop();
    Nop();
}	

/********************************************************************
* Function:         I2CAddressChange
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  I2C
*
* @brief    		This routine is meant to be called to search through
*					all possible TC74 address and find the correct device. 
*
* @note    			This will auto find and store the proper TC74 Address.
*/
/*******************************************************************/

void I2CAddressChange(void)
{
	UINT16_T	TO_Counter = CLEAR;
	UINT16_T	I2C_Check = FAIL;
	volatile UINT16_T	Nothing = 0;

	while (I2C_Check != PASS)
	{
            I2C_START();		 	// Initiate & wait for start condition
            Nop();
            Nop();
            Nop();

            SSP1BUFbits.SSP1BUF = (I2C_Address + WRITE);
            PIR1bits.SSP1IF = CLEAR;
            TO_Counter = 0;
            do
            {
                if (TO_Counter == TO_MAX)
                {	TOFAULT();	}
                TO_Counter++;
            } while(!PIR1bits.SSP1IF);
	    if (SSP1CON2bits.ACKSTAT == CLEAR)				
            {
                    I2C_Check = PASS;
            }
            else
            {
                I2C_Check = FAIL;
                I2C_Address = I2C_Address + 2;
                Nothing = SSP1BUFbits.SSP1BUF;

                if (I2C_Address >= 0xA0)
                {	COMFAULT();	}

                else
                {
                    I2C_STOP();				            // Go issue a STOP command
                    Nop();
                    Nop();
                    Nop();
                }
            }
	}				
}


/********************************************************************
* Function:         I2CReadTemp
* 
* PreCondition: 	None
*
* Side Effects: 	None
*/
/**
* @ingroup  I2C
*
* @brief    		This routine is called to get current temperature reading
*           		from the TC74 on the PICDEM 2 Plus board and return the value
*           		to the caller as 2 BCD nibbles.
*
* @result	  		{Thermal}	*[temp_Value] USED in Main.c
*/
/*******************************************************************/

UINT8_T I2CReadTemp(void)
{
 	UINT8_T 	Thermal;                // Local buffer for temperature
	UINT16_T	TO_Counter = CLEAR;
	
  I2C_START();		 			// Initiate & wait for start condition
	Nop();
	Nop();
	Nop();

  SSP1BUFbits.SSP1BUF = (I2C_Address + WRITE);	// Specify write command
  I2C_WRITE_WAIT();                             // Write & wait until completed
	Nop();
	Nop();
	Nop();

  SSP1BUFbits.SSP1BUF = WRITE;			// Select temperature register
  I2C_WRITE_WAIT();                             // Write & wait until completed
	Nop();
	Nop();
	Nop();

  I2C_RESTART();                                // Restart for read
	Nop();
	Nop();
	Nop();

  SSP1BUFbits.SSP1BUF = (I2C_Address + READ);	// Specify read command
  I2C_WRITE_WAIT();                             // Write & wait until completed
	Nop();
	Nop();
	Nop();

  I2C_READ_WAIT();                          // Wait until data is received
	Nop();
	Nop();
	Nop();

  Thermal = SSP1BUFbits.SSP1BUF;             // Save temperature

  I2C_NACK();                               // NAK last byte
	Nop();
	Nop();
	Nop();

  I2C_STOP();				    // Go issue a stop command
	Nop();
	Nop();
	Nop();

  return(Thermal);                           // Return read temp
}