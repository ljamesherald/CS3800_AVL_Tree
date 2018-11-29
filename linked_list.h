#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

class Node
{
public:
	Node();
   	Node* left;
	Node* right;
	int data;
};


class LinkedList
{
public:
	Node* current;
	Node* root;
	LinkedList();
	~LinkedList();
	ifstream inFile;
	ofstream outFile;
	Node* insert (Node* root, int value);
	Node* create(int data);
	void preorderTrav();
	void postorderTrav();
	void inorderTrav();
	void preorder(Node* p);
	void postorder(Node* p);
	void inorder(Node* p);
	void setRoot();
	void avlCheck(Node* n);
	Node* rotateLeft(Node* n2);
	Node* doubleRotateLeft(Node* n3);
	Node* rotateRight(Node* n2);
	Node* doubleRotateRight(Node* n3);
	Node* balance(Node* n);
	int find(int data);
	int get_depth(Node* n);
	int depthDiff(Node *temp);
	
};

