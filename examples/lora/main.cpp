#include "mbed.h"
#include "bme280.txt"

///////////////////////////////////////
// Globals variables
///////////////////////////////////////

//declaraao gerais
DigitalOut led1(P1_13);
DigitalOut led2(P1_14);
InterruptIn dio0(P0_12);
DigitalIn button1(P1_11);
DigitalIn button2(P1_12);
DigitalIn button3(P0_30);

EventQueue queue;

//============= internet of turtles =============
Timer time_breathing;
Timer time_diving;
bool beathing = false;
float last_breathing_time = 0.0;
float last_diving_time = 0.0;

char float_breathing_time[10];
char float_diving_time[10];

//Timer seconds;
//================================================

#include "lora.txt"

int main(void) {
    
    
    
    ///////////////////////////////////////
    // Variables
    ///////////////////////////////////////


    
//    uint8_t big_message[] = "1234567890qwertyuiopasdfghjklzxcvbnm1234567890qwertyuiopasdfghjklzxcvbnm1234567890qwertyuiopasdfghjklzxcvbnm1234567890qwertyuiopasdfghjklzxcvbnm1234567890qwertyuiopasdfghjklzxcvbnm1234567890qwertyuiopasdfghjklzxcvbnm01234567890123456789";
//    uint8_t reset_message[] = "Reset";

    //long int time_start = seconds.read();
    //printf ("timestart=%d  leitura = %d\n",time_start,seconds.read());
    
    
    ///////////////////////////////////////
    // Configuration
    ///////////////////////////////////////
    
    
    led1=1;//----on leds---
    led2=1;

    //____Configuration bme280
    bme_init();
    
    //____Configuration Lora    
    Thread eventThread;
    eventThread.start(callback(&queue, &EventQueue::dispatch_forever));
 
    dio0.rise(queue.event(&print_packet)); //configure interrupt rotine ro recieve packet
    setup(); //configura sx1272
       
    //TESTE_COMUNICAÇAO LABRADOR
    //sx1272.writeRegister(0x0B,0x3B);
    //sx1272.writeRegister(0x18,0x10);
    //sx1272.writeRegister(0x33,0x26);
//    sx1272.writeRegister(REG_MODEM_CONFIG1,0x0D);
//    sx1272.writeRegister(REG_MODEM_CONFIG2,0xC4); 
        
    sx1272.writeRegister(REG_OP_MODE,133); //leitura continua
  //  sx1272.writeRegister(REG_IRQ_FLAGS_MASK,187);//configure interrupt mask to interrupt only when a packet receive and packet envied 
  
    led1=0;//----off leds--- 
    led2=0;
    

    
    
    ///////////////////////////////////////
    //LOOP
    ///////////////////////////////////////
    
    while(1){
        
        if (!button1){
            led2=1;
            send_data(PING);
            led2=0;
            }
        
//         if (button3 != beathing) {
//                beathing = !beathing;
//                if(button3){
//                    send_packet(DATA);
//                
//                    time_breathing.reset();
//                    time_breathing.start();
//                    
//                    time_diving.stop();
//                    last_diving_time = time_diving.read();
//                }
//                else{
//                    time_diving.reset();
//                    time_diving.start();
//                    
//                    time_breathing.stop();
//                    last_breathing_time = time_breathing.read();
//
//                }
//                
//        }
//            if (button3){
// //               send_data(DATA);
////                send_packet(big_message,sizeof(big_message));
////                send_packet(reset_message,sizeof(reset_message));
////                wait_ms(400);
        

         
        wait_ms(50);
    }

}
