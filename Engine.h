#ifndef GUARD_Engine_h
#define GUARD_Engine_h

#include "PetersenGraph.h"
#include <string>

class Engine {
public:
	Engine();
	int p1size;
	int p2size;
	int longestGame;
	   
private:
	void printIntro();
	void printStartMenu();
	void startMenuChoices(int);
	void createPetersenGraph(int, int, std::string);
	void rotateBarParse();
	void rotateBarParsePlayer1();
	void rotateBarParsePlayer2();
	void rotateBarAnalyzeP1();
	void rotateBarAnalyzeP2();
	int barCount;
	int barCount1;
	int barCount2;
	void createCompleteGraph(int, int, int, std::string);
	void parseMasterData();
	void parsePlayerLogicalData();
	void dataAnalysis(int);
};

#endif