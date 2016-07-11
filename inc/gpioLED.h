#ifndef GPIOLED_H_
#define GPIOLED_H_

/*
 * =====================================================================================
 *
 *       Filename:  gpioLED.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  19/05/2016 20:03:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Francisco Helder (), helderhdw@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include "hw_control_AM335x.h"
#include "soc_AM335x.h"
#include "hw_cm_wkup.h"
#include "hw_gpio_v2.h"
#include "beaglebone.h"
#include "hw_cm_per.h"
#include "hw_types.h"

#define bit_5                    (0x00000020)
#define bit_4                    (0x00000010)
#define bit_3                    (0x00000008)

/* This is used to configure a GPIO pin as an input pin. */
#define DIR_INPUT                1
/* This is used to configure a GPIO pin as an output pin.*/
#define DIR_OUTPUT               0
/* This is used to write a logic 0 to a pin.*/
#define PIN_LOW                  0
/* This is used to write a logic 1 to a pin.*/
#define PIN_HIGH                 1


#define GPIO_INSTANCE_ADDRESS           (SOC_GPIO_1_REGS)
#define GPIO_INSTANCE_PIN_NUMBER(n)     (n)
#define TOGGLE                          (0x01u)


void GPIOPinWrite(unsigned int baseAdd,unsigned int pinNumber, unsigned int pinValue);
int ledInit(int nPin, int direcao);

int butonHigh(int nPin);
void ledHigh(int nPin);
void ledLow(int nPin);


typedef enum Pins pins;
enum pins{GPIO_0, GPIO_1, GPIO_2, GPIO_3, GPIO_4, GPIO_5, GPIO_6, GPIO_7,
  GPIO_8, GPIO_9, GPIO_10, GPIO_11, GPIO_12, GPIO_13, GPIO_14, GPIO_15,
  GPIO_16, GPIO_17, GPIO_18, GPIO_19, GPIO_20, GPIO_21, GPIO_22, GPIO_23,
  GPIO_24, GPIO_25, GPIO_26, GPIO_27, GPIO_28, GPIO_29, GPIO_30, GPIO_31};

typedef enum Mux mux;
enum mux{MUX_0, MUX_1, MUX_2, MUX_3, MUX_5, MUX_4, MUX_6, MUX_7};




#endif //GPIOLED_H_
