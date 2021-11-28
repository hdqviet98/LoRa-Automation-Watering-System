/**
  Generated Interrupt Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    interrupt_manager.h

  @Summary:
    This is the Interrupt Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description:
    This header file provides implementations for global interrupt handling.
    For individual peripheral handlers please see the peripheral driver for
    all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F45K42
        Driver Version    :  2.12
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above or later
        MPLAB 	          :  MPLAB X 5.20
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

#include "interrupt_manager.h"
#include "../../modbus/i2c2_master.h"
#include "mcc.h"

void INTERRUPT_Initialize(void) {
    // Enable Interrupt Priority Vectors
    INTCON0bits.IPEN = 1;
    // Assign peripheral interrupt priority vectors

    // URXI - high priority
    IPR3bits.U1RXIP = 1;

    // URXI - low priority
    IPR6bits.U2RXIP = 0;

    // TMRI - low priority
    IPR3bits.TMR0IP = 0;

    // ICEI - high priority
    IPR3bits.I2C1EIP = 1;

    // ICRXI - high priority
    IPR2bits.I2C1RXIP = 1;

    // ICI - high priority
    IPR3bits.I2C1IP = 1;

    // ICTXI - high priority
    IPR3bits.I2C1TXIP = 1;

}

void __interrupt() INTERRUPT_InterruptManagerHigh(void) {
    // interrupt handler
    if (PIE3bits.U1RXIE == 1 && PIR3bits.U1RXIF == 1) {
        UART1_RxInterruptHandler();
    }// interrupt handler
    if (PIE5bits.I2C2RXIE == 1 && PIR5bits.I2C2RXIF == 1) {
        I2C2_InterruptHandler();
    } else if (PIE5bits.I2C2TXIE == 1 && PIR5bits.I2C2TXIF == 1) {
        I2C2_InterruptHandler();
    } else {
        //Unhandled Interrupt
    }

}

void __interrupt(low_priority) INTERRUPT_InterruptManagerLow(void) {
    // interrupt handler

    if (PIE6bits.U2RXIE == 1 && PIR6bits.U2RXIF == 1) {
        UART2_RxInterruptHandler();
    } else if (PIE3bits.TMR0IE == 1 && PIR3bits.TMR0IF == 1) {
        TMR0_ISR();
    }
    if (PIE6bits.I2C2IE == 1 && PIR6bits.I2C2IF == 1) {
        I2C2_InterruptHandler();
    } else if (PIE6bits.I2C2EIE == 1 && PIR6bits.I2C2EIF == 1) {
        I2C2_InterruptHandler();
    } else {
        //Unhandled Interrupt
    }
}

/**
 End of File
 */
