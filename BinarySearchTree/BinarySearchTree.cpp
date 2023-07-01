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
		newnode->leftchild = NULL; //make the left child of the new node point to NULL
		newnode->rightchild = NULL; //make the right child of the new node point to NULL

		node* parent = NULL;
		node* currentnode = NULL;
		search(element, parent, currentnode); //locate the node will be the parent of the node to be inserted

		if (parent == NULL) //if the parent is NULL (tree is empty)
		{
			ROOT = newnode; //Mark the new node as ROOT
			return; //exit
		}

		if (element < parent->info) //if the value in the data field of the new node is less than that of the parent
		{
			parent->leftchild = newnode; //make the left child of the parent point to the new node
		}

		else if (element > parent->info) //if the value in the data field of the new node is greater than that of the parent
		{
			parent->rightchild = newnode; //make the right child of the parent point to the new node
		}
	}

	void search(string element, node*& parent, node*& currentnode)
	{

	}
};