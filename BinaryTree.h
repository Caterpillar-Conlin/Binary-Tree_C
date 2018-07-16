#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#include <stdio.h>
class node {
public:
	int data;
	node *left;
	node*right;
	node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;

	}

};

//若没有赋值，defaut parameter space=0,t=0
node *search(node *root, int data);//搜索
void print(node *root, int space = 0, int t = 0); //中序遍历

void insert(node *root, int data);//按大小构造搜索树


#endif 
