#include <REG52.H>
sbit P2_0=P2^0;
void main(){
    TMOD=0x10;
    TR1=1;
    for(;;){
        TH1=0xfc;
        TL1=0x18;
        while(!TF1);
        TF1=0;
        P2_0=!P2_0;
    }
}
