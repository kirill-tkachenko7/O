#ifndef GAME_H
#define GAME_H
#include <Arduino.h>
#include <LiquidCrystal.h>
class Game
{
public:
	void mainLoop();
	Game();
	~Game();
private:
	LiquidCrystal lcd = LiquidCrystal(12, 11, 4, 5, 6, 7);
	class Field
	{
	public:
		char* getRow0();
		char* getRow1();
		void update();
		Field();
		~Field();
	private:
		const int ROW_CHAR_COUNT = 16;
		char* row0;
		char* row1;
	};
	Field field;
};
#endif
