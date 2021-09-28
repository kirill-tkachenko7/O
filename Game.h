#ifndef GAME_H
#define GAME_H
#include <Arduino.h>
#include <LiquidCrystal.h>
class Game
{
public:
	bool mainLoop();
	Game();
	~Game();
private:
	LiquidCrystal* lcd;
	char* row0, * row1;
	int gameCycleSize, cycleFrame;
	int score = 0;
	void gameOver(int row);
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
	class O {
	public:
		void update();
		int getPosition();
	private:
		int position = 0;
	};
	O o;
	Field field;
};
#endif
