# Example

```c++
#define F_CPU 16000000UL

#include <avr/interrupt.h>

#include "easyavr.h"

volatile uint8_t byte = 0;

ISR(SERIAL_RX_INTERRUPT) {
	byte = Serial0::get();
}

int main(void) {	
	Serial::begin(115200UL);
	Serial::enable_rx_interrupt();
	
	ArduinoD13::output();
	ArduinoD13::high();
	
	enable_interrupts();
	
    while(1) {
        while (!(Serial::udr_empty())) { };
		Serial::put(byte);
    }
}
```
