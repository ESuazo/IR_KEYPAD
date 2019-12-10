#line 1 "G:/Project/Teclado numerico/Software/Full Programs/MCU Salve/MCU Slave.c"

initconfig(){
 OSCCON = 114;
 ANSELA = 0X2E;
 ANSELB = 0X3F;
 ANSELC = 0XFC;
 ANSELE = 0X07;
 TRISA = 0X2E;
 TRISB = 0X3F;
 TRISC = 0XFC;
 TRISD = 0X01;
 TRISE = 0X07;
 LATA = 0X00;
 LATB = 0X00;
 LATC = 0X00;
 LATD = 0X00;
 LATE = 0X00;
}

short counter = 1;
float percent = 0.5;
int adc_average[4];
int sensibility_percent[21];
short keycode[21] = {0,0x59,0x5A,0x5B,0x57,0x56,0x5C,0x5D,0x5E,0x55,0x46,0x5F,0x60,0x61,0x52,0x58,0x2A,0x62,0x50,0x51,0x4F};


void function(){
 LATD.B5 = 1;
 delay_ms(2);
 for(counter = 1; counter <= 5; counter++){
 adc_average[0] += Adc_Read(counter);
 }
 adc_average[0] = adc_average[0] / 5;
 adc_average[0] = adc_average[0] * percent;
 delay_ms(2);
 LATD.B5 = 0;
 delay_ms(2);

 LATD.B4 = 1;
 delay_ms(2);
 for(counter = 6; counter <= 10; counter++){
 adc_average[1] += Adc_Read(counter);
 }
 adc_average[1] = adc_average[1] / 5;
 adc_average[1] = adc_average[1] * percent;
 delay_ms(2);
 LATD.B4 = 0;
 delay_ms(2);

 LATD.B3 = 1;
 delay_ms(2);
 for(counter = 11; counter <= 15; counter++){
 adc_average[2] += Adc_Read(counter);
 }
 adc_average[2] = adc_average[2] / 5;
 adc_average[2] = adc_average[2] * percent;
 delay_ms(2);
 LATD.B3 = 0;
 delay_ms(2);

 LATD.B2 = 1;
 delay_ms(2);
 for(counter = 16; counter <= 20; counter++){
 adc_average[3] += Adc_Read(counter);
 }
 adc_average[3] = adc_average[3] / 5;
 adc_average[3] = adc_average[3] * percent;
 delay_ms(2);
 LATD.B2 = 0;
 delay_ms(2);
}

void average_table_G1(){
 LATD.B5 = 1;
 delay_ms(1);
 for(counter = 1; counter <= 5; counter++){
 if(Adc_Read(counter) < adc_average[0]){
 if(UART2_Tx_idle() == 1){
 UART2_Write(keycode[counter]);
 }
 delay_us(5500);
 }
 }
 delay_ms(1);
 LATD.B5 = 0;
 delay_ms(1);
}

void average_table_G2(){
 LATD.B4 = 1;
 delay_ms(1);
 for(counter = 6; counter <= 10; counter++){
 if(Adc_Read(counter) < adc_average[1]){
 if(UART2_Tx_idle() == 1){
 UART2_Write(keycode[counter]);
 }
 delay_us(5500);
 }
 }
 delay_ms(1);
 LATD.B4 = 0;
 delay_ms(1);
}

void average_table_G3(){
 LATD.B3 = 1;
 delay_ms(1);
 for(counter = 11; counter <= 15; counter++){
 if(Adc_Read(counter) < adc_average[2]){
 if(UART2_Tx_idle() == 1){
 UART2_Write(keycode[counter]);
 }
 delay_us(5500);
 }
 }
 delay_ms(1);
 LATD.B3 = 0;
 delay_ms(1);
}

void average_table_G4(){
 LATD.B2 = 1;
 delay_ms(1);
 for(counter = 16; counter <= 20; counter++){
 if(Adc_Read(counter) < adc_average[1]){
 if(UART2_Tx_idle() == 1){
 UART2_Write(keycode[counter]);
 }
 delay_us(5500);
 }
 }
 delay_ms(1);
 LATD.B2 = 0;
 delay_ms(1);
}

void main(){
 initconfig();
 Adc_Init();
 UART2_Init(9600);
 function();
 delay_ms(500);

 while(1){
 average_table_G1();
 average_table_G2();
 average_table_G3();
 average_table_G4();
 }
}
