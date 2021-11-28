/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.170.0
        Device            :  PIC24FJ128GA705
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.61
        MPLAB 	          :  MPLAB X v5.45
 */

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

/**
  Section: Included Files
 */
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include <stdio.h>
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/clock.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/interrupt_manager.h"
#include "mcc_generated_files/traps.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/uart2.h"
#include "mcc_generated_files/uart1.h"
#include <string.h>
//#include <libpic30.h>
char data_hmi[50] = "";
uint8_t index_hmi = 0;
char data_get[50] = "";
uint8_t flag_hmi = 0;
char relay1[8] = {0x02,0x05,0x00,0x00,0xFF,0x00,0x8C,0x09};
/*
                         Main application
 */
uint16_t delay;
//#define FCY 20000000UL
int main(void) {uint8_t i;
for (i=0;i<100;i++){Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();}
    // initialize the device
    SYSTEM_Initialize();
    IO_RB12_SetHigh();
    IO_RB13_SetHigh();
    printf("test \r\n");M0_SetLow();M1_SetHigh();
    while (PORTBbits.RB7 != 1){}
    //printf("test \r\n");
    //printf("test \r\n");
    UART1_Write(0xc0); //comand config
    UART1_Write(0x00); //starting addr
    UART1_Write(0x09); //length
    UART1_Write(0xff); //addrh
//    UART2_Write(0xff); //err
    UART1_Write(0xff); //addrl
    UART1_Write(0x00); //netid
    UART1_Write(0x62); //reg0
    UART1_Write(0x00); //reg1
    UART1_Write(0x17); //reg2(channel)
    UART1_Write(0x03); //reg3
    UART1_Write(0x00); //keyh
    UART1_Write(0x00); //k
    for (i=0;i<100;i++){Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();}
    M1_SetLow();
//    while (PORTBbits.RB7 != 1){}
//    UART2_Write(0xff); //addrl
//    UART2_Write(0x00); //netid
     //reg0
//    UART2_Write(0x00);
    
    while (1) {
    
//for (i=0;i<50;i++){Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();}
//        if (flag_hmi == 1) {
//            for (i = 0; i < 3; i++) {
//                data_get[i] = data_hmi[i + 1];
//            }
//            //printf("%s\r\n", data_hmi);
//            printf("%s\r\n", data_get);
//            index_hmi=0;
//            flag_hmi=0;
//            memset(data_hmi,0x00,50);
//        }
    }
}

