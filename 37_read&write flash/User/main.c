#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "MyFLASH.h"

int main(void)
{
	OLED_Init();
	
	OLED_ShowHexNum(1,1,MyFLASH_ReadWord(0x08000010),8);
	OLED_ShowHexNum(2,1,MyFLASH_ReadHalfWord(0x08000010),4);
	OLED_ShowHexNum(3,1,MyFLASH_ReadByte(0x08000010),2);
	
	while (1)
	{
		
	}
}
