/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <device.h>
#include "machine.h"
#include "function.h"
int8 couleur_depart = 1;

void main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
	//PWM_ServoAr_Start();
	//PWM_ServoAv_Start();
	UART_XBee_Start();
	isr_UART_XBee_Rx_Start();
	UART_Asser_Start();
	isr_UART_Asser_Rx_Start();
	
	//isr_Pion_Start();

	CyDelay(3000);
	CYGlobalIntEnable;

	
	/* ------ */
	while(1)
	{
		write_assert(12, 400);
		CyDelay(2000);
		write_assert(12, -400);
		CyDelay(2000);
	}
	//write_assert(14, 400);
	//CyDelay(2000);
	//write_assert(15, 0);
	
	//int data = 12;
	//read_assert(12, &data);
	//printf("PSOC read ok : %d\n", data);
	while(1);


	
	printf("\n\nRobotronik 2011 - DeepRed - Debug\n\n");
	
	Control_Led_Debug_Write(3); // Clignotement 5 Hz
	pieceAvant();
	for(;;) {
		
		if(!Status_Depart_Read())
		{
			Timer_85s_Start();
			isr_Fin_Start();
			Control_Led_Debug_Write(2); // Clignotement 1 Hz
			
			if (Pin_Couleur1_Read()) {
				UART_XBee_PutString("Depart du match en rouge...\n");
				couleur_depart = -1;
			} else {
				UART_XBee_PutString("Depart du match en bleu...\n");
				couleur_depart = 1;
			}
			
			machine();
			/*while(1){
			avancer(35);
			tourner(180);
			}
			//libererPinceAvant();
			*/			//avancer(12.25+40+5+35);
			//while (1)
			//tourner(-45);
			//avancer(35);
			/*if(pieceAvant()){
			fermerPinceAvant();
			tourner(60) // vers la gauche
			avancer(20)
			libererPinceAvant();
			avancer(-20);
			}
			else{
			avancer(35);
			if(pieceAvant()){
			fermerPinceAvant();
			touner(-60);
			avancer(20);
			libererPinceAvant();
			avancer(-20);
			}
			else*/
			
			
			while(!Status_Depart_Read());
		}
	}
}

/* [] END OF FILE */
