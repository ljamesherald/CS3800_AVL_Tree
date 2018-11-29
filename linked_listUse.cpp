#include <iostream>
#include <cstdlib>
#include <fstream>
#include "linked_list.h"

using namespace std;


int main()
{
	LinkedList();
	ifstream inFile;
	inFile.open("lots_ints.txt");
	LinkedList l;
	int f;
	int n;
		cout << "How many numbers in the list? (up to 20429)";
		cin >> n;
		for (int i = 0; i < n; i++) {
			int temp;
			inFile >> temp;
			l.root = l.insert(l.root, temp);
		}
		cout << endl << "Preorder" << endl;
		l.preorderTrav();
		cout << endl << "Postorder" << endl;
		l.postorderTrav();
		cout << endl << "Inorder" << endl;
		l.inorderTrav();
		cout << "The depth of the tree is " << l.get_depth(l.root) << "." << endl;
		
		cout << endl << "Input a number to search for" << endl;
		l.setRoot();
		cin >> f;
		l.find(f);
	inFile.close();
    return 0;
}
