#include "includes.h"


Balance_BinaryTree::Balance_BinaryTree(int data)
{
	root=new AvlNode;
	root->data=data;
	root->right=NULL;
	root->left=NULL;
	root->height=1;
}


Balance_BinaryTree::~Balance_BinaryTree(void)
{
}

/**
 *@name Height：返回该节点的高度
**/
int Balance_BinaryTree::Height(AvlTree posi)
{
	if(posi==NULL)
		return 0;
	else
		return posi->height;
}

/**
 *@name Single_Rotate_left：单旋转 不平衡节点的左儿子上浮
**/
AvlTree Single_Rotate_left(AvlTree K2)
{
	AvlTree temp=K2->left;
	K2->left=temp->right;
	temp->right=K2;
	return temp;
}

/**
 *@name Single_Rotate_right：单旋转 不平衡节点的右儿子上浮
**/
AvlTree Single_Rotate_right(AvlTree K2)
{
	AvlTree temp=K2->right;
	K2->right=temp->left;
	temp->left=K2;
	return temp;
}

/**
 *@name Double_Rotate_left：双旋转 左儿子的右子树 
**/
AvlTree Double_Rotate_left(AvlTree K3)
{
	AvlTree temp=K3->left->right;
	K3->left->right=temp->left;
	temp->left=K3->left;
	K3->left=temp->right;
	temp->right=K3;
	return temp;
}

/**
 *@name Double_Rotate_left：双旋转 右儿子的左子树
**/
AvlTree Double_Rotate_right(AvlTree K3)
{
	AvlTree temp=K3->right->left;
	K3->right->left=temp->right;
	temp->right=K3->right;
	K3->right=temp->left;
	temp->left=K3;
	return temp;
}

/**
 *@name Max：返回两个数中大的那个
**/
int Max(int a,int b)
{
	return (a>b)? a:b;
}

/**
 *@name Insert：插入一个新的树节点 
 *@param1 data：新的树节点的数据
 *@param2 T：从该树节点向下插
 *@ret ：返回插入完成并平衡过了的该树节点
**/
AvlTree Balance_BinaryTree::Insert(int data,AvlTree T)
{
	if(T==NULL)		//如果递归到空节点的话 新建一个树节点后返回
	{
		AvlTree temp=new AvlNode;
		temp->data=data;
		temp->left=temp->right=NULL;
		temp->height=1;
		T=temp;
	}
	else
	{
		if(data<T->data)
		{
			T->left=Insert(data,T->left);
			if(Height(T->left)-Height(T->right)==2)	//此时左子树的高度比右子树的高度大2 需要平衡
			{
				if(data<T->left->data)			//此时说明插入的位置在左儿子的左子树 进行左单旋转
					T=Single_Rotate_left(T);
				else if(data>T->left->data)	//此时说明插入的位置在左儿子的右子树 进行左双旋转
					T=Double_Rotate_left(T);
			}
		}
		else if(data>T->data)
		{
			T->right=Insert(data,T->right);
			if(Height(T->right)-Height(T->left)==2)	//此时右子树的高度比左子树的高度大2 需要平衡
			{
				if(data>T->right->data)			//此时说明插入的位置在右儿子的右子树 进行右单旋转
					T=Single_Rotate_right(T);
				else if(data<T->right->data)	//此时说明插入的位置在右儿子的左子树 进行右双旋转
					T=Double_Rotate_right(T);
			}
		}
		else		//如果插入的元素相同则报错
		{
			cout<<"already have the same element"<<endl;	
		}
		T->height=Max(Height(T->left),Height(T->right))+1; //插入完成后重新计算该树节点的高度
	}
	return T;
}

/**
 *@name Print_AvlTree：遍历打印该树的所有节点的元素 中间 左 右
**/
void Balance_BinaryTree::Print_AvlTree(AvlTree T)
{
	if(T!=NULL)
	{
		cout<< T->data<<endl;
		Print_AvlTree(T->left);
		Print_AvlTree(T->right);
	}
}