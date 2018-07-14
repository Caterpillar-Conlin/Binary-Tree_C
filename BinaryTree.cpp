// Binary Tree.cpp: 定义控制台应用程序的入口点。
//
int x;//全局变量，用来记录遍历次序/递归次数
#include<iostream>
using namespace std;

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
//if 没有赋值，defaut parameter space=0,t=0

void print(node *root, int space = 0, int t = 0) {
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
		cout << "/"<<root->data<<"    ----第"<<x<<"次打印"<<endl;

	}
	else if (t==2)//代表左
	{
		x++;
		cout << "\\" << root->data << "    ---- 第" << x << "次打印" << endl;//"\\"是\
		
	}
	else//根
	{
		x++;
		cout << root -> data << "            ------第" << x << "次打印" << endl;
	}
	print(root->left, space, 2);//第二个递归入口
}

//第一个递归入口,拔到最深右，再退到根，结果：右大子树遍历完(里面的小左子树考的是子递归里面进入了二个递归入口)。第二次递归入口，左大子树的最深右直到退到


int main()
{
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	root->right->right ->right = new node(8);
	print(root);
	system("pause");
    return 0;
}

