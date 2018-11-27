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
	void insert (int data);
	Node* create(int data);
	void preorderTrav();
	void postorderTrav();
	void inorderTrav();
	void preorder(Node* p);
	void postorder(Node* p);
	void inorder(Node* p);
	void setRoot();
	void avlCheck(Node* n);
	void rotateLeft(Node* & n2);
	void doubleRotateLeft(Node* & n3);
	void rotateRight(Node* & n2);
	void doubleRotateRight(Node* & n3);
	void balance(Node* & n);
	int find(int data);
	int get_depth(Node* n);
	
};

