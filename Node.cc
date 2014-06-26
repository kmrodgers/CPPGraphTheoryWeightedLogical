#include "Node.h"

#include <list>
#include <map>
#include <iostream>
#include <algorithm>


Node::Node(int n)
{
	name = n;
    setDegree();
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
	return (int)edgeList.size();
}

Node* Node::getMinimalDegreeNode()
{
    std::map<Node*, int>::iterator minimalDegreeNode = edgeList.begin();
    for (std::map<Node*, int>::iterator iter = edgeList.begin(); iter != edgeList.end(); iter++)
    {
        iter->first->setDegree();
    }
    for (std::map<Node*, int>::iterator iter = edgeList.begin(); iter != edgeList.end(); iter++)
    {
//        if (minimalDegreeNode->second > iter->second && iter->second > 0)
        if (minimalDegreeNode->second > iter->second)
        {
            minimalDegreeNode = iter;
        }
    }
    return minimalDegreeNode->first;
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
//	if (edgeList[n1] == 0)
//		destroyEdge(n1);
}

void Node::setDegree()
{
    degree = 0;
    for (std::map<Node*, int>::iterator iter = edgeList.begin(); iter != edgeList.end(); iter++)
    {
        if (iter->second == 0)
            destroyEdge(iter->first);
    }
    for (std::map<Node*, int>::iterator iter = edgeList.begin(); iter != edgeList.end(); iter++)
    {
        degree += iter->second;
    }
}

int Node::getDegree()
{
    setDegree();
//    for (std::map<Node*, int>::iterator iter = edgeList.begin(); iter != edgeList.end(); iter++)
//        std::cout << iter->second << std::endl;
    return degree;
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

void Node::removeEdgeWeight(Node* n1, int amount)
{
    for (std::map<Node*, int>::iterator iter = edgeList.begin(); iter != edgeList.end(); iter++)
	{
		if (iter->first == n1)
		{
            edgeList[n1] = iter->second - amount;
            if (edgeList[n1] == 0)
                destroyEdge(iter->first);
            break;
		}
	}
    n1->setDegree();
}

void Node::destroyEdge(Node* n1)
{
	edgeList.erase(n1);
}