#ifndef GUARD_Token_h
#define GUARD_Token_h

#include "Node.h"

class Token {
public:
	Token(Node*);
	Node* getTokenLocation();
	void setTokenLocation(Node*);
	int getCurrentPlayerTurn();
	void setPlayerTurn();
	
private:
	Node* location;
	int playerTurn;
};

#endif

//build game state by providing Surface*, have it translate and populate the game data
//Multiple Surface* 
//Class GameState
//overloading casting operation
//Surface* operator(Surface*)(){
//}
//..... gs;
//Casting: Surface* surf = (Surface*)gs;

//also, can overload << and >>: should this be built into surface?

//Goals: Outputing to single file, file for player 1 and player 2 wins
//IO Stuff