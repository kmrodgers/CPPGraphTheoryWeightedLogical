#include "Node.h"
#include "Token.h"

#include <iostream>

Token::Token(Node* n)
{
	location = n;
	playerTurn = 1;
}

Node* Token::getTokenLocation()
{
	return location;
}

void Token::setTokenLocation(Node* n)
{
	location = n;
}

int Token::getCurrentPlayerTurn()
{
	return playerTurn;
}

void Token::setPlayerTurn()
{
	if (playerTurn == 1)
		playerTurn = 2;
	else
		playerTurn = 1;
}