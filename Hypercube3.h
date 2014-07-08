//
//  Hypercube3.h
//  CPPWeightedLogical
//
//  Created by Kyle Rodgers on 7/7/14.
//  Copyright (c) 2014 KMRodgers. All rights reserved.
//

#ifndef GUARD_Hypercube3_h
#define GUARD_Hypercube3_h

#include <list>
#include <vector>
#include <string>
//#include <boolean>

class Node;

class Hypercube3 {
public:
	Hypercube3(int, int, bool, int);
	virtual ~Hypercube3();
	void createInitialEdges();
	void createInitialNodes(int);
	void removeEdge();
	void printVersion();
	void print();
	void game();
	//std::vector<std::string> player1;
	//std::vector<std::string> player2;
	//void analysis(int);
    int getRandomNumber(int);
    int getRandomEdge(int);
    int gameNumber;
    
private:
	int nodeNameCount; //Keeps track of what the name of the next Node will be
	int edgeWeight;
	int totalGames;
	bool watch;
	void rotateBar();
	int barCount;
	std::list<Node*> nodeList;
	
};

#endif