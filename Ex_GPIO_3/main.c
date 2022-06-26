/*
******************************************************************************
Nome: Pedro de Oliveira Trento
Turma: 4324
Professor: marcos Zuccoloto
Atividade: Exercícios de GPIO
Número: 3
******************************************************************************
*/

/* Includes */
#include "stm32f4xx.h"
uint8_t contagem;
const uint8_t mascara = 0b0111;
const uint8_t cores_led[8]=
{
		0b0000, //apagado
		0b0001, //azul - PC0
		0b0010, //verde - PC1
		0b0011, //ciano - PC0 e PC1
		0b0100, //vermelho - PC2
		0b0101, //magenta - PC0 e PC2
		0b0110, //amarelo - PC1 e PC2
		0b0111 //branco 0 PC0, PC1 e PC2

};

int main(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN;

	GPIOC->MODER&=~(GPIO_MODER_MODER2 | GPIO_MODER_MODER1 | GPIO_MODER_MODER0);
	GPIOC->MODER|=GPIO_MODER_MODER2_0 | GPIO_MODER_MODER1_0 | GPIO_MODER_MODER0_0;

	GPIOB->MODER&=~(GPIO_MODER_MODER2 | GPIO_MODER_MODER1 | GPIO_MODER_MODER0);
	GPIOB->PUPDR&=~(GPIO_PUPDR_PUPDR2 | GPIO_PUPDR_PUPDR1 | GPIO_PUPDR_PUPDR0);
	GPIOB->PUPDR|=GPIO_PUPDR_PUPDR2_1 | GPIO_PUPDR_PUPDR1_1 | GPIO_PUPDR_PUPDR0_1;


  while (1)
  {
	contagem=GPIOB->IDR&mascara;
	GPIOC->ODR=~cores_led[contagem];
  }
}
