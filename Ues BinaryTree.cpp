
#include<iostream>
#include "BinaryTree.h"
using namespace std;
int main()
{
	node *root = new node(5);
	insert(root, 3);
	insert(root, 8);
	insert(root, 1);
	insert(root, 4);
	insert(root, 7);
	insert(root, 9);
	insert(root, 0);
	insert(root, 2);
	insert(root, 6);
	insert(root,10);
	
	search(root,10);
	print(root);
	system("pause");
    return 0;
    delete[] root;
}

