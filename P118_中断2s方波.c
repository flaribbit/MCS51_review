#include <REG52.H>
sbit P2_0=P2^0;
void timer1() interrupt 3{
    P2_0=!P2_0;
    TH1=0xfc;
    TL1=0x18;
}
main(){
    TMOD=0x10;
    TH1=0xfc;
    TL1=0x18;
    EA=1;
    ET1=1;
    TR1=1;
    for(;;);
}
