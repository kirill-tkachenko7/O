#include "Game.h"

void Game::mainLoop()
{
	field.update();
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print(field.getRow0());
	lcd.setCursor(0, 1);
	lcd.print(field.getRow1());
	delay(250);
}

Game::Game()
{
	lcd.begin(16, 2);
	randomSeed(analogRead(0));
}

Game::~Game()
{
	;
}

char* Game::Field::getRow0()
{
	return row0;
}

char* Game::Field::getRow1()
{
	return row1;
}

void Game::Field::update()
{
	int i;
	for (i = 0; i < ROW_CHAR_COUNT - 1; i++) {
		row0[i] = row0[i + 1];
		row1[i] = row1[i + 1];
	}
	row0[i] = row1[i - 1] == 'I' ? ' ' : (random(1, 100) < 75 ? ' ' : 'I');
	row1[i] = row0[i - 1] == 'I' ? ' ' : (random(1, 100) < 75 ? ' ' : 'I');
	if (row0[i] == 'I' && row1[i] == 'I') {
		if (random(0, 1) == 0)
			row0[i] = ' ';
		else
			row1[i] = ' ';
	}
}

Game::Field::Field()
{
	row0 = "               I";
	row1 = "                ";
}

Game::Field::~Field()
{
	;
}
