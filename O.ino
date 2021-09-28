/*
 Name:		O.ino
 Created:	9/28/2021 10:05:25 AM
 Author:	Kirill
*/

#include "Game.h"
Game o;

void setup() {
	
}

void loop() {
	while(o.mainLoop());
	exit(1);
}
