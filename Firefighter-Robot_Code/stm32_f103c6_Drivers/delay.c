/*
 * delay.c
 *
 *  Created on: 20/2/2023
 *  Author: Salama mohamed
 */

#include "delay.h"


void delay_ms(int ms)
{
	// timer2 work at 8 MHZ set psc 7999 ( each increment take 1ms )
	TIM1->PSC=7999;
	// timer count at ms-1
	TIM1->ARR=ms-1;
	// enable counter
	TIM1->CR1 |=1<<0;
	// wait until counter reached compared register

	while(!(TIM1->SR & 1<<0));
	// clear flag
	TIM1->SR=0;
	// disable counter
	TIM1->CR1 =0;
	TIM1->CNT=0;
}

void delay_us(int us)
{
	// timer2 work at 8 MHZ set psc 7999 ( each increment take 1us )
	TIM1->PSC=7;
	// timer count at us-1
	TIM1->ARR=us-1;
	// enable counter
	TIM1->CR1 |=1<<0;
	// wait until counter reached compared register
	while(!(TIM1->SR & 1<<0));
	// clear flag
	TIM1->SR=0;
	// disable counter
	TIM1->CR1 |=0;
}
