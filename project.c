#include"adc.h"
#include"dcMotor.h"
#include"lcd.h"
#include"lm35_sensor.h"
#include<util/delay.h>

int main(void)
{
	ADC_ConfigType sel = {INTERNAL,SCALE_8};
	ADC_init(&sel);
	LCD_init();
	DcMotor_Init();
	char x = 0;
	LCD_moveCursor(0,4);
	LCD_displayString("FAN IS "); /*start display in lcd 1st row*/
	LCD_moveCursor(1,4);
	LCD_displayString("TEMP = ");/*start display in lcd 2nd row*/
	while(1)
	{
		LCD_moveCursor(0,11);
		x = LM35_getTemperature();
		if(x<30)
		{
			LCD_displayString("OFF");
			DcMotor_Rotate(STOP,0);
		}
		else if((x>=30)&&(x<60))
		{
			LCD_displayString("ON ");
			DcMotor_Rotate(CW,25);
		}
		else if((x>=60)&&(x<90))
		{
			LCD_displayString("ON ");
			DcMotor_Rotate(CW,50);
		}
		else if((x>=90)&&(x<120))
		{
			LCD_displayString("ON ");
			DcMotor_Rotate(CW,75);
		}
		else if(x>=120)
		{
			LCD_displayString("ON");
			DcMotor_Rotate(CW,100);
		}
		/*DISplaying temperature on lcd*/
		LCD_moveCursor(1,11);
		if(x<100)
		{
			LCD_intgerToString((int)x);
			LCD_displayCharacter(' ');
		}
		else
		{
			LCD_intgerToString((int)x);
		}
		LCD_displayCharacter('C');

	}
}
