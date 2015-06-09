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

#ifndef CORE_H_
#define CORE_H_

#include <inttypes.h>

#define enable_interrupts() sei()
#define disable_interrupts() cli()

#define low_byte(val) ((uint8_t) ((val) & 0xff))
#define high_byte(val) ((uint8_t) ((val) >> 8))

#define nop() __asm__ __volatile__ ("nop")

#define REGISTER8(NAME, REG) struct NAME {                              \
    static inline uint8_t get() { return REG; }                         \
    static inline uint8_t get_low() { return REG; }                     \
    static inline uint8_t get_high() { return 0; }                      \
                                                                        \
    static inline void set(uint8_t val) { REG = val; }                  \
    static inline void set_low(uint8_t val) { REG = val; }              \
    static inline void set_high(uint8_t val) { }                        \
                                                                        \
    static inline void set_bit(uint8_t bit)    { REG |= 1 << bit; }     \
    static inline void clear_bit(uint8_t bit) { REG &= ~(1 << bit); }   \
    static inline void toggle_bit(uint8_t bit) { REG ^= (1 << bit); }   \
                                                                        \
    static inline uint8_t bit(uint8_t bit) { return (REG >> bit) & 1; } \
    static inline void bit(uint8_t bit, uint8_t val) {                  \
        if (val) { set_bit(bit); }                                      \
        else { clear_bit(bit); }                                        \
    }                                                                   \
}

#define REGISTER16(NAME, REG_HIGH, REG_LOW) struct NAME {               \
    static inline uint16_t get() { return (REG_HIGH << 8) | REG_LOW; }  \
    static inline uint8_t get_low() { return REG_LOW; }                 \
    static inline uint8_t get_high() { return REG_HIGH; }               \
                                                                        \
    static inline void set(uint16_t val) {                              \
        REG_HIGH = val >> 8; REG_LOW = val;                             \
    }                                                                   \
    static inline void set(uint8_t val) { set((uint16_t) val); }        \
    static inline void set_low(uint8_t val) { REG_LOW = val; }          \
    static inline void set_high(uint8_t val) { REG_HIGH = val; }        \
                                                                        \
    static inline void set_bit(uint8_t bit)    {                        \
        if (bit > 7) { REG_HIGH |= 1 << (bit - 8); }                    \
        else { REG_LOW |= 1 << bit; }                                   \
    }                                                                   \
    static inline void clear_bit(uint8_t bit) {                         \
        if (bit > 7) { REG_HIGH &= ~(1 << (bit - 8)); }                 \
        else { REG_LOW &= ~(1 << bit); }                                \
    }                                                                   \
    static inline void toggle_bit(uint8_t bit) {                        \
        if (bit > 7) { REG_HIGH ^= 1 << (bit - 8); }                    \
        else { REG_LOW ^= 1 << bit; }                                   \
    }                                                                   \
                                                                        \
    static inline uint8_t bit(uint8_t bit) {                            \
        if (bit > 7) { return (REG_HIGH >> (bit - 8)) & 1; }            \
        else { return (REG_LOW >> bit) & 1; }                           \
    }                                                                   \
    static inline void bit(uint8_t bit, uint8_t val) {                  \
        if (val) { set_bit(bit); }                                      \
        else { clear_bit(bit); }                                        \
    }                                                                   \
}

#define REGISTER REGISTER8

struct NULL_REGISTER {
    static inline uint8_t get() { return 0; }
    static inline uint8_t get_low() { return 0; }
    static inline uint8_t get_high() { return 0; }
    
    static inline void set(uint8_t val) { }
    static inline void set_low(uint8_t val) { }
    static inline void set_high(uint8_t val) { }
        
    static inline void set_bit(uint8_t bit)    { }
    static inline void clear_bit(uint8_t bit) { }
    static inline void toggle_bit(uint8_t bit) { }
    
    static inline uint8_t bit(uint8_t bit) { return 0; }
    static inline void bit(uint8_t bit, uint8_t val) { }
};

#define MAKE_INLINE_CALLABLE(NAME, CODE) struct NAME {  \
    static inline void call() { CODE; }                 \
}

MAKE_INLINE_CALLABLE(NULL_CALLABLE, {});

#endif