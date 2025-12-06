#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "AD.h"

uint16_t ADvalue;
float Voltage;

int main(void)
{
	OLED_Init();
	AD_Init();

	OLED_ShowString(1,1,"ADvalue:");
	OLED_ShowString(2,1,"Voltage:0.00V");

	while(1)
	{
		ADvalue=AD_Getvalue();
		Voltage=(float)ADvalue/4095*3.3;
		OLED_ShowNum(1,9,ADvalue,4);
		OLED_ShowNum(2,9,Voltage,1);
		OLED_ShowNum(2,11,(uint16_t)(Voltage*100)%100,2);
		
		Delay_ms(100);
	}
}
