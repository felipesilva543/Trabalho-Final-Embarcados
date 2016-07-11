/*
 * =====================================================================================
 *
 *       Filename:  gpioLEDBlink.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  15/05/2016 12:15:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Francisco Helder (), helderhdw@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include "gpioLED.h"

/*****************************************************************************
**                INTERNAL MACRO DEFINITIONS
*****************************************************************************/
#define MSEG                        (0x3FFFFFF)


/*****************************************************************************
**                INTERNAL FUNCTION PROTOTYPES
*****************************************************************************/
static void Delay(unsigned int count);


/*FUNCTION*-------------------------------------------------------
*
* Function Name : main
* Comments      :
*END*-----------------------------------------------------------*/
int main() {
    int i, j;
    int pinIn = 12;
    int pinOut1 = 13; //11
    int pinOut2 = 15; //15
    int pinOut3 = 4; //23
    int pinOut4 = 29; //26
    int pinOut5 = 0; //25
    int pinOut6 = 1; //24
    int pinOut7 = 16; //15
    int pinOut8 = 17; //23
    int pinOut9 = 28; //12

    int vet[9] = {pinOut1, pinOut2, pinOut3, pinOut4, pinOut5, pinOut6, pinOut7, pinOut8, pinOut9};

    ledInit(pinIn, DIR_INPUT);

    for(i = 0; i < 9; i++)
      ledInit(vet[i], DIR_OUTPUT);

  while(TRUE){
  	if(butonHigh(pinIn)){

      for (j = 0; j < 3; j++){
        for(i=0;i<4;i++){
          ledHigh(pinOut5);
        	Delay(MSEG);
        	ledLow(pinOut5);
          Delay(MSEG);
        }

        for(i = 0; i < 9; i++)
          ledHigh(vet[i]);
  		    Delay(MSEG);
        for(i = 0; i < 9; i++)
          ledLow(vet[i]);
          Delay(MSEG);
        //////////////////////////////////////////////////////////////
        ledHigh(pinOut1);
				Delay(MSEG);
				ledHigh(pinOut4);
				Delay(MSEG);
				ledHigh(pinOut7);
				Delay(MSEG);
				ledHigh(pinOut8);
				Delay(MSEG);
				ledHigh(pinOut9);
				Delay(MSEG);
				ledHigh(pinOut6);
				Delay(MSEG);
				ledHigh(pinOut3);
				Delay(MSEG);
				ledHigh(pinOut2);
				Delay(MSEG);
				ledHigh(pinOut5);
				Delay(MSEG);
				ledLow(pinOut5);
				Delay(MSEG);
				ledLow(pinOut2);
				Delay(MSEG);
				ledLow(pinOut3);
				Delay(MSEG);
				ledLow(pinOut6);
				Delay(MSEG);
				ledLow(pinOut9);
				Delay(MSEG);
				ledLow(pinOut8);
				Delay(MSEG);
				ledLow(pinOut7);
				Delay(MSEG);
				ledLow(pinOut4);
				Delay(MSEG);
				ledLow(pinOut1);
				Delay(MSEG);

				//Cobra Inversa
				ledHigh(pinOut1);
				Delay(MSEG);
				ledHigh(pinOut2);
				Delay(MSEG);
				ledHigh(pinOut3);
				Delay(MSEG);
				ledHigh(pinOut6);
				Delay(MSEG);
				ledHigh(pinOut9);
				Delay(MSEG);
				ledHigh(pinOut8);
				Delay(MSEG);
				ledHigh(pinOut7);
				Delay(MSEG);
				ledHigh(pinOut4);
				Delay(MSEG);
				ledHigh(pinOut5);
				Delay(MSEG);
				ledLow(pinOut5);
				Delay(MSEG);
				ledLow(pinOut4);
				Delay(MSEG);
				ledLow(pinOut7);
				Delay(MSEG);
				ledLow(pinOut8);
				Delay(MSEG);
				ledLow(pinOut9);
				Delay(MSEG);
				ledLow(pinOut6);
				Delay(MSEG);
				ledLow(pinOut3);
				Delay(MSEG);
				ledLow(pinOut2);
				Delay(MSEG);
				ledLow(pinOut1);
				Delay(MSEG);
        ///////////////////////////////////////////////
        //Diagonal Acender
        for(i = 0; i < 9; i= i+2){
          ledHigh(vet[i]);}
        Delay(MSEG);
        for(i = 0; i < 9; i= i+2){
				  ledLow(vet[i]);}
				Delay(MSEG);

        for(i = 1; i < 9; i= i+2){
				  ledHigh(vet[i]);}
				      Delay(MSEG);
        for(i = 1; i < 9; i= i+2){
				  ledLow(vet[i]);}
				  Delay(MSEG);

				// +

				ledHigh(pinOut2);
				ledHigh(pinOut4);
				ledHigh(pinOut5);
				ledHigh(pinOut6);
				ledHigh(pinOut8);
				Delay(MSEG);
				ledLow(pinOut2);
				ledLow(pinOut4);
				ledLow(pinOut5);
				ledLow(pinOut6);
				ledLow(pinOut8);
				Delay(MSEG);
				ledHigh(pinOut1);
				ledHigh(pinOut3);
				ledHigh(pinOut7);
				ledHigh(pinOut9);
				Delay(MSEG);
				ledLow(pinOut1);
				ledLow(pinOut3);
				ledLow(pinOut7);
				ledLow(pinOut9);
				Delay(MSEG);
        /////////////////////////////////////////
        //LIGA FILA APAGA FILA
				ledHigh(pinOut1);
				ledHigh(pinOut2);
				ledHigh(pinOut3);
				Delay(MSEG);
				ledLow(pinOut1);
				ledLow(pinOut2);
				ledLow(pinOut3);
				Delay(MSEG);
				ledHigh(pinOut4);
				ledHigh(pinOut5);
				ledHigh(pinOut6);
				Delay(MSEG);
				ledLow(pinOut4);
				ledLow(pinOut5);
				ledLow(pinOut6);
				Delay(MSEG);
				ledHigh(pinOut7);
				ledHigh(pinOut8);
				ledHigh(pinOut9);
				Delay(MSEG);
				ledLow(pinOut7);
				ledLow(pinOut8);
				ledLow(pinOut9);
				Delay(MSEG);
				ledHigh(pinOut7);
				ledHigh(pinOut8);
				ledHigh(pinOut9);
				Delay(MSEG);
				ledLow(pinOut7);
				ledLow(pinOut8);
				ledLow(pinOut9);
				Delay(MSEG);
				ledHigh(pinOut4);
				ledHigh(pinOut5);
				ledHigh(pinOut6);
				Delay(MSEG);
				ledLow(pinOut4);
				ledLow(pinOut5);
				ledLow(pinOut6);
				Delay(MSEG);
				ledHigh(pinOut1);
				ledHigh(pinOut2);
				ledHigh(pinOut3);
				Delay(MSEG);
				ledLow(pinOut1);
				ledLow(pinOut2);
				ledLow(pinOut3);
				Delay(MSEG);

				//LIGA COLUNA APAGA COLUNA
				ledHigh(pinOut1);
				ledHigh(pinOut4);
				ledHigh(pinOut7);
				Delay(MSEG);
				ledLow(pinOut1);
				ledLow(pinOut4);
				ledLow(pinOut7);
				Delay(MSEG);
				ledHigh(pinOut2);
				ledHigh(pinOut5);
				ledHigh(pinOut8);
				Delay(MSEG);
				ledLow(pinOut2);
				ledLow(pinOut5);
				ledLow(pinOut8);
				Delay(MSEG);
				ledHigh(pinOut3);
				ledHigh(pinOut6);
				ledHigh(pinOut9);
				Delay(MSEG);
				ledLow(pinOut3);
				ledLow(pinOut6);
				ledLow(pinOut9);
				Delay(MSEG);
				ledHigh(pinOut3);
				ledHigh(pinOut6);
				ledHigh(pinOut9);
				Delay(MSEG);
				ledLow(pinOut3);
				ledLow(pinOut6);
				ledLow(pinOut9);
				Delay(MSEG);
				ledHigh(pinOut2);
				ledHigh(pinOut5);
				ledHigh(pinOut8);
				Delay(MSEG);
				ledLow(pinOut2);
				ledLow(pinOut5);
				ledLow(pinOut8);
				Delay(MSEG);
				ledHigh(pinOut1);
				ledHigh(pinOut4);
				ledHigh(pinOut7);
				Delay(MSEG);
				ledLow(pinOut1);
				ledLow(pinOut4);
				ledLow(pinOut7);
				Delay(MSEG);
////////////////////////////////////////////////////////
      }
    }
  }
  return(0);
}

int butonHigh(int nPin){
	int *up = (int *) (GPIO_INSTANCE_ADDRESS + GPIO_DATAIN);
	int press = *up;

	if(press & (1<<nPin)){
      return PIN_HIGH;
  }	else {
      return PIN_LOW;
    }
}

static void Delay(volatile unsigned int count){
    while(count--);
      asm("   nop");
}
