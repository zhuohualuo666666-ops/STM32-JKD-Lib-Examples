#include "stm32f10x.h"                  // Device header

void LED_init(void)
{
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_1 | GPIO_Pin_2);
}


void LED1_ON(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);//PA1设置为低电平，点亮1号LED
}


void LED1_OFF(void)
{
    GPIO_SetBits(GPIOA,GPIO_Pin_1);//PA1设置为高电平，熄灭1号LED
}

void LED2_ON(void)
{
    GPIO_ResetBits(GPIOA,GPIO_Pin_2);//PA2设置为低电平，点亮2号LED
}


void LED2_OFF(void)
{
    GPIO_SetBits(GPIOA,GPIO_Pin_2);//PA2设置为高电平，熄灭2号LED
}

void LED1_Turn(void)//LED1电平反转函数
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1)==0)//当PA1输出为低电平时
{
    GPIO_SetBits(GPIOA,GPIO_Pin_1);//PA1引脚置高电平
}
    else
{
    GPIO_ResetBits(GPIOA,GPIO_Pin_1);//当PA1输出为高电平时，PA1引脚置低电平
}
}

void LED2_Turn(void)//LED2电平反转函数
{
    if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_2)==0)//当PA2输出为低电平时
{
    GPIO_SetBits(GPIOA,GPIO_Pin_2);//PA2引脚置高电平
}
    else
{
    GPIO_ResetBits(GPIOA,GPIO_Pin_2);//当PA1输出为高电平时，PA1引脚置低电平
}
}
