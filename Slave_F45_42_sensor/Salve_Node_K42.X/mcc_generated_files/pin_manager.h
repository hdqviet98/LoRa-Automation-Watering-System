/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC18F45K42
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.30 and above
        MPLAB 	          :  MPLAB X 5.40	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IN_CONFIG aliases
#define IN_CONFIG_TRIS                 TRISAbits.TRISA2
#define IN_CONFIG_LAT                  LATAbits.LATA2
#define IN_CONFIG_PORT                 PORTAbits.RA2
#define IN_CONFIG_WPU                  WPUAbits.WPUA2
#define IN_CONFIG_OD                   ODCONAbits.ODCA2
#define IN_CONFIG_ANS                  ANSELAbits.ANSELA2
#define IN_CONFIG_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IN_CONFIG_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IN_CONFIG_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IN_CONFIG_GetValue()           PORTAbits.RA2
#define IN_CONFIG_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IN_CONFIG_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IN_CONFIG_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define IN_CONFIG_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define IN_CONFIG_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define IN_CONFIG_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define IN_CONFIG_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define IN_CONFIG_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set SS_LED1 aliases
#define SS_LED1_TRIS                 TRISAbits.TRISA5
#define SS_LED1_LAT                  LATAbits.LATA5
#define SS_LED1_PORT                 PORTAbits.RA5
#define SS_LED1_WPU                  WPUAbits.WPUA5
#define SS_LED1_OD                   ODCONAbits.ODCA5
#define SS_LED1_ANS                  ANSELAbits.ANSELA5
#define SS_LED1_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define SS_LED1_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define SS_LED1_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define SS_LED1_GetValue()           PORTAbits.RA5
#define SS_LED1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define SS_LED1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define SS_LED1_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define SS_LED1_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define SS_LED1_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define SS_LED1_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define SS_LED1_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define SS_LED1_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSELB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RELAY_1 aliases
#define RELAY_1_TRIS                 TRISBbits.TRISB3
#define RELAY_1_LAT                  LATBbits.LATB3
#define RELAY_1_PORT                 PORTBbits.RB3
#define RELAY_1_WPU                  WPUBbits.WPUB3
#define RELAY_1_OD                   ODCONBbits.ODCB3
#define RELAY_1_ANS                  ANSELBbits.ANSELB3
#define RELAY_1_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RELAY_1_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RELAY_1_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RELAY_1_GetValue()           PORTBbits.RB3
#define RELAY_1_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RELAY_1_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RELAY_1_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define RELAY_1_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define RELAY_1_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define RELAY_1_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define RELAY_1_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define RELAY_1_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RELAY_2 aliases
#define RELAY_2_TRIS                 TRISBbits.TRISB4
#define RELAY_2_LAT                  LATBbits.LATB4
#define RELAY_2_PORT                 PORTBbits.RB4
#define RELAY_2_WPU                  WPUBbits.WPUB4
#define RELAY_2_OD                   ODCONBbits.ODCB4
#define RELAY_2_ANS                  ANSELBbits.ANSELB4
#define RELAY_2_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RELAY_2_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RELAY_2_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RELAY_2_GetValue()           PORTBbits.RB4
#define RELAY_2_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RELAY_2_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RELAY_2_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define RELAY_2_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define RELAY_2_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define RELAY_2_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define RELAY_2_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RELAY_2_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RS485_EN aliases
#define RS485_EN_TRIS                 TRISDbits.TRISD4
#define RS485_EN_LAT                  LATDbits.LATD4
#define RS485_EN_PORT                 PORTBbits.RB5
#define RS485_EN_WPU                  WPUBbits.WPUB5
#define RS485_EN_OD                   ODCONBbits.ODCB5
#define RS485_EN_ANS                  ANSELBbits.ANSELB5
#define RS485_EN_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define RS485_EN_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
//#define RS485_EN_SetHigh()            do { RD4 = 1; } while(0)
//#define RS485_EN_SetLow()             do {RD4 = 0; } while(0)
#define RS485_EN_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RS485_EN_GetValue()           PORTBbits.RB5
#define RS485_EN_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RS485_EN_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RS485_EN_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define RS485_EN_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define RS485_EN_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define RS485_EN_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define RS485_EN_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define RS485_EN_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)
#define RB6_SetAnalogMode()         do { ANSELBbits.ANSELB6 = 1; } while(0)
#define RB6_SetDigitalMode()        do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSELB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSELB7 = 0; } while(0)

// get/set IN_WIRE aliases
#define IN_WIRE_TRIS                 TRISCbits.TRISC5
#define IN_WIRE_LAT                  LATCbits.LATC5
#define IN_WIRE_PORT                 PORTCbits.RC5
#define IN_WIRE_WPU                  WPUCbits.WPUC5
#define IN_WIRE_OD                   ODCONCbits.ODCC5
#define IN_WIRE_ANS                  ANSELCbits.ANSELC5
#define IN_WIRE_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IN_WIRE_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IN_WIRE_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IN_WIRE_GetValue()           PORTCbits.RC5
#define IN_WIRE_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IN_WIRE_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IN_WIRE_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define IN_WIRE_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define IN_WIRE_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define IN_WIRE_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define IN_WIRE_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define IN_WIRE_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set LED_M1 aliases
#define LED_M1_TRIS                 TRISDbits.TRISD2
#define LED_M1_LAT                  LATDbits.LATD2
#define LED_M1_PORT                 PORTDbits.RD2
#define LED_M1_WPU                  WPUDbits.WPUD2
#define LED_M1_OD                   ODCONDbits.ODCD2
#define LED_M1_ANS                  ANSELDbits.ANSELD2
#define LED_M1_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define LED_M1_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define LED_M1_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define LED_M1_GetValue()           PORTDbits.RD2
#define LED_M1_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define LED_M1_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define LED_M1_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define LED_M1_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define LED_M1_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define LED_M1_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define LED_M1_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define LED_M1_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set LED_M2 aliases
#define LED_M2_TRIS                 TRISDbits.TRISD3
#define LED_M2_LAT                  LATDbits.LATD3
#define LED_M2_PORT                 PORTDbits.RD3
#define LED_M2_WPU                  WPUDbits.WPUD3
#define LED_M2_OD                   ODCONDbits.ODCD3
#define LED_M2_ANS                  ANSELDbits.ANSELD3
#define LED_M2_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define LED_M2_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define LED_M2_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define LED_M2_GetValue()           PORTDbits.RD3
#define LED_M2_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define LED_M2_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define LED_M2_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define LED_M2_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define LED_M2_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define LED_M2_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define LED_M2_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define LED_M2_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set AUX aliases
#define AUX_TRIS                 TRISDbits.TRISD4
#define AUX_LAT                  LATDbits.LATD4
#define AUX_PORT                 PORTDbits.RD4
#define AUX_WPU                  WPUDbits.WPUD4
#define AUX_OD                   ODCONDbits.ODCD4
#define AUX_ANS                  ANSELDbits.ANSELD4
#define AUX_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define AUX_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define AUX_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define AUX_GetValue()           PORTDbits.RD4
#define AUX_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define AUX_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define AUX_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define AUX_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define AUX_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define AUX_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define AUX_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define AUX_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set M1 aliases
#define M1_TRIS                 TRISDbits.TRISD5
#define M1_LAT                  LATDbits.LATD5
#define M1_PORT                 PORTDbits.RD5
#define M1_WPU                  WPUDbits.WPUD5
#define M1_OD                   ODCONDbits.ODCD5
#define M1_ANS                  ANSELDbits.ANSELD5
#define M1_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define M1_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define M1_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define M1_GetValue()           PORTDbits.RD5
#define M1_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define M1_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define M1_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define M1_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define M1_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define M1_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define M1_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define M1_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set M0 aliases
#define M0_TRIS                 TRISDbits.TRISD6
#define M0_LAT                  LATDbits.LATD6
#define M0_PORT                 PORTDbits.RD6
#define M0_WPU                  WPUDbits.WPUD6
#define M0_OD                   ODCONDbits.ODCD6
#define M0_ANS                  ANSELDbits.ANSELD6
#define M0_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define M0_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define M0_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define M0_GetValue()           PORTDbits.RD6
#define M0_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define M0_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define M0_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define M0_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define M0_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define M0_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define M0_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define M0_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)



// get/set LED_D1 aliases
#define LED_D1_TRIS                 TRISEbits.TRISE1
#define LED_D1_LAT                  LATEbits.LATE1
#define LED_D1_PORT                 PORTEbits.RE1
#define LED_D1_WPU                  WPUEbits.WPUE1
#define LED_D1_OD                   ODCONEbits.ODCE1
#define LED_D1_ANS                  ANSELEbits.ANSELE1
#define LED_D1_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define LED_D1_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define LED_D1_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define LED_D1_GetValue()           PORTEbits.RE1
#define LED_D1_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define LED_D1_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define LED_D1_SetPullup()          do { WPUEbits.WPUE1 = 1; } while(0)
#define LED_D1_ResetPullup()        do { WPUEbits.WPUE1 = 0; } while(0)
#define LED_D1_SetPushPull()        do { ODCONEbits.ODCE1 = 0; } while(0)
#define LED_D1_SetOpenDrain()       do { ODCONEbits.ODCE1 = 1; } while(0)
#define LED_D1_SetAnalogMode()      do { ANSELEbits.ANSELE1 = 1; } while(0)
#define LED_D1_SetDigitalMode()     do { ANSELEbits.ANSELE1 = 0; } while(0)

// get/set LED_RELAY2 aliases
#define LED_RELAY2_TRIS                 TRISEbits.TRISE2
#define LED_RELAY2_LAT                  LATEbits.LATE2
#define LED_RELAY2_PORT                 PORTEbits.RE2
#define LED_RELAY2_WPU                  WPUEbits.WPUE2
#define LED_RELAY2_OD                   ODCONEbits.ODCE2
#define LED_RELAY2_ANS                  ANSELEbits.ANSELE2
#define LED_RELAY2_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define LED_RELAY2_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define LED_RELAY2_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define LED_RELAY2_GetValue()           PORTEbits.RE2
#define LED_RELAY2_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define LED_RELAY2_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define LED_RELAY2_SetPullup()          do { WPUEbits.WPUE2 = 1; } while(0)
#define LED_RELAY2_ResetPullup()        do { WPUEbits.WPUE2 = 0; } while(0)
#define LED_RELAY2_SetPushPull()        do { ODCONEbits.ODCE2 = 0; } while(0)
#define LED_RELAY2_SetOpenDrain()       do { ODCONEbits.ODCE2 = 1; } while(0)
#define LED_RELAY2_SetAnalogMode()      do { ANSELEbits.ANSELE2 = 1; } while(0)
#define LED_RELAY2_SetDigitalMode()     do { ANSELEbits.ANSELE2 = 0; } while(0)

// get/set LED_D2 aliases
#define LED_D2_TRIS                 TRISEbits.TRISE0
#define LED_D2_LAT                  LATEbits.LATE0
#define LED_D2_PORT                 PORTEbits.RE0
#define LED_D2_WPU                  WPUEbits.WPUE0
#define LED_D2_OD                   ODCONEbits.ODCE0
#define LED_D2_ANS                  ANSELEbits.ANSELE0
#define LED_D2_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define LED_D2_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define LED_D2_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define LED_D2_GetValue()           PORTEbits.RE0
#define LED_D2_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define LED_D2_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define LED_D2_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define LED_D2_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define LED_D2_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define LED_D2_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define LED_D2_SetAnalogMode()      do { ANSELEbits.ANSELE0 = 1; } while(0)
#define LED_D2_SetDigitalMode()     do { ANSELEbits.ANSELE0 = 0; } while(0)
/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);




#endif // PIN_MANAGER_H
/**
 End of File
*/