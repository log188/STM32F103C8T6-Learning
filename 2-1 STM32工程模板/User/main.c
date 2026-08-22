#include "stm32f10x.h"                  // Device header

int main(void)
{
	//寄存器点灯
	//RCC->APB2ENR = 0x00000010;
	//GPIOC->CRH = 0x00300000;
	//GPIOC->ODR = 0x00002000;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_InitTypeDef GPIO_Initstructure;                     //端口模式
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Initstructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_Initstructure);
	GPIO_SetBits(GPIOC,GPIO_Pin_13);                        //高电平
	//GPIO_ResetBits(GPIOC,GPIO_Pin_13);                      //低电平
	while (1)
	{
			
	}
}
