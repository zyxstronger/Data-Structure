#pragma once
typedef struct AvlNode* AvlTree;

struct AvlNode
{
	int data;
	AvlNode* left;
	AvlNode* right;
	int height;
};

class Balance_BinaryTree
{
	public:
		Balance_BinaryTree(int data);
		~Balance_BinaryTree(void);
		int Height(AvlTree posi);
		AvlTree Insert(int data,AvlTree T);
		void Print_AvlTree(AvlTree T);

		AvlTree root;
};

