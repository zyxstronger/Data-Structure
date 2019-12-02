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
 *@name Height�����ظýڵ�ĸ߶�
**/
int Balance_BinaryTree::Height(AvlTree posi)
{
	if(posi==NULL)
		return 0;
	else
		return posi->height;
}

/**
 *@name Single_Rotate_left������ת ��ƽ��ڵ��������ϸ�
**/
AvlTree Single_Rotate_left(AvlTree K2)
{
	AvlTree temp=K2->left;
	K2->left=temp->right;
	temp->right=K2;
	return temp;
}

/**
 *@name Single_Rotate_right������ת ��ƽ��ڵ���Ҷ����ϸ�
**/
AvlTree Single_Rotate_right(AvlTree K2)
{
	AvlTree temp=K2->right;
	K2->right=temp->left;
	temp->left=K2;
	return temp;
}

/**
 *@name Double_Rotate_left��˫��ת ����ӵ������� 
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
 *@name Double_Rotate_left��˫��ת �Ҷ��ӵ�������
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
 *@name Max�������������д���Ǹ�
**/
int Max(int a,int b)
{
	return (a>b)? a:b;
}

/**
 *@name Insert������һ���µ����ڵ� 
 *@param1 data���µ����ڵ������
 *@param2 T���Ӹ����ڵ����²�
 *@ret �����ز�����ɲ�ƽ����˵ĸ����ڵ�
**/
AvlTree Balance_BinaryTree::Insert(int data,AvlTree T)
{
	if(T==NULL)		//����ݹ鵽�սڵ�Ļ� �½�һ�����ڵ�󷵻�
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
			if(Height(T->left)-Height(T->right)==2)	//��ʱ�������ĸ߶ȱ��������ĸ߶ȴ�2 ��Ҫƽ��
			{
				if(data<T->left->data)			//��ʱ˵�������λ��������ӵ������� ��������ת
					T=Single_Rotate_left(T);
				else if(data>T->left->data)	//��ʱ˵�������λ��������ӵ������� ������˫��ת
					T=Double_Rotate_left(T);
			}
		}
		else if(data>T->data)
		{
			T->right=Insert(data,T->right);
			if(Height(T->right)-Height(T->left)==2)	//��ʱ�������ĸ߶ȱ��������ĸ߶ȴ�2 ��Ҫƽ��
			{
				if(data>T->right->data)			//��ʱ˵�������λ�����Ҷ��ӵ������� �����ҵ���ת
					T=Single_Rotate_right(T);
				else if(data<T->right->data)	//��ʱ˵�������λ�����Ҷ��ӵ������� ������˫��ת
					T=Double_Rotate_right(T);
			}
		}
		else		//��������Ԫ����ͬ�򱨴�
		{
			cout<<"already have the same element"<<endl;	
		}
		T->height=Max(Height(T->left),Height(T->right))+1; //������ɺ����¼�������ڵ�ĸ߶�
	}
	return T;
}

/**
 *@name Print_AvlTree��������ӡ���������нڵ��Ԫ�� �м� �� ��
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