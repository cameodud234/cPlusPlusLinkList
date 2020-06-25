#ifndef NODE_H
#define NODE_H

#include <limits.h>

struct Node
{
	int data = INT_MIN;
	Node* next = nullptr;
    Node(){}
    Node(int data): data{ data }{}
};

#endif //NODE_H
