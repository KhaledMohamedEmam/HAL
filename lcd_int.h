
void HLCD_init();
void HLCD_SendCommand(u8 A_u8_command);
void HLCDSendData(u8 A_u8_data);
void HLCD_SendString(u8 *ptr_string);
void Lcd_SendInt(u16 value);
void timer0_FPWMInit();
void HLCD_vGoToRowCol(u8 A_u8Row, u8 A_u8Col);


