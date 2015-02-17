/********************************************************************
*
*                
*
*********************************************************************
* FileName:        I2c.h
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
* File Description: This file contains the function prototypes for I2C
*          communication with the TC74 device.
*
* Change History:
* Author               Date        Comment
* Chris Tucker      10/18/2010  First version of module code
********************************************************************/

/**
*   @file I2c.h
*   @brief This file contains the function prototypes for I2C
*          communication with the TC74 device.
*   
*/

#ifndef _I2C_H
#define _I2C_H

/***************************** LOCAL MACROS ****************************************/

///	@brief	Configure I2C communication 
#define I2C_CONFIG()					\
	do									\
	{									\
	SSP1CON1=SSP1_Config;           	\
	Nop();					       	 	\
	SSP1STATbits.SMP=1;             	\
	SSP1CON3bits.SCIE = SET;          	\
	SSP1CON3bits.PCIE = SET;			\
	PIR1bits.SSP1IF = CLEAR;  			\
	} while(0); 			 	
// Configure SSP1CON1 Reg
// Wait a cycle
// Slew rate Standard (100kHz & 1 MHz)
// Set Baud Rate
// Enable Interrupt on Start/Restart bits
// Enable Interupt on Stop Bit	
// Clear Interrupt Flag

///	@brief	Send an I2C start command
#define I2C_START()		 				\
	do									\
	{									\
	PIR1bits.SSP1IF = CLEAR;			\
	SSP1CON2bits.SEN = SET;      		\
    	do								\
		{								\
			if (TO_Counter == TO_MAX)	\
			{	TOFAULT();	}			\
			TO_Counter++;				\
		} while(!PIR1bits.SSP1IF);		\
  	TO_Counter = 0;						\
	} while(0);		
// Clear Interrupt Flag
// Send Start Bit
// Wait for Interrupt Flag

///	@brief	Send an I2C restart command
#define I2C_RESTART()				\
	do								\
	{								\
	PIR1bits.SSP1IF = CLEAR;		\
	SSP1CON2bits.RSEN=SET;       	\
    	do								\
		{								\
			if (TO_Counter == TO_MAX)	\
			{	TOFAULT();	}			\
			TO_Counter++;				\
		} while(!PIR1bits.SSP1IF);		\
  	TO_Counter = 0;						\
	} while(0);
// Clear Interrupt Flag
// Send ReStart Bit
// Wait for Interrupt Flag		

///	@brief	Send an I2C stop command
#define I2C_STOP() 		 			\
	do								\
	{								\
	PIR1bits.SSP1IF = CLEAR;		\
	SSP1CON2bits.PEN=SET;      		\
    	do								\
		{								\
			if (TO_Counter == TO_MAX)	\
			{	TOFAULT();	}			\
			TO_Counter++;				\
		} while(!PIR1bits.SSP1IF);		\
  	TO_Counter = 0;						\
	} while(0);	
// Clear Interrupt Flag
// Send Stop Bit
// Wait for Interrupt Flag

///	@brief	Wait for I2C write command to complete
#define I2C_WRITE_WAIT()				\
	do									\
	{									\
	PIR1bits.SSP1IF = CLEAR;  			\
  	TO_Counter = 0;						\
    	do								\
		{								\
			if (TO_Counter == TO_MAX)	\
			{	TOFAULT();	}			\
			TO_Counter++;				\
		} while(!PIR1bits.SSP1IF);		\
	if (SSP1CON2bits.ACKSTAT != CLEAR)	\
	{	COMFAULT();	}					\
	} while(0);	
// Clear Interrupt Flag
// Wait for Transmit to finish
// Wait for ACK to be received
// Wait for Interrupt Flag

///	@brief	Wait for I2C read command to complete 
#define I2C_READ_WAIT()					\
	do									\
	{									\
	PIR1bits.SSP1IF = CLEAR;			\
	SSP1CON2bits.RCEN=SET;          	\
    	do								\
		{								\
			if (TO_Counter == TO_MAX)	\
			{	TOFAULT();	}			\
			TO_Counter++;				\
		} while(!PIR1bits.SSP1IF);		\
  	TO_Counter = 0;						\
	} while(0);	 	
// Clear Interrupt Flag
// Send Receive Bit
// Wait for Interrupt Flag

///	@brief	Send an I2C NACK command
#define I2C_NACK()						\
	do									\
	{									\
	PIR1bits.SSP1IF = CLEAR;			\
	SSP1CON2bits.ACKDT=SET;           	\
	SSP1CON2bits.ACKEN=SET;           	\
    	do								\
		{								\
			if (TO_Counter == TO_MAX)	\
			{	TOFAULT();	}			\
			TO_Counter++;				\
		} while(!PIR1bits.SSP1IF);		\
  	TO_Counter = 0;						\
	} while(0);	 
// Clear Interrupt Flag
// ACK end of Receive sequence
// Transmit ACKDT data bit.
// Wait for Interrupt Flag

/***************************** FUNCTION PROTOTYPES**************************************/

void I2CInit(void);              ///< Hardware initialization routine
void I2C_ISR (void);			 ///< When Serial Interrupt is detected
UINT8_T I2CReadTemp(void);       ///< Temperature reading service routine

void I2CAddressChange(void);

#endif
