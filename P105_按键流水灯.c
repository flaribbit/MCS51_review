#include <REG52.H>
char led[]={0xfe,0xfd,0xfb,0xf7};
bit dir=0,run=0;
void delay(unsigned int time){
    unsigned char j=0;
    for(;time;time--)
        for(j=0;j<125;j++);
}
void key() interrupt 0{
    switch(P0&0x0f){
        case 0x0e:run=1;break;
        case 0x0d:run=0;dir=0;break;
        case 0x0b:dir=1;break;
        case 0x07:dir=0;break;
    }
}
void main(){
    unsigned char i;
    IT0=EX0=EA=1;
    for(;;){
        if(run){
            if(dir){
                for(i=0;i<=3;i++){
                    P2=led[i];
                    delay(200);
                }
            }else{
                for(i=3;i>=0;i--){
                    P2=led[i];
                    delay(200);
                }
            }
        }else{
            P2=0xff;
        }
    }
}
