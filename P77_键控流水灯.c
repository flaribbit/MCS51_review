#include <REG52.H>
//键控流水灯
//P0.0运行 P0.1停止
//P0.2正向 P0.3反向
unsigned char led[]={0xfe,0xfd,0xfb,0xf7};
void delay(unsigned char time){
    unsigned int j=15000;
    for(;time>0;time--)
        for(;j>0;j--);
}
void main(void){
    bit dir=0,run=0;
    char i;
    while(1){
        switch(P0&0x0f){
            case 0x0e:run=1;break;
            case 0x0d:run=0;break;
            case 0x0b:dir=1;break;
            case 0x07:dir=0;break;
        }
        if(run)
            if(dir)
                for(i=0;i<=3;i++){
                    P2=led[i];
                    delay(200);
                }
            else
                for(i=3;i>=0;i--){
                    P2=led[i];
                    delay(200);
                }
        else P2=0xff;
    }
}
