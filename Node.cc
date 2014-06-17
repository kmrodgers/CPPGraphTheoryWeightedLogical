#include "Node.h"

#include <list>
#include <map>
#include <iostream>
#include <algorithm>


Node::Node(int n)
{
	name = n;
}

Node::~Node()
{
}

int Node::getName()
{
	return name;
}

void Node::printEdges()
{
	std::cout << "Node " << name << " is connected to the following nodes: " << std::endl;
	std::map<Node*, int>::iterator iter;
	if (edgeList.size() == 0)
	{
		std::cout << "This node is not connected to any other node" << std::endl;
	}
	else
	{
		for (iter = edgeList.begin(); iter != edgeList.end(); iter++)
		{
			std::cout << "N" << name << " - " << iter->second << " - N" << iter->first << std::endl;
		}
	}
	std::cout << std::endl;
}

int Node::getEdgeListSize()
{
	return edgeList.size();
}

Node* Node::getNodeAtElement(int i)
{
    std::map<Node*, int>::iterator iter = edgeList.begin();
    std::advance(iter, i);
    return iter->first;
}

void Node::setEdge(Node* n1, int weight)
{
	edgeList[n1] = weight;
	if (edgeList[n1] == 0)
		destroyEdge(n1);
}

int Node::getWeight(Node* n1)
{
	for (std::map<Node*, int>::iterator iter = edgeList.begin(); iter != edgeList.end(); iter++)
	{
		if (iter->first == n1)
		{
				return iter->second;
				break;
		}
	}
	return -1;
}

/*
bool Node::edgeExists(int n1)
{
	bool answer = false;
	std::list<Node*>::iterator iter;
	for (iter = edgeList.begin(); iter != edgeList.end(); iter++)
	{
		if ((*iter)->getName() == n1)
		{
			answer = true;
		}
		else
		{
			answer = false;
		}
	}
	return answer;
}
*/

void Node::destroyEdge(Node* n1)
{
	edgeList.erase(n1);
}