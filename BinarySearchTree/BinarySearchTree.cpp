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
		// this function searches the currentnode of the specified node as well as the current node of it's parent
		currentnode = ROOT;
		parent = NULL;
		while ((currentnode != NULL) && (currentnode->info != element))
		{
			parent = currentnode;
			if (element < currentnode->info)
				currentnode = currentnode->leftchild;
			else
				currentnode = currentnode->rightchild;
		}
	}

	void inorder(node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
	}

	void preorder(node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}

	void postorder(node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			postorder(ptr->leftchild);
			postorder(ptr->rightchild);
			cout << ptr->info << " ";
		}
	}
};

int main()
{
	binarytree obj;
	while (true)
	{
		cout << "\nMenu" << endl;
		cout << "1. Implement insert operation" << endl;
		cout << "2. Perform inorder traversal" << endl;
		cout << "3. Perfrom preorder traversal" << endl;
		cout << "4. Perform postorder traversal" << endl;
		cout << "5. Exit" << endl;
		cout << "\nEnter your chouce (1-5): ";

		char ch;
		cin >> ch;
		cout << endl;

		switch (ch)
		{
		case '1':
		{
			cout << "Enter a word: ";
			string word;
			cin >> word;
			obj.insert(word);
			break;
		}
		case '2':
		{
			obj.inorder(obj.ROOT);
			break;
		}
		case '3':
		{
			obj.preorder(obj.ROOT);
			break;
		}
	}
}