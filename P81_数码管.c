#include <REG52.H>
//数码管循环显示0~9
unsigned char led_mod[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x58,0x5e,0x79,0x71};
void delay(unsigned int time){
    unsigned int j=0;
    for(;time>0;time--)
        for(j=0;j<125;j++);
}
void main(void){
    char i=0;
    while(1){
        for(i=0;i<=9;i++){
            P0=led_mod[i];
            delay(500);
        }
    }
}
