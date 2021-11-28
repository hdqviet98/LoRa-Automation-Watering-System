/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC18F45K42
        Driver Version    :  2.00
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
#include <xc.h>
#include "mcc_generated_files/spi1.h"
#include "mcc_generated_files/mcc.h"
#include "main.h"
#include "lora_setting.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/uart1.h"
#include "../modbus/modbus_app_layer.h"
#include <string.h>
#include "eeprom.h"
#include "../modbus/am2315.h"
#include "../modbus/i2c2_master.h"
/////////////////new
// --------------- PLEASE CHANGE TO THE CORRESPONDING NODE --------------------
// AM2315: 0x02; ILLUMINANCE: 0x03; SOIL_MOISTURE: 0x04; RELAY_NODE: 0x05
#define MODBUS_LORA_ADDR 0x02
#define NETWORK_ID 0x01     //0x00 
#define CHANNEL_ID 0x39     //0x40
#define HIGH_KEY 0x03       //0x99
#define LOW_KEY 0x09        //0x99
void set_stopbits(uint8_t stop);
void set_parity(uint8_t parity);
void set_baudrate(uint8_t br);
void set_baudrate_uart2(uint8_t br);
uint8_t led_blink;

enum _typeSensor {
    AM2315_SENSOR,
    ILLUMINANCE_SENSOR,
    SOILMOISTURE_SENSOR,
    RELAY_NODE,
} typeSensor = AM2315_SENSOR;

//#define LED_LORA LATEbits.LATE2 //Relay

#define LED_LORA LATAbits.LATA5 

enum _RHSensor {
    AM2315,
    SHT20,
} RHSensor = AM2315;
// ----------------------------------------------------------------------------
#define MEC10_ADDR 0x01
#define LIGHT_INTENSITY_ADDR 0x01
#define MEC10_QUALITY_REG 0x0001  
#define LIGHT_QUALITY_REG 0x0002
#define START_REG 0x0000
#define START_REG_485_12V 0x0002
#define SENSOR_DATA_TIMEOUT 15000
#define START_HOLD_REGS  0
#define HOLD_SIZE  50
#define EEPROM_BUFFER_SIZE 10
#define NUM_ITERATIONS      64  // The number of iterations for Encode() and Decode()
#define LED_RFSETTING_TIMEOUT 200

#define bit_set(var, pos) var |= (1 << pos)
#define bit_clear(var, pos) var &= (~(1 << pos))
#define bit_test(var, pos) ((var) & (1<<(pos)))

static enum {
    START_RF_SETTING = 0, // khoi dong vao che do setting aurx=0,m0=0,m1=1
    INSTALL_RF_SETTING, // cai dat thong so
    CHECK_RF_SETTING, // KIEM TRA LAI DU LIEU DA CAI DAT = DU LIEU CAI DAT
    WAIT_STATUS,
    END_RF_SETTING, // doi su kien
    RF_CONFIG_ERROR// CONFIG ERROR
} smSettingRF = START_RF_SETTING;

enum _readDataSensor {
    BEGIN_MODBUS_SENSOR,
    SEND_REQUEST_MODBUS_SENSOR,
    END_REQUEST_MODBUS_SENSOR,
    STOP_MODBUS_SENSOR,
} readDataSensor = STOP_MODBUS_SENSOR;

extern uint8_t flagInstallRFSettings; // 1: Installing settings for LoRa RF
extern uint8_t flagCheckRFSettings; // 1: LoRa RF settings has been installed and it is ready for checking the RF settings.
extern uint8_t lenRFSettingData;
extern uint8_t rfSettingResponse[15]; // Response of RF settings returned from LoRa module
extern uint8_t flagReceiveRS485LoRa; // 1: Receiving data via RS485; 0: Receiving data via LoRa RF

extern float tempVal, humVal; // The values of Temperature and Humidity collected from AM2315
uint8_t key[16] = "1"; // Crypt key used in Encode() and Decode() functions
const unsigned long DELTA = 1; // Used in Encode() and Decode() functions
// Variable used in checkSetDefault() function
static BOOL set = 1;
static uint8_t config = 0;
static BOOL wait = 0;
static BOOL kl = 0;
uint32_t ky = 0;
extern uint16_t hold_regs[50]; // Variable used to store data collected from the sensor.
extern uint8_t inputs;
extern uint8_t coils;
BOOL events_coils_output = 0;
uint8_t data_read_coil = 0;
extern modbusrx modbus_rx; // Stored data received from Modbus, including both RS485 and LoRa RF
uint8_t modbus_address =2;
uint8_t modbus_baudrate;
uint8_t modbus_parity;
uint8_t modbus_stop;
uint32_t t = 0; // time tick
uint32_t tErr = 0; // time Error setting
uint32_t timer_out_data_rf = 0;
BOOL flag_send_rf_485;
uint8_t sum_error_get485 = 0; //tong so lan bi loi
unsigned long ledToggleTimeout = 0;
unsigned long sensorDataTimeout = 0;
extern volatile unsigned long tick_time1 = 0; // TMR0 counter
extern volatile unsigned short sensor_timer1_ms = 0; // ms
uint8_t eeprom_buffer_write[EEPROM_BUFFER_SIZE];
uint8_t eeprom_buffer_read[EEPROM_BUFFER_SIZE];
uint8_t read_eeprom_flag = 0;
extern uint8_t flag_id_mb; // Check Data have been sent ?
uint32_t tick_reset_setting_rx_lora; // no data feedback 
uint8_t sum_reset_device = 0; // flag_reset_device error
extern uint8_t index;
/*
                         Main application
 */
//////////////////new



//static BOOL checkSetDefault(void);

/*
                         Main application
 */
uint8_t C,ff;
uint8_t rxlora[20];
BOOL flag,checklora;
uint8_t c_lora=0;
uint8_t len_lora=0;
int i;
uint8_t check[12]={0xc1,0x00,0x09,0xff,0xff,0x00,0x62,0x00,0x17,0x03,0x00,0x00};

void config_button();
void configlora();
void main(void) {

    
    // Initialize the device
    uint32_t i = 50000;
//    while (i > 0) {
//        i--;
//        Nop();
//        Nop();
//        Nop();
//        //        LED_STT1_SetHigh();
//    }
    SYSTEM_Initialize();
    RS485_EN_TRIS = 0;
    RS485_EN_SetLow();  
//    RS485_EN_LAT = 1;
    TRISAbits.TRISA4=0;ANSELAbits.ANSELA4=0;
    TRISAbits.TRISA5=0;ANSELAbits.ANSELA5=0;
    TRISBbits.TRISB4=0;ANSELBbits.ANSELB4=0;
    TRISBbits.TRISB5=0;ANSELBbits.ANSELB5=0;
    TRISAbits.TRISA3=1;ANSELAbits.ANSELA3=0;
    TRISBbits.TRISB3=1;ANSELBbits.ANSELB3=0;
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:
        INTERRUPT_GlobalInterruptEnable();
    // Enable high priority global interrupts
//    INTERRUPT_GlobalInterruptHighEnable();
    // Enable low priority global interrupts.
//    INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    // INTERRUPT_GlobalInterruptHighDisable();
//uint32_t i = 50000;
//    while (i > 0) {
//        i--;
//        Nop();
//        Nop();
//        Nop();
//        //        LED_STT1_SetHigh();
//    }
    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();
    modbus_init();
    int test;
        
//    
  RS485_EN_SetLow();  
//    UART1_Write(0x44);UART1_Write(0x44);UART1_Write(0x44);
//    UART1_Write_String("D1");
    NVMCON1bits.NVMREG = 0b10;
    
//    WWDT_SoftEnable();
        RS485_EN_SetLow();
        LATAbits.LATA4 = 0;LATAbits.LATA5 = 0;__delay_ms(1000);
        LATAbits.LATA4 = 1;LATAbits.LATA5 = 1;
//        configlora();//checklora=1;
//    while (1) {LATAbits.LATA4 ^= 1;__delay_ms(1000);}
        while(1){
//                 RS485_EN_SetHigh();
        // Reset Watch-Dog Timer
        CLRWDT();RS485_EN_SetLow();UART1_Write(0x44);UART2_Write(0x44);
//        if (RD4 == 0) LATAbits.LATA4 = 1;
        NVMCON1bits.NVMREG = 0b10; // 0b10: PFM locations write access   
//        if (ff==1) {SS_LED1_Toggle();ff=0;}
//        config_button();
//        
//        if(flag==1){ 
// 
//            for ( i=0; i<len_lora;i++)       
//            {
//                UART1_Write(rxlora[i]);
//                if (rxlora[i]!= check[i]) {break;}
//            }
//            if (i<len_lora)
//            {LATAbits.LATA5=~LATAbits.LATA5;
//            LATBbits.LATB5=0;checklora=0;}// {checklorafl=0;M1=0;}
//            c_lora=0;
//            flag=0;
//              
//
//        }
        }{     if (modbus_kbhit()) {

            if (modbus_rx.address == modbus_address) {
             RS485_EN_SetHigh() ;  
                flag_id_mb = 1; // 1: have modbus send cmd
                //      PIR6bits_t.U2RXIF = 0;
                //            LED_RTU_SetHigh();
                switch (modbus_rx.func) {
                    case FUNC_READ_COILS:
                        if (make16(modbus_rx.data[0], modbus_rx.data[1]) < 16) {
                            data_read_coil = coils >> make16(modbus_rx.data[0], modbus_rx.data[1]);

                            if (make16(modbus_rx.data[2], modbus_rx.data[3]) > 8) {
                                modbus_read_coils_rsp(modbus_address, (uint8_t) modbus_rx.data[3] / 8 + 1, &data_read_coil);

                            } else if (make16(modbus_rx.data[2], modbus_rx.data[3]) <= 8) {
                                modbus_read_coils_rsp(modbus_address, 0x01, &data_read_coil);
                            }
                        } else {
                            modbus_exception_rsp(modbus_address, modbus_rx.func, ILLEGAL_DATA_VALUE);
                        }
                        break;
                    case FUNC_READ_DISCRETE_INPUT:
                        if (make16(modbus_rx.data[0], modbus_rx.data[1]) < 8) {
                            data_read_coil = inputs >> modbus_rx.data[1];
                            if (make16(modbus_rx.data[2], modbus_rx.data[3]) > 8) {
                                modbus_read_discrete_input_rsp(modbus_address, (uint8_t) modbus_rx.data[3] / 8 + 1, &data_read_coil);

                            } else if (make16(modbus_rx.data[2], modbus_rx.data[3]) <= 8) {
                                modbus_read_discrete_input_rsp(modbus_address, 0x01, &data_read_coil);

                            }
                        } else if ((make16(modbus_rx.data[0], modbus_rx.data[1]) > 255) || (make16(modbus_rx.data[2], modbus_rx.data[3]) > 255)) {
                            modbus_exception_rsp(modbus_address, modbus_rx.func, ILLEGAL_DATA_VALUE);
                        }
                        break;
                    case FUNC_WRITE_SINGLE_COIL:
                        if (modbus_rx.data[3] > 8)
                            modbus_exception_rsp(modbus_address, modbus_rx.func, ILLEGAL_DATA_ADDRESS);
                        else if (modbus_rx.data[2] != 0xFF && modbus_rx.data[2] != 0x00)
                            modbus_exception_rsp(modbus_address, modbus_rx.func, ILLEGAL_DATA_VALUE);
                        else {
                            if (modbus_rx.data[2] == 0xFF) {
                                bit_set(coils, make16(modbus_rx.data[0], modbus_rx.data[1]));
                            } else if (modbus_rx.data[2] == 0x00) {
                                bit_clear(coils, make16(modbus_rx.data[0], modbus_rx.data[1]));
                            }
             
                            modbus_write_single_coil_rsp(modbus_address, make16(modbus_rx.data[0], modbus_rx.data[1]), ((uint16_t) (modbus_rx.data[2])) << 8);
                            events_coils_output = 1;
                        }
                        break;
                    case FUNC_WRITE_MULTIPLE_COILS:
                        if (modbus_rx.data[0] || modbus_rx.data[2] ||
                                modbus_rx.data[1] >= 8 || modbus_rx.data[3] + modbus_rx.data[1] > 8) {
                            modbus_exception_rsp(modbus_address, modbus_rx.func, ILLEGAL_DATA_ADDRESS);
                        } else {
                            int i, j;
                            for (i = modbus_rx.data[1], j = 0; i < modbus_rx.data[1] + modbus_rx.data[3]; ++i, ++j) {
                                if (bit_test(modbus_rx.data[5], j))
                                    bit_set(coils, i);
                                else
                                    bit_clear(coils, i);
                            }
                      
                            modbus_write_multiple_coils_rsp(modbus_address,
                                    make16(modbus_rx.data[0], modbus_rx.data[1]),
                                    make16(modbus_rx.data[2], modbus_rx.data[3]));
                            events_coils_output = 1;
                        }
                        break;
                    case FUNC_READ_HOLDING_REGISTERS:
                        if (make16(modbus_rx.data[2], modbus_rx.data[3]) <= 0 || make16(modbus_rx.data[2], modbus_rx.data[3]) > HOLD_SIZE)
                            modbus_exception_rsp(modbus_address, modbus_rx.func, ILLEGAL_DATA_VALUE);
                        else if (make16(modbus_rx.data[0], modbus_rx.data[1]) < START_HOLD_REGS ||
                                make16(modbus_rx.data[0], modbus_rx.data[1]) - START_HOLD_REGS + make16(modbus_rx.data[2], modbus_rx.data[3]) > HOLD_SIZE) {
                            modbus_exception_rsp(modbus_address, modbus_rx.func, ILLEGAL_DATA_ADDRESS);
                        } else {
                            modbus_read_holding_registers_rsp(modbus_address, (modbus_rx.data[3]*2), hold_regs + modbus_rx.data[1]);
                        }
                        break;
                    case FUNC_WRITE_SINGLE_REGISTER:
                        if (make16(modbus_rx.data[0], modbus_rx.data[1]) < START_HOLD_REGS || make16(modbus_rx.data[0], modbus_rx.data[1]) > START_HOLD_REGS + HOLD_SIZE)
                            modbus_exception_rsp(modbus_address, modbus_rx.func, ILLEGAL_DATA_ADDRESS);
                        else {
                            hold_regs[modbus_rx.data[1]] = make16(modbus_rx.data[2], modbus_rx.data[3]);
                            saveToEEPROM(hold_regs[modbus_rx.data[1]], modbus_rx.data[1]);
                            modbus_write_single_register_rsp(modbus_address, make16(modbus_rx.data[0], modbus_rx.data[1]), hold_regs[modbus_rx.data[1]]);
                            read_eeprom_flag = 1;
                        }
                        break;

                    case FUNC_WRITE_MULTIPLE_REGISTERS:
                        if (make16(modbus_rx.data[0], modbus_rx.data[1]) < START_HOLD_REGS || make16(modbus_rx.data[0], modbus_rx.data[1]) > START_HOLD_REGS + HOLD_SIZE) // Check start addr
                            modbus_exception_rsp(modbus_address, modbus_rx.func, ILLEGAL_DATA_ADDRESS);
                        else if (make16(modbus_rx.data[0], modbus_rx.data[1]) + make16(modbus_rx.data[2], modbus_rx.data[3]) > HOLD_SIZE) // Check start addr + quality addr
                            modbus_exception_rsp(modbus_address, modbus_rx.func, ILLEGAL_DATA_ADDRESS);
                        else {
                            uint8_t i = 0, j = 0;
                            for (i = make16(modbus_rx.data[0], modbus_rx.data[1]); i < make16(modbus_rx.data[0], modbus_rx.data[1]) + make16(modbus_rx.data[2], modbus_rx.data[3]); i++) {
                                hold_regs[i] = make16(modbus_rx.data[5 + j], modbus_rx.data[5 + j + 1]);
                                saveToEEPROM(hold_regs[i], i);
                                j = j + 2;
                            }
                            uint32_t time = 0;
                            while (time < 100) {
                                time++;
                            }
                            modbus_write_multiple_registers_rsp(modbus_address, make16(modbus_rx.data[0], modbus_rx.data[1]), make16(modbus_rx.data[2], modbus_rx.data[3])*2);
                            read_eeprom_flag = 1;
                        }
                        break;
                    case FUNC_READ_INPUT_REGISTERS:
                    default: //We don't support the function, so return exception
                        modbus_exception_rsp(modbus_address, modbus_rx.func, ILLEGAL_FUNCTION);
                }
                if (coils==1) LATAbits.LATA5=~LATAbits.LATA5;
                //            LED_RTU_SetLow();
                RS485_EN_SetLow();
            }
        }
    }
}

    void config_button()
{
    BOOL flag;
   if (PORTAbits.RA3 == 1) flag=1;
    while (flag)   if ((PORTAbits.RA3 == 0)) {configlora();checklora=1;
                        LATAbits.LATA4=~LATAbits.LATA4;flag = 0;}
}
 
    void configlora() {//LATAbits.LATA4=~LATAbits.LATA4;
    LATBbits.LATB4=0;
    LATBbits.LATB5=1;
//    LATBbits.LATB3=1;
    while(RB3==0);
//    Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();Nop();
    UART2_Write(0xc0); //comand config
    UART2_Write(0x00); //starting addr
    UART2_Write(0x09); //length
    UART2_Write(0xff); //addrh
//    UART2_Write(0xff); //err
    UART2_Write(0xff); //addrl
    UART2_Write(0x00); //netid
    UART2_Write(0x62); //reg0
    UART2_Write(0x00); //reg1
    UART2_Write(0x17); //reg2(channel) 0x2B
    UART2_Write(0x03); //reg3
    UART2_Write(0x00); //keyh
    UART2_Write(0x00); //keyl 
//    __delay_ms(10);
    }
    void setBaudRate(uint8_t br) {
        //    uint16_t i;
        //    switch (br) {
        //        case 1: //4800
        //            i = 1040;
        //            SP1BRGL = (uint8_t) (i);
        //            SP1BRGH = (uint8_t) (i >> 8);
        //            break;
        //        case 2: //9600
        //            i = 519;
        //            SP1BRGL = (uint8_t) (i);
        //            SP1BRGH = (uint8_t) (i >> 8);
        //            break;
        //        case 3: //19200
        //            i = 259;
        //            SP1BRGL = (uint8_t) (i);
        //            SP1BRGH = (uint8_t) (i >> 8);
        //            break;
        //        case 4: //38400
        //            i = 129;
        //            SP1BRGL = (uint8_t) (i);
        //            SP1BRGH = (uint8_t) (i >> 8);
        //            break;
        //        case 5: //57600
        //            i = 85;
        //            SP1BRGL = (uint8_t) (i);
        //            SP1BRGH = (uint8_t) (i >> 8);
        //            break;
        //        case 6: //115200
        //            SP1BRGL = 0x2A;
        //            SP1BRGH = 0x00;
        //            break;
        //    }
    }

    void setParity(uint8_t parity) {
    }

    void setStopBits(uint8_t stop) {
    }

    void saveToEEPROM(uint8_t data, uint8_t position) {

    }

    void loadFromEEPROM(void) {

    }

    void assignEEPROMBufferToVariables(void) {

    }

    void setDefaultRFConfig(void) {

    }

    uint8_t make8(uint16_t var, uint8_t ofset) {
        uint8_t value = 0;
        value = (uint8_t) ((var >> (8 * ofset))&0x00FF);
        return value;
    }

    uint16_t make16(uint8_t high, uint8_t low) {
        uint16_t value = 0;
        value = (((uint16_t) high << 8)&0xFF00) + low;
        return value;
    }

    /*********************************************************************
     * Function:        void Encode(unsigned long* data, unsigned char dataLength)
     *
     * PreCondition:    None
     *
     * Input:           data - array of data to be Encode (must be even length)
     *                  dataLength - length of data array (must be even)
     *                  interations - number of Feistel cycles to iterate on the data 
     *                  (min suggested is 16, 64 is standard for high security projects
     *                  highest levels cracked so far are around 10 cycles)
     *
     * Output:          None
     *
     * Side Effects:    _data values change
     *******************************************/
    void Encode(unsigned long* data, unsigned char dataLength) {

    }

    /*********************************************************************
     * Function:        void Decode(unsigned long* data, unsigned int dataLength, unsigned char iterations)
     *
     * PreCondition:    None
     *
     * Input:           data - array of data to be decoded (must be even length)
     *                  dataLength - length of data array (must be even)
     *                  interations - number of Feistel cycles to iterate on the data 
     *                  (min suggested is 16, 64 is standard for high security projects
     *                  highest levels cracked so far are around 10 cycles)
     *
     * Output:          None
     *
     * Side Effects:    _data values change
     ********************************************************************/

    void Decode(uint32_t* data, uint8_t dataLength) {

    }

    void configLoRaRFSettings(void) {

    }

    BOOL checkSetDefault(void) {

    }

    void getAM2315(void) {


    }

    void sendRequestToReadSensorData(uint8_t address, uint16_t start_address, uint16_t quantity) {

    }

    void controlRelays(void) {

    }

    void reset_lora_error() {

    }

    void set_baudrate(uint8_t br) {

    }

    void set_baudrate_uart2(uint8_t br) {

    }

    void set_parity(uint8_t parity) {

    }

    void set_stopbits(uint8_t stop) {

    }

