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
	int height;
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
	int find(int data);
	int get_height(Node* n);

};

