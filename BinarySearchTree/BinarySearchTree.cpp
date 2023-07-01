#include <iostream>
#include <string>
using namespace std;

class node
{
public:
	string info;
	node* leftchild;
	node* rightchild;

	//constructor for the node class
	node(string i, node* l, node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class binarytree
{
public:
	node* ROOT;

	binarytree()
	{
		ROOT = NULL; //initializing ROOT to NULL
	}

	void insert(string element) //insert a node in the binary search tree
	{
		node* newnode = new node(element, NULL, NULL); //allocate memory fot the new node
		newnode->info = element; //assign value to the data field of the new node
	}
};