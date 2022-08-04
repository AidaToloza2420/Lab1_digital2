/* 
 * File:   pwm.c
 * Author: Aida Toloza
 *
 * Created on 22 de julio de 2022, 08:27 AM
 */

#include <xc.h>
#include "pwm.h"
#define _XTAL_FREQ 4000000

void pwm_init(uint8_t channel){
    TRISCbits.TRISC2 = 1;       
    TRISCbits.TRISC1 = 1;       
    PR2 = VALOR_PR2;                  
    T2CONbits.T2CKPS = 0b11;    // prescaler 1:16
    switch(channel){
        case 1:
            CCP1CON = 0;                
            CCP1CONbits.P1M = 0;        
            CCP1CONbits.CCP1M = 0b1100; 
            TRISCbits.TRISC2 = 0;
            break;
        case 2:
            CCP2CON = 0;                
            CCP2CONbits.CCP2M = 0b1100; 
            TRISCbits.TRISC1 = 0;
            break;
        default:
            break;
             
    }
    
}

void pwm_duty_cycle(uint16_t duty_cycle, uint8_t channel){
    if (duty_cycle < 1024){ //Rango 
        switch(channel){
            case 1:
                CCPR1L = duty_cycle>>2;
                CCP1CONbits.DC1B = duty_cycle & 0b11;    
                break;
            case 2:    
                CCPR2L = duty_cycle>>2;
                CCP2CONbits.DC2B0 = duty_cycle & 0b1; 
                CCP2CONbits.DC2B1 = duty_cycle>>1 & 0b1;
                break;
            default:
                break;
        }
    }
}
