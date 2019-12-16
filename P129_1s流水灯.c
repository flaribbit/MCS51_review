#include <REG52.H>
typedef unsigned char u8;
u8 t=0,i=0;
u8 led[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
void timer0() interrupt 1{
    t++;
    if(t==20){
        t=0;
        P2=led[i++];
        if(i==8)i=0;
    }
    TH0=0x3c;
    TL0=0xb0;
}
main(){
    TMOD=0x01;
    TH0=0x3c;
    TL0=0xb0;
    EA=1;
    ET0=1;
    TR0=1;
    for(;;);
}
