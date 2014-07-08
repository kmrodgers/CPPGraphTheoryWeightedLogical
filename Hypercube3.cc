// Hypercube3.cc

#include <list>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
//#include <boolean>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "Token.h"
#include "Node.h"
#include "Hypercube3.h"
#include "RandomEngine.h"

/*
 This is the .cpp file for the Hypercube3 object.
 */

//Desc: Constructor for the Hypercube3 object. Constructs a Hypercube3 of Nodes,
//		and creates edges between them.
//Input: int i for the number of Nodes
Hypercube3::Hypercube3(int i, int j, bool b, int k)
{
	gameNumber = i;
	edgeWeight = j;
	totalGames = k;
	watch = b;
	nodeNameCount = 0;
	for (int l = 1; l <= 8; l++)
	{
		createInitialNodes(l);
		nodeNameCount++;
	}
	createInitialEdges();
	std::ofstream master_data;
	game();
}
//analysis(numGames);


//Desc: Destructor for the Hypercube3 object. Deletes the nodeList
//		and frees up memory.
Hypercube3::~Hypercube3()
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
void Hypercube3::createInitialEdges()
{
	std::list<Node*>::iterator iter1 = nodeList.begin();    // 1
	std::list<Node*>::iterator iter2 = nodeList.begin();
	std::advance(iter2, 1);                                 // 2
	(*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter2, 2);                                 // 4
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter2, 1);                                 // 5
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter1, 1);                                 // 2
    iter2 = nodeList.begin();                               // 1
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter2, 2);                                 // 3
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter2, 3);                                 // 5
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter1, 1);                                 // 3
    iter2 = nodeList.begin();
    std::advance(iter2, 1);                                 // 2
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter2, 2);                                 // 4
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter2, 3);                                 // 7
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter1, 1);                                 // 4
    iter2 = nodeList.begin();                               // 1
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter2, 2);                                 // 3
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter2, 5);                                 // 8
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter1, 1);                                 // 5
    iter2 = nodeList.begin();                               // 1
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter2, 5);                                 // 6
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter2, 2);                                 // 8
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter1, 1);                                 // 6
    iter2 = nodeList.begin();
    std::advance(iter2, 1);                                 // 2
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter2, 3);                                 // 5
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter2, 2);                                 // 7
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter1, 1);                                 // 7
    iter2 = nodeList.begin();
    std::advance(iter2, 2);                                 // 3
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter2, 3);                                 // 6
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter2, 2);                                 // 8
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter1, 1);                                 // 8
    iter2 = nodeList.begin();
    std::advance(iter2, 3);                                 // 4
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter2, 1);                                 // 5
    (*iter1)->setEdge(*iter2, edgeWeight);
    std::advance(iter2, 2);                                 // 7
    (*iter1)->setEdge(*iter2, edgeWeight);
}

//Desc: Creates the initial Nodes
//Input: int i, which is the name of the Node
void Hypercube3::createInitialNodes(int i)
{
	Node *n = new Node(i);
	nodeList.push_back(n);
}

void Hypercube3::removeEdge()
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
void Hypercube3::printVersion()
{
	std::cout << std::endl;
	std::cout << "Version: 0.2 Beta" << std::endl;
	std::cout << "Author: Kyle Rodgers" << std::endl;
	std::cout << "Date of Last Revision: 5/4/14 23:30" << std::endl;
}

void Hypercube3::print()
{
	std::cout << "This surface contains the following nodes and edges: " << std::endl;
	std::list<Node*>::iterator iter;
	for (iter = nodeList.begin(); iter != nodeList.end(); iter++)
	{
		(*iter)->printEdges();
	}
}

int Hypercube3::getRandomNumber(int size)
{
	
	RandomEngine *rand = RandomEngine::instance();
	double r = rand->getRandom();
	int randNum = (int)(r * size);
	return randNum;
}

//This is the method that plays the game
//The master data is sent to the file /output_data/mater_data.txt

void Hypercube3::rotateBar()
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

int Hypercube3::getRandomEdge(int size)
{
	
	RandomEngine *rand = RandomEngine::instance();
	double r = rand->getRandom();
	int randNum = (int)((r * size)+1);
	return randNum;
}

void Hypercube3::game()
{
    /*    std::cout << edgeWeight << std::endl;
     for (std::list<Node*>::iterator iter = nodeList.begin(); iter != nodeList.end(); iter++)
     std::cout << (*iter)->getDegree() << std::endl;
     */    std::ofstream master_data;
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
            if (t->getCurrentPlayerTurn() == 2)
            {
                nextMove = getRandomNumber(t->getTokenLocation()->getEdgeListSize());
                nextMoveNode = t->getTokenLocation()->getNodeAtElement(nextMove);
            }
            else
                nextMoveNode = t->getTokenLocation()->getMinimalDegreeNode();     // sets node at based in this number
	        edgeSize = t->getTokenLocation()->getWeight(nextMoveNode);
            nextRandomWeight = getRandomEdge(edgeSize);
            nextRandomWeight = 1;
            if (nextRandomWeight == 0)
		    {
		    	t->getTokenLocation()->destroyEdge(nextMoveNode);
	    		nextMoveNode->destroyEdge(t->getTokenLocation());
		    }
            else if (nextRandomWeight > 0)
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
    	    if (t->getTokenLocation()->getEdgeListSize() == 0)
			{
				//moves += std::to_string((t->getTokenLocation())->getName());
				t->setPlayerTurn();
				std::cout << std::endl;
				//master_data << "Player " << t->getCurrentPlayerTurn() << " wins!\n";
				master_data << t->getCurrentPlayerTurn() << std::endl;
				std::cout << "Player " << t->getCurrentPlayerTurn() << " wins!" << std::endl;
				std::cout << std::endl;
                delete t;
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
            for (std::list<Node*>::iterator iter = nodeList.begin(); iter != nodeList.end(); iter++)
                (*iter)->setDegree();
            //            for (std::list<Node*>::iterator iter = nodeList.begin(); iter != nodeList.end(); iter++)
            //                std::cout << "Node: " << (*iter)->getName() << " Degree: " << (*iter)->getDegree() << std::endl;
            if (t->getCurrentPlayerTurn() == 2)
            {
                nextMove = getRandomNumber(t->getTokenLocation()->getEdgeListSize());
                nextMoveNode = t->getTokenLocation()->getNodeAtElement(nextMove);
            }
            else
                nextMoveNode = t->getTokenLocation()->getMinimalDegreeNode();
    	    edgeSize = t->getTokenLocation()->getWeight(nextMoveNode);
        	nextRandomWeight = getRandomEdge(edgeSize);
            if (nextRandomWeight > 0)
    	    {
    	    	master_data << nextRandomWeight << "-";
        		(t->getTokenLocation())->removeEdgeWeight(nextMoveNode, nextRandomWeight);
	        	(nextMoveNode)->removeEdgeWeight(t->getTokenLocation(), nextRandomWeight);
    		    t->setPlayerTurn();
	        	t->setTokenLocation(nextMoveNode);
       			master_data << (t->getTokenLocation())->getName() << "-";
	    	}
            /*            else if (nextRandomWeight == 0)
             {
             t->getTokenLocation()->destroyEdge(nextMoveNode);
             nextMoveNode->destroyEdge(t->getTokenLocation());
             }
             */    	    if (t->getTokenLocation()->getEdgeListSize() == 0)
             {
                 //moves += std::to_string((t->getTokenLocation())->getName());
                 t->setPlayerTurn();
                 //				std::cout << std::endl;
                 //master_data << "Player " << t->getCurrentPlayerTurn() << " wins!\n";
                 master_data << t->getCurrentPlayerTurn() << std::endl;
                 //				std::cout << "Player " << t->getCurrentPlayerTurn() << " wins!" << std::endl;
                 //				std::cout << std::endl;
                 delete t;
                 break;
             }
        }
        master_data.close();
    }
}

/*
 
 while (true)
 {
 nextMove = getRandomNumber(t->getTokenLocation()->getEdgeListSize()); // inside () returns an int the size of possible nodes to go to
 nextMoveNode = t->getTokenLocation()->getNodeAtElement(nextMove);     // sets node at based in this number
 edgeSize = t->getTokenLocation()->getWeight(nextMoveNode);
 nextRandomWeight = getRandomEdge(edgeSize);
 if (nextRandomWeight > 0)
 {
 (t->getTokenLocation())->setEdge(nextMoveNode, nextMoveNode->getWeight(t->getTokenLocation()) - nextRandomWeight);
 (nextMoveNode)->setEdge(t->getTokenLocation(), t->getTokenLocation()->getWeight(nextMoveNode) - nextRandomWeight);
 std::cout << "Player " << t->getCurrentPlayerTurn() << " removed edge " << (t->getTokenLocation())->getName() << " - " << nextRandomWeight << " - " << (nextMoveNode)->getName() << std::endl;
 //master_data << "Player " << t->getCurrentPlayerTurn() << " removed edge " << (t->getTokenLocation())->getName() << " - " << (nextMoveNode)->getName() << std::endl;
 t->setPlayerTurn();
 t->setTokenLocation(nextMoveNode);
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
 master_data << (t->getTokenLocation())->getName() << "-";
 }
 }
 */