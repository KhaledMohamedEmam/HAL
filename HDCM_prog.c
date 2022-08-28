#include "HDCM_int.h"
#include "HDCM_confg.h"
#include "../../MCAL/DIO/DIO_int.h"
void HDCM_Init()
{
	DIO_vWrtPinDir(ForwardT1_Port,ForwardT1_Pin,DIO_OUTPUT);
	DIO_vWrtPinDir(ReverseT2_Port,ReverseT2_Pin,DIO_OUTPUT);
	DIO_vWrtPinDir(ForwardT3_Port,ForwardT3_Pin,DIO_OUTPUT);
	DIO_vWrtPinDir(ReverseT4_Port,ReverseT4_Pin,DIO_OUTPUT);

}
void HDCM_Forward()
{
	DIO_vWrtPinVal(ReverseT2_Port,ReverseT2_Pin,DIO_LOW);
	DIO_vWrtPinVal(ReverseT4_Port,ReverseT4_Pin,DIO_LOW);
	DIO_vWrtPinVal(ForwardT1_Port,ForwardT1_Pin,DIO_HIGH);
	DIO_vWrtPinVal(ForwardT3_Port,ForwardT3_Pin,DIO_HIGH);
}
void HDCM_Reverse()
{
	DIO_vWrtPinVal(ForwardT1_Port,ForwardT1_Pin,DIO_LOW);
	DIO_vWrtPinVal(ForwardT3_Port,ForwardT3_Pin,DIO_LOW);
	DIO_vWrtPinVal(ReverseT2_Port,ReverseT2_Pin,DIO_HIGH);
	DIO_vWrtPinVal(ReverseT4_Port,ReverseT4_Pin,DIO_HIGH);
}

