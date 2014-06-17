#ifndef GUARD_Node_h
#define GUARD_Node_h

#include <map>

class Node {
public:
	Node(int);
	virtual ~Node();
	int getName();
	void printEdges();
	void setEdge(Node*, int);
	int getWeight(Node*);
	void destroyEdge(Node*);
	bool edgeExists(int);
	Node* getNodeAtElement(int);
    int getRandomNumber();
    //bool search(int);
	int getEdgeListSize();
	std::map<Node*, int> edgeList; //shows the node it's connected to, and the weight
	
private:
	int name;
	
};

#endif

//Goals
//Printouts
//Proper RNG
//Get Unit Weight Stuff working
//analysis - producing all the graphs of how you win
//ASCII drawings?


//----------------------------
//use map to know connections and the weights of the edges.
//std::map<Node*, double>

//Dump everything into buffer and extract information:
//1. When player 1 wins, player 2 wins
//2. When number of remaining edges are the same

//Output is N1 - N2 - N3, etc, and parse this
//Unix parsers already exist?

//more results | sort -u
//-u flag puts 

//parse into all unique games vs unique player 1 wins, into sort

//saving game states for analysis afterward 
//vector of game state after each move

//more sophisticated analysis afterward