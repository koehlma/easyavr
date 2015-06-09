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

#ifndef ATMEGA2560_H_
#define ATMEGA2560_H_

#include "../pins.h"

typedef Pin<PortG, 5> Pin1, ArduinoD4;
typedef Pin<PortE, 0> Pin2, ArduinoD0;
typedef Pin<PortE, 1> Pin3, ArduinoD1;
typedef Pin<PortE, 2> Pin4;
typedef Pin<PortE, 3> Pin5, ArduinoD5;
typedef Pin<PortE, 4> Pin6, ArduinoD2;
typedef Pin<PortE, 5> Pin7, ArduinoD3;
typedef Pin<PortE, 6> Pin8;
typedef Pin<PortE, 7> Pin9;
typedef Pin<PortH, 0> Pin12, ArduinoD17;
typedef Pin<PortH, 1> Pin13, ArduinoD16;
typedef Pin<PortH, 2> Pin14;
typedef Pin<PortH, 3> Pin15, ArduinoD6;
typedef Pin<PortH, 4> Pin16, ArduinoD7;
typedef Pin<PortH, 5> Pin17, ArduinoD8;
typedef Pin<PortH, 6> Pin18, ArduinoD9;
typedef Pin<PortB, 0> Pin19, ArduinoD53;
typedef Pin<PortB, 1> Pin20, ArduinoD52;
typedef Pin<PortB, 2> Pin21, ArduinoD51;
typedef Pin<PortB, 3> Pin22, ArduinoD50;
typedef Pin<PortB, 4> Pin23, ArduinoD10;
typedef Pin<PortB, 5> Pin24, ArduinoD11;
typedef Pin<PortB, 6> Pin25, ArduinoD12;
typedef Pin<PortB, 7> Pin26, ArduinoD13;
typedef Pin<PortH, 7> Pin27;
typedef Pin<PortG, 3> Pin28;
typedef Pin<PortG, 4> Pin29;
typedef Pin<PortL, 0> Pin35, ArduinoD49;
typedef Pin<PortL, 1> Pin36, ArduinoD48;
typedef Pin<PortL, 2> Pin37, ArduinoD47;
typedef Pin<PortL, 3> Pin38, ArduinoD46;
typedef Pin<PortL, 4> Pin39, ArduinoD45;
typedef Pin<PortL, 5> Pin40, ArduinoD44;
typedef Pin<PortL, 6> Pin41, ArduinoD43;
typedef Pin<PortL, 7> Pin42, ArduinoD42;
typedef Pin<PortD, 0> Pin43, ArduinoD21;
typedef Pin<PortD, 1> Pin44, ArduinoD20;
typedef Pin<PortD, 2> Pin45, ArduinoD19;
typedef Pin<PortD, 3> Pin46, ArduinoD18;
typedef Pin<PortD, 4> Pin47;
typedef Pin<PortD, 5> Pin48;
typedef Pin<PortD, 6> Pin49;
typedef Pin<PortD, 7> Pin50, ArduinoD38;
typedef Pin<PortG, 0> Pin51, ArduinoD41;
typedef Pin<PortG, 1> Pin52, ArduinoD40;
typedef Pin<PortC, 0> Pin53, ArduinoD37;
typedef Pin<PortC, 1> Pin54, ArduinoD36;
typedef Pin<PortC, 2> Pin55, ArduinoD35;
typedef Pin<PortC, 3> Pin56, ArduinoD34;
typedef Pin<PortC, 4> Pin57, ArduinoD33;
typedef Pin<PortC, 5> Pin58, ArduinoD32;
typedef Pin<PortC, 6> Pin59, ArduinoD31;
typedef Pin<PortC, 7> Pin60, ArduinoD30;
typedef Pin<PortJ, 0> Pin63, ArduinoD15;
typedef Pin<PortJ, 1> Pin64, ArduinoD14;
typedef Pin<PortJ, 2> Pin65;
typedef Pin<PortJ, 3> Pin66;
typedef Pin<PortJ, 4> Pin67;
typedef Pin<PortJ, 5> Pin68;
typedef Pin<PortJ, 6> Pin69;
typedef Pin<PortG, 2> Pin70, ArduinoD39;
typedef Pin<PortA, 7> Pin71, ArduinoD29;
typedef Pin<PortA, 6> Pin72, ArduinoD28;
typedef Pin<PortA, 5> Pin73, ArduinoD27;
typedef Pin<PortA, 4> Pin74, ArduinoD26;
typedef Pin<PortA, 3> Pin75, ArduinoD25;
typedef Pin<PortA, 2> Pin76, ArduinoD24;
typedef Pin<PortA, 1> Pin77, ArduinoD23;
typedef Pin<PortA, 0> Pin78, ArduinoD22;
typedef Pin<PortJ, 7> Pin79;
typedef Pin<PortK, 7> Pin82, ArduinoA15;
typedef Pin<PortK, 6> Pin83, ArduinoA14;
typedef Pin<PortK, 5> Pin84, ArduinoA13;
typedef Pin<PortK, 4> Pin85, ArduinoA12;
typedef Pin<PortK, 3> Pin86, ArduinoA11;
typedef Pin<PortK, 2> Pin87, ArduinoA10;
typedef Pin<PortK, 1> Pin88, ArduinoA9;
typedef Pin<PortK, 0> Pin89, ArduinoA8;
typedef Pin<PortF, 7> Pin90, ArduinoA7;
typedef Pin<PortF, 6> Pin91, ArduinoA6;
typedef Pin<PortF, 5> Pin92, ArduinoA5;
typedef Pin<PortF, 4> Pin93, ArduinoA4;
typedef Pin<PortF, 3> Pin94, ArduinoA3;
typedef Pin<PortF, 2> Pin95, ArduinoA2;
typedef Pin<PortF, 1> Pin96, ArduinoA1;
typedef Pin<PortF, 0> Pin97, ArduinoA0;

#endif