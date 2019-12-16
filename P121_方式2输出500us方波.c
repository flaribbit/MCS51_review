#include <REG52.H>
sbit out=P2^0;
void timer0() interrupt 1{
    out=!out;
}
void main(){
    TMOD=0x02;
    TH0=0x06;
    TL0=0x06;
    EA=1;
    ET0=1;
    TR0=1;
    for(;;);
}
