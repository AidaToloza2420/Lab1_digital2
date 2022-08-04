/* 
 * File:   adc.c
 * Author: Aida Toloza
 *
 * Created on 22 de julio de 2022, 08:27 AM
 */

#include <xc.h>
#include "adc.h"
#define _XTAL_FREQ 4000000

void adc_init(uint8_t adc_cs, uint8_t vref_plus, uint8_t vref_minus){
    // Configuración ADC
    switch(adc_cs){
        case 0:
            ADCON0bits.ADCS = 0b00;     // Fosc/2
            break;
        case 1:
            ADCON0bits.ADCS = 0b01;     // Fosc/8
            break;
        case 2:
            ADCON0bits.ADCS = 0b10;     // Fosc/32
            break;
        case 3:
            ADCON0bits.ADCS = 0b11;     // Frc
            break;
        default:
            break;
    }
    ADCON1bits.VCFG0 = vref_plus;       // VDD
    ADCON1bits.VCFG1 = vref_minus;       // VSS
    ADCON0bits.CHS = 0b0000;    // Seleccionamos el AN0
    ADCON1bits.ADFM = 0;        // Justificado a la izquierda
    ADCON0bits.ADON = 1;        
    __delay_us(40);             
}

void adc_start(uint8_t channel){ // Configuración canal
    
    if(channel < 14){
        ADCON0bits.CHS = channel;
    }
    else{
        ADCON0bits.CHS = 0; 
    }
    __delay_us(40);             
    ADCON0bits.GO_nDONE = 1;
    while (ADCON0bits.GO){}
}
int adc_read(void){
    PIR1bits.ADIF = 0;          
    return (ADRESH);            
}
