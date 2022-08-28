#include"STPM_confg.h"
#include"STPM_priv.h"
#include"STPM_int.h"
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"util/delay.h"
void HSTPM_Init()
{
	DIO_vWrtPinDir(STPM_c1_Port,STPM_c1_Pin,DIO_OUTPUT);
	DIO_vWrtPinDir(STPM_c2_Port,STPM_c2_Pin,DIO_OUTPUT);
	DIO_vWrtPinDir(STPM_c3_Port,STPM_c3_Pin,DIO_OUTPUT);
	DIO_vWrtPinDir(STPM_c4_Port,STPM_c4_Pin,DIO_OUTPUT);
	DIO_vWrtPinVal(STPM_c1_Port,STPM_c1_Pin,DIO_HIGH);
	DIO_vWrtPinVal(STPM_c2_Port,STPM_c2_Pin,DIO_HIGH);
	DIO_vWrtPinVal(STPM_c3_Port,STPM_c3_Pin,DIO_HIGH);
	DIO_vWrtPinVal(STPM_c4_Port,STPM_c4_Pin,DIO_HIGH);

}
void HSTPM_ClockWise(u16 A_u16_Angle)
{
	u16 u16_IterationsCounter;
	u16_IterationsCounter=(A_u16_Angle/(StrideAngle*2*NoPhases))+1;
	 DIO_vWrtPinVal(STPM_c1_Port,STPM_c1_Pin,DIO_LOW);
		 DIO_vWrtPinVal(STPM_c2_Port,STPM_c2_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c3_Port,STPM_c3_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c4_Port,STPM_c4_Pin,DIO_HIGH);
		 _delay_ms(10);
	 u16_IterationsCounter=(A_u16_Angle/StrideAngle*2*NoPhases)+1;
	 for(int i=0;i<=u16_IterationsCounter;i++)
	 {

		 DIO_vWrtPinVal(STPM_c1_Port,STPM_c1_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c2_Port,STPM_c2_Pin,DIO_LOW);
		 DIO_vWrtPinVal(STPM_c3_Port,STPM_c3_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c4_Port,STPM_c4_Pin,DIO_HIGH);
		 _delay_ms(10);
		 DIO_vWrtPinVal(STPM_c1_Port,STPM_c1_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c2_Port,STPM_c2_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c3_Port,STPM_c3_Pin,DIO_LOW);
		 DIO_vWrtPinVal(STPM_c4_Port,STPM_c4_Pin,DIO_HIGH);
		 _delay_ms(10);
		 DIO_vWrtPinVal(STPM_c1_Port,STPM_c1_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c2_Port,STPM_c2_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c3_Port,STPM_c3_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c4_Port,STPM_c4_Pin,DIO_LOW);
		 _delay_ms(10);
		 DIO_vWrtPinVal(STPM_c1_Port,STPM_c1_Pin,DIO_LOW);
		 DIO_vWrtPinVal(STPM_c2_Port,STPM_c2_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c3_Port,STPM_c3_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c4_Port,STPM_c4_Pin,DIO_HIGH);
		 _delay_ms(10);


	 }

}
void HSTPM_CounterClockWise(u16 A_u16_Angle)
{
	u16 u16_IterationsCounter;
	u16_IterationsCounter=(A_u16_Angle/(StrideAngle*2*NoPhases))+1;
	 DIO_vWrtPinVal(STPM_c1_Port,STPM_c1_Pin,DIO_LOW);
		 DIO_vWrtPinVal(STPM_c2_Port,STPM_c2_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c3_Port,STPM_c3_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c4_Port,STPM_c4_Pin,DIO_HIGH);
		 _delay_ms(10);
	 u16_IterationsCounter=(A_u16_Angle/StrideAngle*2*NoPhases)+1;
	 for(int i=0;i<=u16_IterationsCounter;i++)
	 {

		 DIO_vWrtPinVal(STPM_c1_Port,STPM_c1_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c2_Port,STPM_c2_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c3_Port,STPM_c3_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c4_Port,STPM_c4_Pin,DIO_LOW);
		 _delay_ms(10);
		 DIO_vWrtPinVal(STPM_c1_Port,STPM_c1_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c2_Port,STPM_c2_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c3_Port,STPM_c3_Pin,DIO_LOW);
		 DIO_vWrtPinVal(STPM_c4_Port,STPM_c4_Pin,DIO_HIGH);
		 _delay_ms(10);
		 DIO_vWrtPinVal(STPM_c1_Port,STPM_c1_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c2_Port,STPM_c2_Pin,DIO_LOW);
		 DIO_vWrtPinVal(STPM_c3_Port,STPM_c3_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c4_Port,STPM_c4_Pin,DIO_HIGH);
		 _delay_ms(10);
		 DIO_vWrtPinVal(STPM_c1_Port,STPM_c1_Pin,DIO_LOW);
		 DIO_vWrtPinVal(STPM_c2_Port,STPM_c2_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c3_Port,STPM_c3_Pin,DIO_HIGH);
		 DIO_vWrtPinVal(STPM_c4_Port,STPM_c4_Pin,DIO_HIGH);
		 _delay_ms(10);


	 }
}
