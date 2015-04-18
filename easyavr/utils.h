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

#ifndef UTILS_H_
#define UTILS_H_

#include <inttypes.h>

#define set_bit(var, bit) ((var) |= (1UL << (bit)))
#define clear_bit(var, bit) ((var) &= ~(1UL << (bit)))
#define read_bit(var, bit) (((var) >> (bit)) & 1)
#define write_bit(var, bit, val) ((val) ? set_bit(var, bit) : clear_bit(var, bit))

#define enable_interrupts() sei()
#define disable_interrupts() cli()

#define low_byte(val) ((uint8_t) ((val) & 0xff))
#define high_byte(val) ((uint8_t) ((val) >> 8))

#define nop() __asm__ __volatile__ ("nop")

#define REGISTER8(NAME, REG) struct NAME {						\
	static inline uint8_t get() { return REG; }					\
	static inline uint8_t get_low() { return REG; }				\
	static inline uint8_t get_high() { return 0; }				\
																\
	static inline void set(uint8_t val) { REG = val; }			\
	static inline void set_low(uint8_t val) { REG = val; }		\
	static inline void set_high(uint8_t val) { }				\
}
#define REGISTER16(NAME, REG_LOW, REG_HIGH) struct NAME {							\
	static inline uint16_t get() { return (REG_HIGH << 8) | REG_LOW; }				\
	static inline uint8_t get_low() { return REG_LOW; }								\
	static inline uint8_t get_high() { return REG_HIGH; }							\
																					\
	static inline void set(uint16_t val) { REG_HIGH = val >> 8; REG_LOW = val; }	\
	static inline void set(uint8_t val) { REG_LOW = val; }							\
	static inline void set_low(uint8_t val) { REG_LOW = val; }						\
	static inline void set_high(uint8_t val) { REG_HIGH = val; }					\
}
#define REGISTER REGISTER8

struct NULL_REGISTER {
	static inline uint8_t get() { return 0; }
	static inline uint8_t get_low() { return 0; }
	static inline uint8_t get_high() { return 0; }
	
	static inline void set(uint8_t val) { }
	static inline void set_low(uint8_t val) { }
	static inline void set_high(uint8_t val) { }
};

#define INLINE_CALLABLE(NAME, CODE) struct NAME {	\
	static inline void call() { CODE; }				\
}

INLINE_CALLABLE(NULL_CALLABLE, {});

#ifdef __AVR_ATmega2560__
	#include "chips/atmega2560.h"
#endif

#endif