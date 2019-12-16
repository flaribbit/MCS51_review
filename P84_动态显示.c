#include <REG52.H>
//数码管动态显示"L2"
unsigned char led_mod[]={0x38,0x5b};//LED字模"L2"
void delay(unsigned int time){
    unsigned int j=0;
    for(;time>0;time--)
        for(j=0;j<125;j++);
}
void main(void){
    char led_point=0;
    while(1){
        P3=2-led_point;
        P2=led_mod[led_point];
        led_point=1-led_point;
        delay(30);
    }
}
