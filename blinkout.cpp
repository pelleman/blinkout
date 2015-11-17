/**********************************************
 *
 * blinkout.cpp
 *
 * Display numbers on Arduino using a single LED 
 *
 * Per-Ola Gustavsson
 * http://marsba.se
 * pelle@marsba.se
 *
 *
 *
 * Copyright 2015 Per-Ola Gustavsson
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *********************************************/

#include <Arduino.h>

int powOfTen [] = {1, 10, 100, 1000, 10000};

void blinkOut (int pin, int code, int onTime, int offTime, int divideTime)
{
	pinMode(pin, OUTPUT);
	digitalWrite(pin, HIGH);		
	delay(divideTime);
	if (code < 0) {
		for (int i = 0; i < 20; i++) {
			digitalWrite(pin, HIGH);		
			delay(divideTime / 40);
			digitalWrite(pin, LOW);
			delay(divideTime / 40);
		}
	}
	digitalWrite(pin, LOW);
	delay(divideTime);
	
	bool begun = false;
	for (int d = 4; d >= 0; d--) {
		byte digit = abs(code) / powOfTen[d] % 10;
		if (digit > 0) {
			for (int i = 0; i < digit; i++) {
				digitalWrite(pin, HIGH);		
				delay(onTime);
				digitalWrite(pin, LOW);
				delay(offTime);
			}
			begun = true;
			delay(divideTime);
		} else if (begun){
			digitalWrite(pin, HIGH);		
			delay(onTime / 5);
			digitalWrite(pin, LOW);
			delay(divideTime + offTime);
		}
	}
}
void blinkOut (int pin, int code)
{
	blinkOut(pin, code, 200, 200, 1000);
}

