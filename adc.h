#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   (2.56)
/*Voltage Reference Selection*/
#define AREF 0
#define AVCC 1
#define RESERVED 2
#define INTERNAL 3
/*ADC Prescaler Selections*/
#define SCALE_2 1
#define SCALE_4 2
#define SCALE_8 3
#define SCALE_16 4
#define SCALE_32 5
#define SCALE_64 6
#define SCALE_128 7
typedef uint8 ADC_ReferenceVolatge ;
typedef uint8 ADC_Prescaler ;
typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr );

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
