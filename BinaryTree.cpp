int x = 0;//int x;//全局变量，用来记录遍历次序/递归次数
#include<iostream>
#include "BinaryTree.h"
using namespace std;//与iostream 合用
//若 没有赋值，defaut parameter space=0,t=0
void print(node *root,int space,int t) {
	//最后打印根节点，先找最右的，再同父找左的最右后代
	int count = 3;//  count 决定间隔多大，即二层数据与三层数据，竖着看相差几个空格
	if (root == NULL)
		return;//跳出此函数不必再执行
	space += count;
	print(root->right, space, 1);//此步是第一个递归，一直到最后一个right，调用了几次space就增加几次
	for (int i = count; i < space; i++)
	{

		cout << " ";//第n层打印n个空格
	}
	if (t == 1) {//t=1,代表右
		x++;
		cout << "/" << root->data << "    ----第" << x << "次打印"<<root << endl;

	}
	else if (t == 2)//代表左
	{
		x++;
		cout << "\\" << root->data << "    ---- 第" << x << "次打印" <<root<< endl;//"\\"是\
																		 		
	}
	else//根
	{
		x++;
		cout << root->data << "            ------第" << x << "次打印"<<root << endl;
	}
	print(root->left, space, 2);//第二个递归入口
}

//第一个递归入口,拔到最深右，再退到根，结果：右大子树遍历完(里面的小左子树考的是子递归里面进入了二个递归入口)。第二次递归入口，左大子树的最深右直到退到

//节点插入函数，自动按大小构造二叉树-搜索树的构造

void insert(node *root, int data)
{
	if (root == NULL)

		node *root = new node(data);

	else if (data <= root->data)

		if (root->left != NULL)
			insert(root->left, data);
		else

			root->left = new node(data);

	else if (data > root->data)

		if (root->right != NULL)
			insert(root->right, data);
		else

			root->right = new node(data);
}

node * search(node* root, int data)
{
	
	if (root == NULL) 
	{
		
		cout << "Not Found" << endl;
		return NULL;
	}
	if (root->data == data) 
	{
		cout << "Found at" << root << endl;
		return root;
	}
	if (root->data > data)
		return search(root->left, data);
	else
		return search(root->right, data);
}
