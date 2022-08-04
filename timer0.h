/* 
 * File:   timer0.h
 * Author: Aida Toloza
 *
 * Created on 28 de julio de 2022, 08:54 PM
 */

#ifndef TIMER0_H
#define	TIMER0_H

#include <xc.h>
#include <stdint.h>

void tmr0_init(uint16_t prescaler);
void tmr0_reload(void);

#endif	/* TIMER0_H */

