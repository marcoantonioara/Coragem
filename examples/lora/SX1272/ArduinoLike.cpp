// added by C.Dupaty
// for Arduino compatibility
#include "mbed.h"

unsigned long micros(void)
{
     return us_ticker_read();
}

unsigned long millis(void)
{
    return micros()/1000;
} 