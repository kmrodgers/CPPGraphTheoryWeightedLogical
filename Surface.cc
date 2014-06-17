#include <list>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>						//for saving information to text files

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "Token.h"
#include "Node.h"
#include "Surface.h"
#include "RandomEngine.h"

/*
 This is the .cpp file for the Surface object.
 */

//Desc: Constructor for the Surface object. Constructs a Surface of Nodes,
//		and creates edges between them.
//Input: int i for the number of Nodes
Surface::Surface(int i, int j)
{
	gameNumber = i;
	edgeWeight = j;
	nodeNameCount = 0;
	for (int k = 1; k <= 10; k++)
	{
		createInitialNodes(k);
		nodeNameCount++;
	}
	Surface::createInitialEdges();
	std::ofstream myfile;
	game();
}
//analysis(numGames);


//Desc: Destructor for the Surface object. Deletes the nodeList
//		and frees up memory.
Surface::~Surface()
{
	while(!nodeList.empty()) {
		delete nodeList.front();
		nodeList.pop_front();
	}
	nodeList.clear();
	//player1.clear();
	//player2.clear();
}

//Desc: Creates the initial edges
void Surface::createInitialEdges()
{
	std::list<Node*>::iterator iter1 = nodeList.begin();
	std::list<Node*>::iterator iter2 = nodeList.begin();
	std::advance(iter2, 1);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter2, 3);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter2, 1);
	(*iter1)->setEdge(*iter2, edgeWeight);
	iter2 = nodeList.begin();
	std::advance(iter1, 1);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter2, 2);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter2, 4);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter1, 1);
	iter2 = nodeList.begin();
	std::advance(iter2, 1);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter2, 2);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter2, 4);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter1, 1);
	iter2 = nodeList.begin();
	std::advance(iter2, 2);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter2, 2);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter2, 4);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter1, 1);
	iter2 = nodeList.begin();
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter2, 3);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter2, 6);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter1, 1);
	iter2 = nodeList.begin();
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter2, 7);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter2, 1);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter1, 1);
	iter2 = nodeList.begin();
	std::advance(iter2, 1);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter2, 7);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter2, 1);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter1, 1);
	iter2 = nodeList.begin();
	std::advance(iter2, 2);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter2, 3);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter2, 4);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter1, 1);
	iter2 = nodeList.begin();
	std::advance(iter2, 3);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter2, 2);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter2, 1);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter1, 1);
	iter2 = nodeList.begin();
	std::advance(iter2, 4);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter2, 2);
	(*iter1)->setEdge(*iter2, edgeWeight);
	std::advance(iter2, 1);
	(*iter1)->setEdge(*iter2, edgeWeight);
	
}

//Desc: Creates the initial Nodes
//Input: int i, which is the name of the Node
void Surface::createInitialNodes(int i)
{
	Node *n = new Node(i);
	nodeList.push_back(n);
}

void Surface::removeEdge()
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
void Surface::printVersion()
{
	std::cout << std::endl;
	std::cout << "Version: 0.2 Beta" << std::endl;
	std::cout << "Author: Kyle Rodgers" << std::endl;
	std::cout << "Date of Last Revision: 5/4/14 23:30" << std::endl;
}

void Surface::print()
{
	std::cout << "This surface contains the following nodes and edges: " << std::endl;
	std::list<Node*>::iterator iter;
	for (iter = nodeList.begin(); iter != nodeList.end(); iter++)
	{
		(*iter)->printEdges();
	}
}

int Surface::getRandomNumber(int size)
{
	
	RandomEngine *rand = RandomEngine::instance();
	double r = rand->getRandom();
	int randNum = (int)(r * size);
	return randNum;
}

int Surface::getRandomEdge(int size)
{
	
	RandomEngine *rand = RandomEngine::instance();
	double r = rand->getRandom();
	int randNum = (int)((r * size)+1);
	return randNum;
}

//This is the method that plays the game
//The master data is sent to the file /output_data/mater_data.txt

void Surface::game()
{
	std::ofstream myfile;
	//myfile.open("logs/log.txt");
	
	
	//std::string moves;
//	std::string gameName = std::to_string(i) + ".txt";
	std::string master_data_path = "output_data/master_data.txt";
	
//	myfile.open(path+gameName);
	myfile.open(master_data_path, std::ios_base::app);
	std::list<Node*>::iterator iter1 = nodeList.begin();
	Node* nextMoveNode;
	Token* t = new Token(*iter1);
	int nextMove = 0;
	int nextRandomWeight = 0;
	int edgeSize = 0;
	std::cout << "Game " << gameNumber << std::endl;
	std::cout << std::endl;
	myfile << (t->getTokenLocation())->getName() << "-";
	while (true)
	{
        nextMove = getRandomNumber(t->getTokenLocation()->getEdgeListSize()); // inside () returns an int the size of possible nodes to go to
        nextMoveNode = t->getTokenLocation()->getNodeAtElement(nextMove);     // sets node at based in this number
        edgeSize = t->getTokenLocation()->getWeight(nextMoveNode);
        nextRandomWeight = getRandomEdge(edgeSize);
//        std::cout << edgeSize << std::endl;
//        std::cout << nextRandomWeight << std::endl;
//        if (t->getTokenLocation()->getWeight(nextMoveNode) > 0)
		if (nextRandomWeight > 0)
        {
        	(t->getTokenLocation())->setEdge(nextMoveNode, nextMoveNode->getWeight(t->getTokenLocation()) - nextRandomWeight);
	        (nextMoveNode)->setEdge(t->getTokenLocation(), t->getTokenLocation()->getWeight(nextMoveNode) - nextRandomWeight);
    	    std::cout << "Player " << t->getCurrentPlayerTurn() << " removed edge " << (t->getTokenLocation())->getName() << " - " << nextRandomWeight << " - " << (nextMoveNode)->getName() << std::endl;
	        //myfile << "Player " << t->getCurrentPlayerTurn() << " removed edge " << (t->getTokenLocation())->getName() << " - " << (nextMoveNode)->getName() << std::endl;
    	    t->setPlayerTurn();
	        t->setTokenLocation(nextMoveNode);
	    }
//	    else if (t->getTokenLocation()->getWeight(nextMoveNode) == 0)
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
			//myfile << "Player " << t->getCurrentPlayerTurn() << " wins!\n";
			myfile << t->getCurrentPlayerTurn() << std::endl;		
			std::cout << "Player " << t->getCurrentPlayerTurn() << " wins!" << std::endl;
			std::cout << std::endl;
//			if (t->getCurrentPlayerTurn() == 1)
//				player1.push_back(moves);
//			else
//				player2.push_back(moves);
			//myfile << (t->getTokenLocation())->getName() << std::endl;
			//moves.clear();
			//myfile.close();
			break;
		}
		myfile << (t->getTokenLocation())->getName() << "-";
		//moves += std::to_string((t->getTokenLocation())->getName()) + "-";
		
	}
	delete t;
	myfile.close();
	
	}

/*
void Surface::analysis(int numGames)
{
	int numberOfGamesPlayed = numGames;
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "Game Analysis" << std::endl;
	std::cout << std::endl;
	std::cout << "Of the " << numGames << " games played:" << std::endl;
	std::cout << std::endl;
	std::cout << "Player 1 won " << player1.size() << "." << std::endl;
	std::cout << "Player 2 won " << player2.size() << "." << std::endl;
	std::vector<std::string> player1moves;
	std::vector<std::string> player2moves;
	for (std::vector<std::string>::iterator i = player1.begin(); i != player1.end(); i++)
	{
		std::vector<std::string>::iterator it = find(player1moves.begin(), player1moves.end(), *i);
		if (it == player1moves.end()) {
			player1moves.push_back(*i);
		}	
	}
	for (std::vector<std::string>::iterator i = player2.begin(); i != player2.end(); i++)
	{
		std::vector<std::string>::iterator it = find(player2moves.begin(), player2moves.end(), *i);
		if (it == player2moves.end()) {
			player2moves.push_back(*i);
		}	
	}
	std::sort(player1moves.begin(), player1moves.end());
	std::sort(player2moves.begin(), player2moves.end());
	std::cout << std::endl;
	std::cout << "There are " << player1moves.size() << " unique moves for Player 1." << std::endl;
	std::cout << "There are " << player2moves.size() << " unique moves for Player 2." << std::endl;
	std::cout << std::endl;
	std::cout << "The following moves led to Player 1's victory:" << std::endl;
	for (std::vector<std::string>::iterator i = player1moves.begin(); i != player1moves.end(); i++)
	{
		std::cout << *i << std::endl;
	}
	std::cout << std::endl;
	std::cout << "The following moves led to Player 2's victory:" << std::endl;
	for (std::vector<std::string>::iterator i = player2moves.begin(); i != player2moves.end(); i++)
	{
		std::cout << *i << std::endl;
	}
	std::cout << std::endl;
*/