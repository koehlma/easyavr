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

#ifndef TOAVR_H_
#define TOAVR_H_

#include "toavr/core.h"

#include "toavr/pins.h"
#include "toavr/serial.h"

#if defined(__AVR_ATmega2560__)
    #include "toavr/chips/atmega2560.h"
#endif
#if defined(__AVR_ATtiny2313__)
    #include "toavr/chips/attiny2313.h"
#endif
#if defined(__AVR_ATmega8__) || defined(__AVR_ATmega328__)  || defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__)
    #include "toavr/chips/atmega8.h"
#endif

#endif