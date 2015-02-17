//#include <>
#define FCY 32000
main ()
{
//	TRISA = 0x00 ;
	while(1)
	{
		int a = 0b00000100 ;
		int b = 0b00000010 ;
		delay_ms(200) ;
//		PORTA = a | 0b11111001 ;

		delay_ms(200) ;

//		PORTA = b | 0b11111001;
	}
	
	
}

void	delay_ms(int ms)
{
//	T2CONbits.TCKPS = 0b11  ;
//	T2CONbits.TCS = 0 ;
//	PR2 = FCY*ms*0,001/256 ;
}
