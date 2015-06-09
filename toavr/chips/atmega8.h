/*
 * Copyright (C) 2015, Maximilian Köhl <mail@koehlma.de>
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 3.0 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ATMEGA8_H_
#define ATMEGA8_H_

#include "../pins.h"

typedef Pin<PortC, 6> Pin1;
typedef Pin<PortD, 0> Pin2, ArduinoD0;
typedef Pin<PortD, 1> Pin3, ArduinoD1;
typedef Pin<PortD, 2> Pin4, ArduinoD2;
typedef Pin<PortD, 3> Pin5, ArduinoD3;
typedef Pin<PortD, 4> Pin6, ArduinoD4;
typedef Pin<PortB, 6> Pin9;
typedef Pin<PortB, 7> Pin10;
typedef Pin<PortD, 5> Pin11, ArduinoD5;
typedef Pin<PortD, 6> Pin12, ArduinoD6;
typedef Pin<PortD, 7> Pin13, ArduinoD7;
typedef Pin<PortB, 0> Pin14, ArduinoD8;
typedef Pin<PortB, 1> Pin15, ArduinoD9;
typedef Pin<PortB, 2> Pin16, ArduinoD10;
typedef Pin<PortB, 3> Pin17, ArduinoD11;
typedef Pin<PortB, 4> Pin18, ArduinoD12;
typedef Pin<PortB, 5> Pin19, ArduinoD13;
typedef Pin<PortC, 0> Pin23, ArduinoA0;
typedef Pin<PortC, 1> Pin24, ArduinoA1;
typedef Pin<PortC, 2> Pin25, ArduinoA2;
typedef Pin<PortC, 3> Pin26, ArduinoA3;
typedef Pin<PortC, 4> Pin27, ArduinoA4;
typedef Pin<PortC, 5> Pin28, ArduinoA5;

#endif