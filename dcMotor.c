#include "gpio.h"
#include "pwm.h"
#include"dcMotor.h"

void DcMotor_Init(void)
{
	/*
	 *1. The Function responsible for setup the direction
	 * for the two motor pins through the GPIO driver.
	 *
	 *2.Stop at the DC-Motor at the beginning through the GPIO driver.
	 *
	 * */
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);
	GPIO_writePin(PORTB_ID, PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN1_ID,LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	if(state == STOP)
	{
		GPIO_writePin(PORTB_ID, PIN0_ID,LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID,LOGIC_LOW);
	}

	else if(state == A_CW)
	{
		GPIO_writePin(PORTB_ID, PIN0_ID,LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID,LOGIC_HIGH);
	}

	else if(state == CW)
	{
		GPIO_writePin(PORTB_ID, PIN0_ID,LOGIC_HIGH);
		GPIO_writePin(PORTB_ID, PIN1_ID,LOGIC_LOW);
	}
	/*speed Controlling*/
	PWM_Timer0_Start(speed);

}

