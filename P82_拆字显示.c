#include <REG52.H>
//0~99循环计数显示
sbit P3_7=P3^7;
unsigned char table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x58,0x5e,0x79,0x71};
unsigned char count;
void delay(unsigned int time){
    unsigned int j=0;
    for(;time>0;time--)
        for(j=0;j<125;j++);
}
void main(void){
    count=0;
    P0=table[count/10];
    P2=table[count%10];
    while(1){
        if(P3_7==0){
            delay(10);
            if(P3_7==0){
                count++;
                if(count==100){
                    count=0;
                }
                P0=table[count/10];
                P2=table[count%10];
                while(P3_7==0);
            }
        }
    }
}