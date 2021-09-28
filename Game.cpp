#include "Game.h"

bool Game::mainLoop()
{
	cycleFrame = ++cycleFrame % gameCycleSize;
	o.update();
	if (cycleFrame == 0) 
	{
		field.update();
		lcd->clear();
		row0 = field.getRow0();
		lcd->setCursor(0, 0);
		lcd->print(row0);
		row1 = field.getRow1();
		lcd->setCursor(0, 1);
		lcd->print(row1);
		score++;
	}
	if (o.getPosition() == 0) {
		lcd->setCursor(0, 1);
		lcd->print(row1[0]);
		lcd->setCursor(0, 0);
		lcd->print("O");
		if (row0[0] == 'I') {
			gameOver(0);
			return false;
		}
	}
	else if (o.getPosition() == 1) {
		lcd->setCursor(0, 0);
		lcd->print(row0[0]);
		lcd->setCursor(0, 1);
		lcd->print("O");
		if (row1[0] == 'I') {
			gameOver(1);
			return false;
		}
	}
	delay(30);
	return true;
}

Game::Game()
{
	gameCycleSize = 6;
	cycleFrame = gameCycleSize - 1;
	lcd = new LiquidCrystal(12, 11, 4, 5, 6, 7);
	lcd->begin(16, 2);
}

Game::~Game()
{
	delete lcd;
}

void Game::gameOver(int row)
{
	for (int i = 0; i < 10; i++) {
		lcd->setCursor(0, row);
		lcd->print('X');
		delay(130);
		lcd->setCursor(0, row);
		lcd->print('I');
		delay(130);
	}
	lcd->setCursor(0, row);
	lcd->print('X');
	delay(500);
	lcd->clear();
	lcd->print("Game Over!");
	lcd->setCursor(0, 1);
	lcd->print("Score: ");
	lcd->print(score);
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
	row0[i] = row1[i - 1] == 'I' ? ' ' : (random(1, 100) < 50 ? ' ' : 'I');
	row1[i] = row0[i - 1] == 'I' ? ' ' : (random(1, 100) < 50 ? ' ' : 'I');
	if (row0[i] == 'I' && row1[i] == 'I') {
		if (random(0, 1) == 0)
			row0[i] = ' ';
		else
			row1[i] = ' ';
	}
}

Game::Field::Field()
{
	randomSeed(analogRead(0));
	if (random(0, 1)) 
	{
		row0 = "               I";
		row1 = "                ";
	}
	else 
	{
		row0 = "                ";
		row1 = "               I";
	}
}

Game::Field::~Field()
{
	;
}

void Game::O::update() {
	if (digitalRead(13) == HIGH)
		position = 0;
	else if (digitalRead(10) == HIGH)
		position = 1;
}
int Game::O::getPosition()
{
	return position;
}
