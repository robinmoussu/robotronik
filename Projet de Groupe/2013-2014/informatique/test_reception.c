
/*
 *    Tracking location of robot
 *    Copyright (C) 2014 Robotronik
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



/** \file test_reception.c
 * \brief Permet de valider la réception de bits.
 *
 * \note Les pattes RA1 et RA2 doivent etre relié à des diodes, et la patte RA3 au capteur à tester.
 *
 * Allume une diode sur RA1 et éteind une diode sur RA2 si des bits sont reçus sur la patte RA3, et inversement
 */

void initPic();
void recep_valid(void);

int main(void)
{
    initPic();
    recep_valid();
}

void initPic()
{
    TRISA=0b00000011
}

void recep_valid(void)
{
    if (PORTAbits.bit3==1) {
        PORTAbits.bits1=1;
        PORTAbits.bit2=0;
    } else {
        PORTAbits.bit2=1;
        PORTAbits.bit1=0;
    }
}

