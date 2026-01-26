#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);

}

uint8_t Key_GetNum(void)//“按键数字获取”函数，返回值为无符号整形
{
	uint8_t KeyNum =0;//初始值为0
    if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) == 0)//按下1号按键
	{
		Delay_ms(20);//延迟消抖
		while (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1==0))//如不松手一直卡在这里
		Delay_ms(20);
		KeyNum=1;//返回值为1
	}
	
	  if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11) == 0)//按下11号按键
	{
		Delay_ms(20);//延迟消抖
		while (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11==0))//如不松手一直卡在这里
		Delay_ms(20);
		KeyNum=2;//返回值为2
	}
	
		return KeyNum;//得到返回值，默认为0，按1号按键为1，2号为2
}
