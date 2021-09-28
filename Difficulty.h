#ifndef DIFFICULTY_H
#define DIFFICULTY_H
enum DifficultyLevel
{
	easy,
	medium,
	hard,
	extreme
};
class Difficulty
{
public:
	void scale();
	int getSpaceProbability();
	int getFrameDelay();
	Difficulty(DifficultyLevel level);
	~Difficulty();
private:
	int spaceProbability;
	int frameDelay;
	double scaleFactor = 1.0;
	int counter;
};
#endif
