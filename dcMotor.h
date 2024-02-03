
#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "std_types.h"
/*Motor states*/
#define STOP 0
#define CW 1
#define A_CW 2

typedef uint8 DcMotor_State;

void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DCMOTOR_H_ */
