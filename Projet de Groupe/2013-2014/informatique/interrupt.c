// C/C++ File
// AUTHOR:   robin_arch
// FILE:     interrupt.c
// ROLE:     TODO (some explanation)
// CREATED:  2014-03-28 11:34:29
// MODIFIED: 2014-03-28 14:48:39

void initPIC(void)
{
    OSCCONbits.LPOSCEN = 1; // enable secondary 32kHz oscillator
    /*ACLKCON*/
}
void enableInterrupts(void)
{
    /* Set CPU IPL to 0, enable level 1-7 interrupts */
    /* No restoring of previous CPU IPL state performed here */
    SRbits.IPL = 0;
    return;
}
void disableInterrupts(void)
{
    /* Set CPU IPL to 7, disable level 1-7 interrupts */
    /* No saving of current CPU IPL setting performed here */
    SRbits.IPL = 7;
    return;
}
void initInterrupts(void)
{
    /* Interrupt nesting enabled here */
    INTCON1bits.NSTDIS = 0;
    /* Set Timer3 interrupt priority to 6 (level 7 is highest) */
    IPC2bits.T3IP = 6;

    /* Set Timer2 interrupt priority to 5 */
    IPC1bits.T2IP = 5;
    /* Set Change Notice interrupt priority to 4 */
    IPC4bits.CNIP = 4;
    /* Set Timer4 interrupt priority to 3 */
    IPC6bits.T4IP = 3; 
    /* Set Timer1 interrupt priority to 2 */
    IPC0bits.T1IP = 2; 
    /* Reset Timer1 interrupt flag */
    IFS0bits.T1IF = 0;
    /* Reset Timer2 interrupt flag */
    IFS0bits.T2IF = 0;
    /* Reset Timer3 interrupt flag */
    IFS0bits.T3IF = 0;
    /* Reset Timer4 interrupt flag */
    IFS1bits.T4IF = 0;
    /* Enable CN interrupts */
    IEC1bits.CNIE = 1;
    /* Enable Timer1 interrupt */
    IEC0bits.T1IE = 1;
    /* Enable Timer2 interrupt (PWM time base) */
    IEC0bits.T2IE = 1;
    /* Enable Timer3 interrupt */
    IEC0bits.T3IE = 1;
    /* Enable Timer4 interrupt (replacement for Timer 2 */
    IEC1bits.T4IE = 1;
    /* Reset change notice interrupt flag */
    IFS1bits.CNIF = 0;
    return;
}
void __attribute__((__interrupt__)) _T1Interrupt(void)
{
    /* Insert ISR Code Here*/
    /* Clear Timer1 interrupt */
    IFS0bits.T1IF = 0;
}
void __attribute__((__interrupt__)) _T2Interrupt(void)
{
    /* Insert ISR Code Here*/
    /* Clear Timer2 interrupt */
    IFS0bits.T2IF = 0;
}
void __attribute__((__interrupt__)) _T3Interrupt(void)
{
    /* Insert ISR Code Here*/
    /* Clear Timer3 interrupt */
    IFS0bits.T3IF = 0;
}
void __attribute__((__interrupt__)) _T4Interrupt(void)
{
    /* Insert ISR Code Here*/
    /* Clear Timer4 interrupt */
    IFS1bits.T4IF = 0;
}
void __attribute__((__interrupt__)) _CNInterrupt(void)
{
    /* Insert ISR Code Here*/
    /* Clear CN interrupt */
    IFS1bits.CNIF = 0;
}
