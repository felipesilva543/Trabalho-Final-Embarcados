/*
 * =====================================================================================
 *
 *       Filename:  gpioLED.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  19/05/2016 20:01:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Francisco Helder (), helderhdw@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include "gpioLED.h"

int flagToggle=0x0;

/*FUNCTION*-------------------------------------------------------
*
* Function Name : GPIO1_ModuleClkConfig
* Comments      : This function enables the L3 and L4_PER interface
* clocks. This also enables functional clocks of GPIO1 instance.
*END*-----------------------------------------------------------*/
static void GPIO1_ModuleClkConfig(void){

    /* Writing to MODULEMODE field of CM_PER_GPIO1_CLKCTRL register. */
    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO1_CLKCTRL) |=
          CM_PER_GPIO1_CLKCTRL_MODULEMODE_ENABLE;

    /*
    ** Writing to OPTFCLKEN_GPIO_1_GDBCLK bit in CM_PER_GPIO1_CLKCTRL
    ** register.
    */
    HWREG(SOC_CM_PER_REGS + CM_PER_GPIO1_CLKCTRL) |=
          CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK;

}

/*FUNCTION*-------------------------------------------------------
*
* Function Name : GPIOPinMuxSetup
* Comments      : This function does the pin multiplexing for any GPIO Pin.
*
* \param  offsetAddr   This is the offset address of the Pad Control Register
*                      corresponding to the GPIO pin. These addresses are
*                      offsets with respect to the base address of the
*                      Control Module.
* \param  padConfValue This is the value to be written to the Pad Control
*                      register whose offset address is given by 'offsetAddr'.
*
* The 'offsetAddr' and 'padConfValue' can be obtained from macros defined
* in the file 'include/armv7a/am335x/pin_mux.h'.\n
*END*-----------------------------------------------------------*/
/*static void GPIOPinMuxSetup(unsigned int offsetAddr, unsigned int padConfValue){
    HWREG(SOC_CONTROL_REGS + offsetAddr) = (padConfValue);
}*/


static void GPIOPinMuxSetup(unsigned int offsetAddr, unsigned int padConfValue){
    HWREG(SOC_CONTROL_REGS + offsetAddr) = (padConfValue);
    HWREG(SOC_CONTROL_REGS + offsetAddr) |= bit_5;
    HWREG(SOC_CONTROL_REGS + offsetAddr) &= ~(bit_4);
    HWREG(SOC_CONTROL_REGS + offsetAddr) &= ~(bit_3);
}

/*FUNCTION*-------------------------------------------------------
*
* Function Name : SPIOModuleEnable
* Comments      : This API is used to enable the GPIO module. When
* the GPIO module is enabled, the clocks to the module are not gated.
*
* \param  baseAdd    The memory address of the GPIO instance being used
*END*-----------------------------------------------------------*/
static void GPIOModuleEnable(unsigned int baseAdd){
    HWREG(baseAdd + GPIO_CTRL) &= ~(GPIO_CTRL_DISABLEMODULE);
}

/*FUNCTION*-------------------------------------------------------
*
* Function Name : SPIOModuleEnable
* Comments      : This API performs the module reset of the GPIO
* module. It also waits until the reset process is complete.
*
* \param  baseAdd    The memory address of the GPIO instance being used
*END*-----------------------------------------------------------*/
// static void GPIOModuleReset(unsigned int baseAdd){
//     HWREG(baseAdd + GPIO_SYSCONFIG) |= (GPIO_SYSCONFIG_SOFTRESET);
// }

/*FUNCTION*-------------------------------------------------------
*
* Function Name : GPIODirModeSet
* Comments      : This API configures the direction of a specified
* GPIO pin as being either input or output.
*
* \param  baseAdd       The memory address of the GPIO instance being used
* \param  pinNumber     The number of the pin in the GPIO instance
* \param  pinDirection  The required direction for the GPIO pin
*
* 'pinNumber' can take one of the following values:
* (0 <= pinNumber <= 31)\n
*
* 'pinDirection' can take one of the following values:
* - GPIO_DIR_INPUT - to configure the pin as an input pin\n
* - GPIO_DIR_OUTPUT - to configure the pin as an output pin\n
*END*-----------------------------------------------------------*/
static void GPIODirModeSet(unsigned int baseAdd,
                            unsigned int pinNumber,
                            unsigned int pinDirection) {
    /* Checking if pin is required to be an output pin. */
    if(DIR_OUTPUT == pinDirection){
        HWREG(baseAdd + GPIO_OE) &= ~(1 << pinNumber);
    }else{
        HWREG(baseAdd + GPIO_OE) |= (1 << pinNumber);
    }
}

/*FUNCTION*-------------------------------------------------------
*
* Function Name : GPIOPinWrite
* Comments      : This API drives an output GPIO pin to a logic
* HIGH or a logic LOW state.
*
* \param  baseAdd     The memory address of the GPIO instance being used
* \param  pinNumber   The number of the pin in the GPIO instance
* \param  pinValue    This specifies whether a logic HIGH or a logic LOW
*                     should be driven on the output pin
*
* 'pinNumber' can take one of the following values:
* (0 <= pinNumber <= 31)\n
*
* 'pinValue' can take one of the following values:
* - GPIO_PIN_LOW - indicating to drive a logic LOW(logic 0) on the pin.
* - GPIO_PIN_HIGH - indicating to drive a logic HIGH(logic 1) on the pin.
*END*-----------------------------------------------------------*/
void GPIOPinWrite(unsigned int baseAdd,
                          unsigned int pinNumber,
                          unsigned int pinValue) {

    if(PIN_HIGH == pinValue){
        HWREG(baseAdd + GPIO_SETDATAOUT) = (1 << pinNumber);
    }else{
        HWREG(baseAdd + GPIO_CLEARDATAOUT) = (1 << pinNumber);
    }
}

/*FUNCTION*-------------------------------------------------------
*
* Function Name : ledInit
* Comments      :
*END*-----------------------------------------------------------*/

int ledInit(int nPin, int direcao){
    int num;
    /* Enabling functional clocks for GPIO1 instance. */
    GPIO1_ModuleClkConfig();
    if ((nPin >= GPIO_0 && nPin <= GPIO_7) || (nPin >= GPIO_12 && nPin <= GPIO_15)) {
      GPIOPinMuxSetup(CONTROL_CONF_GPMC_AD(nPin), CONTROL_CONF_MUXMODE(MUX_7));
    }
    else if (nPin >= GPIO_16 && nPin <= GPIO_27) {
      num = nPin - GPIO_16;
      GPIOPinMuxSetup(CONTROL_CONF_GPMC_A(num), CONTROL_CONF_MUXMODE(MUX_7));
    }
    else if (nPin >= GPIO_29 && nPin <= GPIO_31) {
      num = nPin - GPIO_29;
      GPIOPinMuxSetup(CONTROL_CONF_GPMC_CSN(num), CONTROL_CONF_MUXMODE(MUX_7));
    }
    else {
      switch (nPin) {
        case GPIO_8:

          GPIOPinMuxSetup(CONTROL_CONF_UART_CTSN(0), CONTROL_CONF_MUXMODE(MUX_7));
          break;
        case GPIO_9:
          GPIOPinMuxSetup(CONTROL_CONF_UART_RTSN(0), CONTROL_CONF_MUXMODE(MUX_7));
          break;
        case GPIO_10:
          GPIOPinMuxSetup(CONTROL_CONF_UART_RXD(0), CONTROL_CONF_MUXMODE(MUX_7));
          break;
        case GPIO_11:
          GPIOPinMuxSetup(CONTROL_CONF_UART_TXD(0), CONTROL_CONF_MUXMODE(MUX_7));
          break;
        case GPIO_28:
          GPIOPinMuxSetup(CONTROL_CONF_GPMC_BE1N, CONTROL_CONF_MUXMODE(MUX_7));
          break;
      }
    }

    /* Enabling the GPIO module. */
    GPIOModuleEnable(GPIO_INSTANCE_ADDRESS);

    /* Resetting the GPIO module. */
//    GPIOModuleReset(GPIO_INSTANCE_ADDRESS);

    /* Setting the GPIO pin as an output pin. */
    GPIODirModeSet(GPIO_INSTANCE_ADDRESS,
              GPIO_INSTANCE_PIN_NUMBER(nPin),
              direcao);

    return(0);
}


void ledHigh(int nPin){
  GPIOPinWrite(GPIO_INSTANCE_ADDRESS,
  GPIO_INSTANCE_PIN_NUMBER(nPin),
  PIN_HIGH);
}

void ledLow(int nPin){
  GPIOPinWrite(GPIO_INSTANCE_ADDRESS,
  GPIO_INSTANCE_PIN_NUMBER(nPin),
  PIN_LOW);
}

// 
// void cobrinha(){
//   //LIGA COBRA APAGA COBRA
// 			ledHigh(pinOut1);
// 			Delay(MSEG);
// 			ledHigh(pinOut4);
// 			Delay(MSEG);
// 			ledHigh(pinOut7);
// 			Delay(MSEG);
// 			ledHigh(pinOut8);
// 			Delay(MSEG);
// 			ledHigh(pinOut9);
// 			Delay(MSEG);
// 			ledHigh(pinOut6);
// 			Delay(MSEG);
// 			ledHigh(pinOut3);
// 			Delay(MSEG);
// 			ledHigh(pinOut2);
// 			Delay(MSEG);
// 			ledHigh(pinOut5);
// 			Delay(MSEG);
// 			ledLow(pinOut5);
// 			Delay(MSEG);
// 			ledLow(pinOut2);
// 			Delay(MSEG);
// 			ledLow(pinOut3);
// 			Delay(MSEG);
// 			ledLow(pinOut6);
// 			Delay(MSEG);
// 			ledLow(pinOut9);
// 			Delay(MSEG);
// 			ledLow(pinOut8);
// 			Delay(MSEG);
// 			ledLow(pinOut7);
// 			Delay(MSEG);
// 			ledLow(pinOut4);
// 			Delay(MSEG);
// 			ledLow(pinOut1);
// 			Delay(MSEG);
// }
