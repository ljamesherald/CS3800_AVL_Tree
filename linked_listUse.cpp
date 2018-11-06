#include <iostream>
#include <cstdlib>
#include <fstream>
#include "linked_list.h"

using namespace std;


int main()
{
	LinkedList();
       // int test[20429];
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
			l.insert(temp);
		}
		cout << endl << "Preorder" << endl;
		l.preorderTrav();
		cout << endl << "Postorder" << endl;
		l.postorderTrav();
		cout << endl << "Inorder" << endl;
		l.inorderTrav();
		cout << endl << "Input a number to search for" << endl;
		l.setRoot();
		cin >> f;
		l.find(f);


	/*for (int i = 0; i < 20429; i++){
		inFile >> test[i];
	}
        for (int j = 0; j < 20429; j++){
		cout << test[j] << endl;
	}*/
	inFile.close();
    return 0;
}
