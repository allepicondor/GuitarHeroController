/*
*  Project     Nintendo Extension Controller Library
*  @author     David Madison
*  @link       github.com/dmadison/NintendoExtensionCtrl
*  @license    LGPLv3 - Copyright (c) 2018 David Madison
*
*  This file is part of the Nintendo Extension Controller Library.
*
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU Lesser General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU Lesser General Public License for more details.
*
*  You should have received a copy of the GNU Lesser General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*  Example:      Guitar_DebugPrint
*  Description:  Connect to a Guitar Hero controller and continuously print
*                its control data, nicely formatted for debugging, over
*                the serial bus.
*/

#include <NintendoExtensionCtrl.h>

GuitarController guitar;

void setup() {
	Serial.begin(9600); 
	guitar.begin();

	while (!guitar.connect()) {
		Serial.println("Guitar controller not detected!");
		delay(1000);
	}
}

void loop() {
	boolean success = guitar.update();  // Get new data from the controller

	if (success == true) {  // We've got data!
    const String greenPrint = String(guitar.fretGreen());
    const String redPrint = String(guitar.fretRed());
    const String yellowPrint = String(guitar.fretYellow());
    const String bluePrint = String(guitar.fretBlue());
    const String orangePrint = String(guitar.fretOrange());
    const String strumUP = String(guitar.strumUp());
    const String strumDOWN = String(guitar.strumDown());
    const String buttonP = String(guitar.buttonPlus());
    const String buttonM = String(guitar.buttonMinus());
    

    const String output = String(greenPrint+redPrint+yellowPrint+bluePrint+orangePrint+strumUP+strumDOWN+buttonP+buttonM);
		Serial.println(output);
	}
	else {  // Data is bad :(
		Serial.println("Controller Disconnected!");
		delay(1000);
		guitar.connect();
	}
}
