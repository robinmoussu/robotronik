#include "emission.h"
#include "common.h"

void	emission_trame (Trame ti) /*parcourt la trame de bits "ti" et émet chacun de ses bits*/
{
	int	i = 0 ;
	while(i < NB_BIT + 2)
	{
		emission_bit(ti [i]) ;
		i++ ;
	}
}

/* emmet le codage correspondant à un bit de valeur 0
 */
void	emission_0 ()
{
	
}

/* emmet le codage correspondant à un bit de valeur 1
 */
void	emission_1 ()
{
	
}

void	emission_bit (Bit	bit)/*Reçoit un bit et émet un 0 ou un 1 en fonction de la valeur de ce bit en utilisant les fonctions emission_0 et emission_1*/
{
//	if (bit == 0)
//	emission_0() ;
//	else if (bit == 1)
//	emission_1() ;
}

void	allumer_diode (void)
{
//	RA0 = 1 ;//Le bit 0 du port A prend la valeur 1
}

void	eteindre_diode (void)
{
//	RA0 = 0 ;//Le bit 0 du port A prend la valeur 0
}

void	init(void)
{
	TRISA = 0 ;// Tous les bits du port A fonctionnennt en sortie (TRISA = 1 pour qu'ils fonctionnent en entrée)
}

int	main()
{
	init() ;
//	TCKPS = 0b00;
	
	

	
	return (0) ;
}
