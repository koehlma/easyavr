/*
 * Copyright (C) 2015, Maximilian Köhl <mail@koehlma.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#include <avr/io.h>

#include "utils.h"

#define SERIAL_BIT_TX_ENABLE		3
#define SERIAL_BIT_RX_ENABLE		4
#define SERIAL_BIT_UDR_INTERRUPT	5
#define SERIAL_BIT_TX_INTERRUPT		6
#define SERIAL_BIT_RX_INTERRUPT		7
#define SERIAL_BIT_STOP				3

#define SERIAL_MODE_ASYNC			0b00
#define SERIAL_MODE_SYNC			0b01

#define SERIAL_PARITY_DISABLED		0b00
#define SERIAL_PARITY_EVEN			0b10
#define SERIAL_PARITY_ODD			0b11

#define SERIAL_STOP_BIT_ONE			0
#define SERIAL_STOP_BIT_TWO			1

#define SERIAL_CHAR_SIZE_5			0b000
#define SERIAL_CHAR_SIZE_6			0b001
#define SERIAL_CHAR_SIZE_7			0b010
#define SERIAL_CHAR_SIZE_8			0b011
#define SERIAL_CHAR_SIZE_9			0b111

#define SERIAL_STATUS_RX_COMPLETE	0b10000000
#define SERIAL_STATUS_TX_COMPLETE	0b01000000
#define SERIAL_STATUS_UDR_EMPTY		0b00100000
#define SERIAL_STATUS_FRAME_ERROR	0b00010000
#define SERIAL_STATUS_OVERRUN		0b00001000
#define SERIAL_STATUS_PARITY_ERROR	0b00000100

template<typename Udr, typename Ucsr, typename Ubrr> struct Serial {
	static inline void begin(unsigned long baudrate, uint8_t size=SERIAL_CHAR_SIZE_8) {
		uint16_t ubrr = (((F_CPU + baudrate * 8) / (16 * baudrate)) - 1);
		Ubrr::set(ubrr);
		enable_rx();
		enable_tx();
		char_size(size);		
	}
	
	static inline uint8_t status() {
		return Ucsr::a::get();
	}
	
	static inline uint8_t mode() {
		return Ucsr::c::get() >> 6;
	}
	static inline void mode(uint8_t val) {
		Ucsr::c::set((Ucsr::get() & 0b00111111) | (val << 6));
	}
	
	static inline uint8_t parity() {
		return (Ucsr::c::get() >> 4) & 0b11;
	}
	static inline void parity(uint8_t val) {
		Ucsr::c::set((Ucsr::get() & 0b11001111) | (val << 4));
	}
	
	static inline uint8_t stop_bit() {
		return Ucsr::c::bit(SERIAL_BIT_STOP);
	}	
	static inline void stop_bit(uint8_t val) {
		Ucsr::c::bit(SERIAL_BIT_STOP, val);
	}
	
	static inline uint8_t char_size() {
		return (Ucsr::b::bit(2) << 2) | ((Ucsr::c::get() >> 1) & 0b11);
	}
	static inline void char_size(uint8_t val) {
		Ucsr::b::bit(2, (val >> 2) & 1);
		Ucsr::c::set((Ucsr::c::get() & 0b11111001) | ((val & 0b11) << 1));
	}
	
	static inline void enable_rx() {
		Ucsr::b::set_bit(SERIAL_BIT_RX_ENABLE);
	}
	static inline void enable_tx() {
		Ucsr::b::set_bit(SERIAL_BIT_TX_ENABLE);
	}
	static inline void disable_rx() {
		Ucsr::b::clear_bit(SERIAL_BIT_RX_ENABLE);
	}
	static inline void disable_tx() {
		Ucsr::b::clear_bit(SERIAL_BIT_TX_ENABLE);
	}
	
	static inline void enable_rx_interrupt() {
		Ucsr::b::set_bit(SERIAL_BIT_RX_INTERRUPT);
	}
	static inline void enable_tx_interrupt() {
		Ucsr::b::set_bit(SERIAL_BIT_TX_INTERRUPT);
	}
	static inline void enable_udr_interrupt() {
		Ucsr::b::set_bit(SERIAL_BIT_UDR_INTERRUPT);
	}	
	static inline void disable_rx_interrupt() {
		Ucsr::b::clear_bit(SERIAL_BIT_RX_INTERRUPT);
	}
	static inline void disable_tx_interrupt() {
		Ucsr::b::clear_bit(SERIAL_BIT_TX_INTERRUPT);
	}
	static inline void disable_udr_interrupt() {
		Ucsr::b::clear_bit(SERIAL_BIT_UDR_INTERRUPT);
	}
	
	static inline void put(uint8_t data) {
		Udr::set(data);
	}
	static inline void put9(uint16_t data) {
		Udr::set(data & 0xff);
		Ucsr::b::bit(0, (data >> 8));
	}
	static inline uint8_t get() {
		return Udr::get();
	}
	static inline uint16_t get9() {
		return Udr::get() | (Ucsr::b::bit(1) << 8);
	}	
};


#define MAKE_SERIAL(NUMBER)													\
	REGISTER8(Udr##NUMBER, UDR##NUMBER);									\
	struct Ucsr##NUMBER {													\
		REGISTER8(a, UCSR##NUMBER##A);										\
		REGISTER8(b, UCSR##NUMBER##B);										\
		REGISTER8(c, UCSR##NUMBER##C);										\
	};																		\
	REGISTER16(Ubrr##NUMBER, UBRR##NUMBER##H, UBRR##NUMBER##L);				\
	typedef Serial<Udr##NUMBER, Ucsr##NUMBER, Ubrr##NUMBER> Serial##NUMBER

#ifdef UDR
	#define UDR0 UDR
	#define UCSR0A UCSRA
	#define UCSR0B UCSRB
	#define UCSR0C UCSRC
	#define UBRR0H UBRRH
	#define UBRR0L UBRRL
	#define SERIAL0_RX_INTERRUPT USART_RX_vect
	#define SERIAL0_TX_INTERRUPT USART_TX_vect
#endif

#ifdef UDR0
	#ifndef SERIAL0_RX_INTERRUPT
		#define SERIAL0_RX_INTERRUPT USART0_RX_vect
		#define SERIAL0_TX_INTERRUPT USART0_TX_vect
	#endif
	MAKE_SERIAL(0);
#endif

#ifdef UDR1
	#define SERIAL1_RX_INTERRUPT USART1_RX_vect
	#define SERIAL1_TX_INTERRUPT USART1_TX_vect
	MAKE_SERIAL(1);
#endif

#ifdef UDR2
	#define SERIAL2_RX_INTERRUPT USART2_RX_vect
	#define SERIAL2_TX_INTERRUPT USART2_TX_vect
	MAKE_SERIAL(2);
#endif

#ifdef UDR3
	#define SERIAL3_RX_INTERRUPT USART3_RX_vect
	#define SERIAL3_TX_INTERRUPT USART3_TX_vect
	MAKE_SERIAL(3);
#endif

#endif