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
	root = NULL;
	int depth = 0;
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


Node *LinkedList::insert(Node *root, int value)
{
    if (root == NULL)
    {
        root = new Node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance(root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        root = balance(root);
    }
    return root;
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
cout << p->data <<  endl;
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

int LinkedList::get_depth(Node* n)
{
		if(n == NULL)
        {
                return 0;
        }
		else if(n->left == NULL && n->right == NULL)
		{
			return 0;
		}
		else
		{
			int left_depth = get_depth(n->left);
			int right_depth = get_depth(n->right);
			
			if(left_depth > right_depth)
				return(left_depth + 1);
			else
				return(right_depth + 1);
		}
}
		
int LinkedList::depthDiff(Node *temp)
{
    int l_depth = get_depth(temp->left);
    int r_depth = get_depth(temp->right);
    int depthDifference = l_depth - r_depth;
    return depthDifference;
}

		
Node *LinkedList::rotateLeft(Node* n2)
{
	Node *n1 = n2->left;
	n2->left = n1->right;
	n1->right = n2;
	return n1;
}

Node *LinkedList::doubleRotateLeft(Node* n3)
{
	Node* n2 = n3->left;
	n3->left = rotateRight(n2);
	return rotateRight(n3);
}
	
Node *LinkedList::rotateRight(Node* n2)
{
	Node *n1 = n2->right;
	n2->right = n1->left;
	n1->left = n2;
	return n1;
}	
	
Node *LinkedList::doubleRotateRight(Node* n3)
{
		Node* n2 = n3->right;
		n3->right = rotateLeft(n2);
		return rotateRight(n3);
}

	
Node *LinkedList::balance(Node* n)
{
	int depthDifference = depthDiff(n);
    if (depthDifference > 1)
    {
        if (depthDiff(n->left) > 0)
            n = rotateLeft(n);
        else
            n = doubleRotateLeft(n);
    }
    else if (depthDifference < -1)
    {
        if (depthDiff(n->right) > 0)
            n = doubleRotateRight(n);
        else
            n = rotateRight(n);
    }
    return n;

}
		
		

