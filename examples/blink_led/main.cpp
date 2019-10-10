#include "mbed.h"

DigitalOut led1(P1_13);

int main(){
    led1 = 0;
    
    while (true){
        led1=!led1;
        wait_ms(500);
    }
}
