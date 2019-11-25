#pragma once
typedef struct Tree_node *Search_Tree;

//定义二叉树节点的结构体
struct Tree_node
{
	int data;
	Tree_node* left;
	Tree_node* right;
};

//定义二叉树的类
class Binary_Tree
{
public:
	Binary_Tree(int data);		
	~Binary_Tree(void);
	Search_Tree Make_empty(Search_Tree T);	//删除一颗树
	Search_Tree Find_Position(int data,Search_Tree T);//查找关键字所在的树的节点，返回该节点的指针
	Search_Tree Find_Max(Search_Tree T);	//查找关键字最大的树节点
	Search_Tree Find_Min(Search_Tree T); //查找关键字最小的树节点
	Search_Tree Insert(int data,Search_Tree T);	//插入一个元素
	Search_Tree Delete(int data,Search_Tree T);	//删除关键字所在的节点
	void Print_Tree(Search_Tree T);

	Search_Tree root;								//根节点的指针
};

