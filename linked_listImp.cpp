#include <iostream>
#include <cstdlib>
#include <fstream>
#include "linked_list.h"

using namespace std;

Node::Node()
{
left = NULL;
right = NULL;
data = 0;
}
LinkedList::LinkedList()
{
   // this->length = 0;
	root = NULL;
	//root->data = 0;
	//root->left = NULL;
	//root->right = NULL;
}

LinkedList::~LinkedList()
{
}

Node* LinkedList::create(int data)
{
	Node* n = new Node;
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void LinkedList::insert(int data)
{
	if (root == NULL) {
		root = create(data);
		current = root;
	}
	else if (data < current->data) {
		if (current->left != NULL) {
			current = current->left;
			insert(data);
		}
		else
		{
			current->left = create(data);
			current = root;
		}
	}
	else if (data > current->data) {
		if (current->right != NULL) {
			current = current->right;
			insert(data);
		}
		else
		{
			current->right = create(data);
			current = root;
		}
	}
	else
	{
		cout << data << " is equal to another data entry." << endl;
		current = root;
	}
		
}

void LinkedList::preorderTrav()
{
	if (root){
		outFile.open("preorder.txt");
		preorder(root);
		outFile.close();
	}
}

void LinkedList::preorder(Node* p)
{
if (p != NULL){
cout << p->data << endl;
outFile << p->data << endl;
preorder(p->left);
preorder(p->right);
}
}

void LinkedList::postorderTrav()
{
	if (root){
		outFile.open("postorder.txt");
		postorder(root);
		outFile.close();
	}
}
void LinkedList::postorder(Node* p)
{
if (p != NULL){
postorder(p->left);
postorder(p->right);
cout << p->data << endl;
outFile << p->data << endl;
}
}

void LinkedList::inorderTrav()
{
	if (root){
		outFile.open("inorder.txt");
		inorder(root);
		outFile.close();
	}
}

void LinkedList::inorder(Node* p)
{
if (p !=NULL){
inorder(p->left);
cout << p->data << endl;
outFile << p->data << endl;
inorder(p->right);
}
}

void LinkedList::setRoot()
{
	current = root;
}

int LinkedList::find(int q)
{
	if (root->data == NULL) {
		cout << "There is no list" << endl;
		return 1;
	}
	else if (q == current->data) {
		cout << "Search query found" << endl;
		return q;
	}
	else if (q < current->data) {
		if (current->left != NULL) {
			cout << q << " is less than " << current->data << ". Traversing left." << endl;
			current = current->left;
			find(q);
			return q;
		}
		else {
			cout << "Search query not found" << endl;
			return 1;
		}
	}
	else if (q > current->data) {
		if (current->right != NULL) {
			cout << q << " is greater than " << current->data << ". Traversing right." << endl;
			current = current->right;
			find(q);
			return q;
		}
		else {
			cout << "Search query not found" << endl;
			return 1;
		}
	}
	else {
		cout << "Error" << endl;
		return 1;
	}

}




/*void LinkedList::add(int data)
{
    Node* node = new Node();
    node->data = data;
    node->next = this->head;
    this->head = node;
    this->length++;
}*/

/*void LinkedList::print()
{
    Node* head = this->head;
    int i = 1;
    while(head)
	{
        cout << i << ": " << head->data << std::endl;
        head = head->next;
        i++;
	}
}*/
