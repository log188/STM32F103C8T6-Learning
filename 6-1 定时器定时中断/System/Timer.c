#include "stm32f10x.h"                  // Device header

void Timer_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);
	
	TIM_InternalClockConfig(TIM2);                                       //时基单元由内部时钟驱动
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;                   //配置时基单元
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;          //1分频
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;      //向上计数
	TIM_TimeBaseInitStructure.TIM_Period = 10000 - 1;                    //周期
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7200 - 1;                  //预分频的值
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;                 //重复计数器的值（高级定时器才有） 
	TIM_TimeBaseInit(TIM2 , &TIM_TimeBaseInitStructure);
	
	TIM_ClearFlag(TIM2 , TIM_FLAG_Update);                                //防止初始化完就进中断的问题,即复位Num就从1开始计数
	TIM_ITConfig(TIM2 , TIM_IT_Update , ENABLE);                          //使能中断（更新中断到NVIC的通路）

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);                       //分组
	
	NVIC_InitTypeDef NVIC_InitStructure;                                   
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;                       //中断通道
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                       
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;             
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM2 , ENABLE);                                               //启动定时器
}

//中断函数
/*
void TIM2_IRQHandler (void)
{
	if (TIM_GetITStatus(TIM2 , TIM_IT_Update) == SET)
	{
		TIM_ClearITPendingBit (TIM2 , TIM_IT_Update);
	}
}
*/












