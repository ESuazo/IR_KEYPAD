#line 1 "D:/Project/Infrared Keypad/Software/Full Programs/MCU Master/MikroC_PRO_Keyboard/UNI_HID_Keyboard.c"
#line 39 "D:/Project/Infrared Keypad/Software/Full Programs/MCU Master/MikroC_PRO_Keyboard/UNI_HID_Keyboard.c"
initconfig(){

 ADCON1 = 0x0F;
 TRISA = 0X00;
 TRISB = 0X00;
 TRISC = 0X00;
 LATA = 0X00;
 LATB = 0X00;
 LATC = 0X00;

}
unsigned char buttons=0;
unsigned char readbuff[64] absolute 0x500;
unsigned char writebuff[64] absolute 0x540;
char button_pressed=0;

unsigned char modifier=0b00000000;
unsigned char reserved=0;
unsigned char keycode[6];
unsigned int contadortimer = 0;
unsigned char last_code[1];
char error;

void interrupt(){
 USB_Interrupt_Proc();
}

void main(){

 initconfig();
 error = Soft_UART_Init(&PORTA, 4, 3, 9600, 0);
 UART1_Init(9600);
 HID_Enable(readbuff,writebuff);

 while(1) {

 keycode[0] = 0;

 if(UART1_Data_Ready() == 1){
 keycode[0] = UART1_Read();
 }

 writebuff[2] = keycode[0];
 while(!HID_Write(&writebuff,8));
 writebuff[2] = 0;
 while(!HID_Write(&writebuff,8));
#line 118 "D:/Project/Infrared Keypad/Software/Full Programs/MCU Master/MikroC_PRO_Keyboard/UNI_HID_Keyboard.c"
 keycode[1] = 0;
 keycode[2] = 0;
 keycode[3] = 0;
 keycode[4] = 0;
 keycode[5] = 0;
 }
}
