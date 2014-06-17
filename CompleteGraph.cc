/*	Author: Kyle Rodgers
 *	Date: 6/12/2014
 */

#include <list>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "Token.h"
#include "Node.h"
#include "CompleteGraph.h"
#include "RandomEngine.h"

//	This is the .cc file for the CompleteGraph object.

/*	Constructor for the CompleteGraph. Takes three ints: i, numNodes, weight,
 *	and a bool b and assigns initial values.
 */
CompleteGraph::CompleteGraph(int i, int numNodes, int weight, bool b, int k)
{
	edgeWeight = weight;
	gameNumber = i;
	totalGames = k;
	watch = b;
	nodeNameCount = 0;
	for (int j = 1; j <= numNodes ; j++)
	{
		createInitialNodes(j);
		nodeNameCount++;
	}
	createInitialEdges();
	game();
}

//	Destructor for the CompleteGraph object
CompleteGraph::~CompleteGraph()
{
	while(!nodeList.empty()) {
		delete nodeList.front();
		nodeList.pop_front();
	}
	nodeList.clear();
	//player1.clear();
	//player2.clear();
}

//	Creates the initial edges
void CompleteGraph::createInitialEdges()
{
	for (std::list<Node*>::iterator iter1 = nodeList.begin(); iter1 != nodeList.end(); iter1++)
	{
		for (std::list<Node*>::iterator iter2 = nodeList.begin(); iter2 != nodeList.end(); iter2++)
		{
			if ((iter1) != (iter2))
			{
				(*iter1)->setEdge(*iter2, edgeWeight);
			}
		}
	}
}

//Desc: Creates the initial Nodes
//Input: int i, which is the name of the Node
void CompleteGraph::createInitialNodes(int i)
{
	Node *n = new Node(i);
	nodeList.push_back(n);
}

void CompleteGraph::removeEdge()
{
	int n1 = 0;
	int n2 = 0;
	std::cout << "Please enter the nodes you would like to remove the edge between (x y): ";
	std::cin >> n1;
	std::cin >> n2;
	std::list<Node*>::iterator iter1;
	std::list<Node*>::iterator iter2;
	for (iter1 = nodeList.begin(); iter1 != nodeList.end(); iter1++)
	{
		if ((*iter1)->getName() == n1)
		{
			for (iter2 = nodeList.begin(); iter2 != nodeList.end(); iter2++)
			{
				if ((*iter2)->getName() == n2)
				{
					(*iter1)->destroyEdge(*iter2);
					(*iter2)->destroyEdge(*iter1);
				}
			}
		}
	}
}

//Desc: Prints out the current version of the program the user is running
void CompleteGraph::printVersion()
{
	std::cout << std::endl;
	std::cout << "Version: 0.2 Beta" << std::endl;
	std::cout << "Author: Kyle Rodgers" << std::endl;
	std::cout << "Date of Last Revision: 5/4/14 23:30" << std::endl;
}

void CompleteGraph::print()
{
	std::cout << "This surface contains the following nodes and edges: " << std::endl;
	std::list<Node*>::iterator iter;
	for (iter = nodeList.begin(); iter != nodeList.end(); iter++)
	{
		(*iter)->printEdges();
	}
}

int CompleteGraph::getRandomNumber(int size)
{
	
	RandomEngine *rand = RandomEngine::instance();
	double r = rand->getRandom();
	int randNum = (int)(r * size);
	return randNum;
}

int CompleteGraph::getRandomEdge(int size)
{
	
	RandomEngine *rand = RandomEngine::instance();
	double r = rand->getRandom();
	int randNum = (int)((r * size)+1);
	return randNum;
}

void CompleteGraph::rotateBar()
{
	barCount++;
	char barspin[4] = {'\\', '|', '/', '-'};
	int whichOne;
	whichOne = barCount % 4;
	if (whichOne == 3)
	{
		std::cout << '\r' << barspin[whichOne] << "  Please wait while the games are played. Game: " << gameNumber << " " << (int)(((double)gameNumber/totalGames)*100.0) << "% complete";
	}
	else
	{
		std::cout << '\r' << barspin[whichOne] << "  Please wait while the games are played. Game: " << gameNumber << " " << (int)(((double)gameNumber/totalGames)*100.0) << "% complete";
	}
	std::cout.flush();
	return;
}

void CompleteGraph::game()
{
	std::ofstream master_data;
	//master_data.open("logs/log.txt");
	
	
	//std::string moves;
//	std::string gameName = std::to_string(i) + ".txt";
	std::string master_data_path = "output_data/master_data.txt";
	
//	master_data.open(path+gameName);
	master_data.open(master_data_path, std::ios_base::app);
	std::list<Node*>::iterator iter1 = nodeList.begin();
	Node* nextMoveNode;
	Token* t = new Token(*iter1);
	int nextRandomWeight = 0;
	int edgeSize = 0;
	int nextMove = 0;
	if (watch == true)
	{
		std::cout << "Game " << gameNumber << std::endl;
		std::cout << std::endl;
		master_data << (t->getTokenLocation())->getName() << "-";
		while (true)
		{
    	    nextMove = getRandomNumber(t->getTokenLocation()->getEdgeListSize()); // inside () returns an int the size of possible nodes to go to
        	nextMoveNode = t->getTokenLocation()->getNodeAtElement(nextMove);     // sets node at based in this number
	        edgeSize = t->getTokenLocation()->getWeight(nextMoveNode);
	        nextRandomWeight = getRandomEdge(edgeSize);
			if (nextRandomWeight > 0)
        	{
        		master_data << nextRandomWeight << "-";
        		(t->getTokenLocation())->setEdge(nextMoveNode, nextMoveNode->getWeight(t->getTokenLocation()) - nextRandomWeight);
		        (nextMoveNode)->setEdge(t->getTokenLocation(), t->getTokenLocation()->getWeight(nextMoveNode) - nextRandomWeight);
    		    std::cout << "Player " << t->getCurrentPlayerTurn() << " removed edge " << (t->getTokenLocation())->getName() << " - " << nextRandomWeight << " - " << (nextMoveNode)->getName() << std::endl;
	    	    //master_data << "Player " << t->getCurrentPlayerTurn() << " removed edge " << (t->getTokenLocation())->getName() << " - " << (nextMoveNode)->getName() << std::endl;
    	    	t->setPlayerTurn();
		        t->setTokenLocation(nextMoveNode);
		        master_data << (t->getTokenLocation())->getName() << "-";
		    }
			else if (nextRandomWeight == 0)
		    {
		    	t->getTokenLocation()->destroyEdge(nextMoveNode);
	    		nextMoveNode->destroyEdge(t->getTokenLocation());
		    }
    	    if (t->getTokenLocation()->getEdgeListSize() == 0)
			{
				//moves += std::to_string((t->getTokenLocation())->getName());
				t->setPlayerTurn();
				std::cout << std::endl;
				//master_data << "Player " << t->getCurrentPlayerTurn() << " wins!\n";
				master_data << t->getCurrentPlayerTurn() << std::endl;		
				std::cout << "Player " << t->getCurrentPlayerTurn() << " wins!" << std::endl;
				std::cout << std::endl;
				break;
			}
		}
	}
	else
	{
		master_data << (t->getTokenLocation())->getName() << "-";
		while (true)
		{
			rotateBar();
    	    nextMove = getRandomNumber(t->getTokenLocation()->getEdgeListSize()); // inside () returns an int the size of possible nodes to go to
	        nextMoveNode = t->getTokenLocation()->getNodeAtElement(nextMove);     // sets node at based in this number
    	    edgeSize = t->getTokenLocation()->getWeight(nextMoveNode);
        	nextRandomWeight = getRandomEdge(edgeSize);
			if (nextRandomWeight > 0)
    	    {
    	    	master_data << nextRandomWeight << "-";
        		(t->getTokenLocation())->setEdge(nextMoveNode, nextMoveNode->getWeight(t->getTokenLocation()) - nextRandomWeight);
	        	(nextMoveNode)->setEdge(t->getTokenLocation(), t->getTokenLocation()->getWeight(nextMoveNode) - nextRandomWeight);
//    		    std::cout << "Player " << t->getCurrentPlayerTurn() << " removed edge " << (t->getTokenLocation())->getName() << " - " << nextRandomWeight << " - " << (nextMoveNode)->getName() << std::endl;
		        //master_data << "Player " << t->getCurrentPlayerTurn() << " removed edge " << (t->getTokenLocation())->getName() << " - " << (nextMoveNode)->getName() << std::endl;
    		    t->setPlayerTurn();
	        	t->setTokenLocation(nextMoveNode);
       			master_data << (t->getTokenLocation())->getName() << "-";
	    	}
			else if (nextRandomWeight == 0)
		    {
	    		t->getTokenLocation()->destroyEdge(nextMoveNode);
	    		nextMoveNode->destroyEdge(t->getTokenLocation());
		    }
    	    if (t->getTokenLocation()->getEdgeListSize() == 0)
			{
				//moves += std::to_string((t->getTokenLocation())->getName());
				t->setPlayerTurn();
//				std::cout << std::endl;
				//master_data << "Player " << t->getCurrentPlayerTurn() << " wins!\n";
				master_data << t->getCurrentPlayerTurn() << std::endl;		
//				std::cout << "Player " << t->getCurrentPlayerTurn() << " wins!" << std::endl;
//				std::cout << std::endl;
				break;
		}
	}	
	delete t;
	master_data.close();
	}
}