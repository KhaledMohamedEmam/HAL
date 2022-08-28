#include"../../MCAL/DIO/DIO_int.h"
#include "../lcd/lcd_confg.h"
#include "../lcd/lcd_int.h"
#include "../lcd/lcd_priv.h"
#include"util/delay.h"
void HLCD_init()
{
	DIO_vWrtPortDir(Data_Port,0xff);
	DIO_vWrtPinDir(Rs_Port,Rs_Pin,DIO_OUTPUT);
	DIO_vWrtPinDir(Rw_Port,Rw_Pin,DIO_OUTPUT);
	DIO_vWrtPinDir(En_Port,En_Pin,DIO_OUTPUT);
	_delay_ms(30);
	HLCD_SendCommand(Cmd_Return_Home);
	_delay_ms(15);
	HLCD_SendCommand(eight_BitMode);
	_delay_ms(1);
	HLCD_SendCommand(display_on);
	_delay_ms(1);
	HLCD_SendCommand(clear_display);
	_delay_ms(2);
	HLCD_SendCommand(Entry_Mode_Set);
	_delay_ms(2);
}
void HLCD_SendCommand(u8 A_u8_command)
{
	DIO_vWrtPinVal(Rs_Port,Rs_Pin,DIO_LOW);
	DIO_vWrtPinVal(Rw_Port,Rw_Pin,DIO_LOW);
	DIO_vWrtPortVal(Data_Port,A_u8_command);
	DIO_vWrtPinVal(En_Port,En_Pin,DIO_HIGH);
	_delay_ms(1);
	DIO_vWrtPinVal(En_Port,En_Pin,DIO_LOW);


}
void HLCDSendData(u8 A_u8_data)
{
	    DIO_vWrtPinVal(Rs_Port,Rs_Pin,DIO_HIGH);
		DIO_vWrtPinVal(Rw_Port,Rw_Pin,DIO_LOW);
		DIO_vWrtPortVal(Data_Port,A_u8_data);
		DIO_vWrtPinVal(En_Port,En_Pin,DIO_HIGH);
		_delay_ms(1);
		DIO_vWrtPinVal(En_Port,En_Pin,DIO_LOW);

}
void HLCD_SendString(u8 *ptr_string)
{
u8 L_CounterR=0;

while(ptr_string[L_CounterR]!='\0')
{
	HLCDSendData(ptr_string[L_CounterR]);
	L_CounterR++;
}

}
void Lcd_SendInt(u16 value)
{
	if(value!=0)
	{
		Lcd_SendInt(value/10);
		HLCDSendData((value%10)+'0');
	}
}
void HLCD_vGoToRowCol(u8 A_u8Row, u8 A_u8Col) {
	u8 L_u8Address;
	switch(A_u8Row) {
		case 0:
			L_u8Address = A_u8Col + 0x00;
			break;
		case 1:
			L_u8Address = A_u8Col + 0x40;
			break;
	}

	HLCD_SendCommand(L_u8Address | 0b10000000);
}
