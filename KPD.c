#include"../../MCAL/DIO/DIO_int.h"
#include<util/delay.h>
#include"../../LIB/STD_TYPES.h"
#define HKPD_PORT DIO_PORTD
#define HKPD_ColumStart 0
#define HKPD_CoulumEnd  3
#define HKPD_RowStart   4
#define HKPD_RowEnd     7
static const u8 global_Au8_SwitchVal[4][4]=
{
	{
		0x07, /* Row 0 Column 0 */
		0x04, /* Row 1 Column 0 */
		0x01, /* Row 2 Column 0 */
		0x0A  /* Row 3 Column 0 */
	},
	{
		0x08, /* Row 0 Column 1 */
		0x05, /* Row 1 Column 1 */
		0x02, /* Row 2 Column 1 */
		0x00  /* Row 4 Column 1 */
	},
	{
		0x09, /* Row 0 Column 2 */
		0x06, /* Row 1 Column 2 */
		0x03, /* Row 2 Column 2 */
		0x0B  /* Row 3 Column 2 */
	},
	{
		0x01, /* Row 0 Column 3 */
		0x05, /* Row 1 Column 3 */
		0x09, /* Row 2 Column 3 */
		0x0D  /* Row 3 Column 3 */
	}
};
HKPD_Initial()
{
	u8 u8_L_Coloum;
	u8 u8_L_Row;
	for(u8_L_Coloum=HKPD_ColumStart;u8_L_Coloum<=HKPD_CoulumEnd;u8_L_Coloum++)
	{
		DIO_vWrtPinDir(HKPD_PORT,u8_L_Coloum,DIO_OUTPUT);
		DIO_vWrtPinVal(HKPD_PORT,u8_L_Coloum,DIO_HIGH);
	}
	for(u8_L_Row=HKPD_RowStart;u8_L_Row<=HKPD_RowEnd;u8_L_Row++)
	{
		DIO_vWrtPinDir(HKPD_PORT,u8_L_Row,DIO_INPUT);
		DIO_vWrtPinVal(HKPD_PORT,u8_L_Row,DIO_HIGH);
	}
}
u8 HKPD_GetPressedKey()
{
	u8 u8_L_Coloum;
	u8 u8_L_Row;
	u8 u8_L_state;
	u8_L_state=1;
	u8 u8_L_value;
	for(u8_L_Coloum=HKPD_ColumStart;u8_L_Coloum<=HKPD_CoulumEnd;u8_L_Coloum++)
	{
		DIO_vWrtPinVal(HKPD_PORT,u8_L_Coloum,DIO_LOW);
		for(u8_L_Row=HKPD_RowStart;u8_L_Row<=HKPD_RowEnd;u8_L_Row++)
		{
			u8_L_state=DIO_u8GetPinVal(HKPD_PORT,u8_L_Row);
			if(u8_L_state==0)
			{
				u8_L_value=global_Au8_SwitchVal[u8_L_Coloum-HKPD_ColumStart][u8_L_Row-HKPD_RowStart];
				while(u8_L_state==0)
				{
					u8_L_state=DIO_u8GetPinVal(HKPD_PORT,u8_L_Row);
				}
				_delay_ms(20);
			}
		}
		DIO_vWrtPinVal(HKPD_PORT,u8_L_Coloum,DIO_HIGH);
	}

return u8_L_value;
}
