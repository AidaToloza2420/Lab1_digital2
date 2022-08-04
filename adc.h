/* 
 * File:   adc.h
 * Author: Aida Toloza
 *
 * Created on 22 de julio de 2022, 08:49 AM
 */

#ifndef ADC_H
#define	ADC_H

#include <xc.h>
#include <stdint.h>

void adc_init(uint8_t adc_cs, uint8_t vref_plus, uint8_t vref_minus);
void adc_start(uint8_t channel);
int adc_read(void);

#endif	/* ADC_H */

