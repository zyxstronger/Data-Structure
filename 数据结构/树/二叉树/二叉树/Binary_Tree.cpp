#include "includes.h"

Binary_Tree::Binary_Tree(int data)
{
	root=new Tree_node;
	root->data=data;
	root->left=root->right=NULL;
}

Binary_Tree::~Binary_Tree(void)
{
}

/**
 *@name Make_empty���ݹ�ɾ���ýڵ��Լ��ýڵ������е�����
 *@param1 T��ָ��ýڵ��ָ��
 *@ret����NULL���ظ�ɾ���ĸýڵ�
**/
Search_Tree Binary_Tree::Make_empty(Search_Tree T )
{
	//����ʹ���˵ݹ�ɾ��
	if(T!=NULL)
	{
		Make_empty(T->left);
		Make_empty(T->right);
		delete T;
		T=NULL;
	}
	return T;
}

/**
 *@name Find_Position�����ҹؼ������ڵ����Ľڵ�
 *@param1 data����Ҫƥ��Ĺؼ���
 *@param2 T������һ���ڵ㿪ʼ������ ֻ�����²���
 *@ret��ָ��ƥ�䵽�ؼ��ֵĽڵ��ָ�� û���ҵ��򷵻�NULL
**/
Search_Tree Binary_Tree::Find_Position(int data,Search_Tree T)
{
	if(T==NULL)
	{
		return NULL;	
	}

	//������ݱȸýڵ�Ĺؼ���С�Ļ�������ȥ�������в���
	if(T->data>data)
	{
		return Find_Position(data,T->left);	
	}
	//������ݱȸýڵ�Ĺؼ��ִ�Ļ�������ȥ�������в���
	else if(T->data<data)
	{
		return Find_Position(data,T->right);
	}
	else
	{
		return T;
	}
}

/**
 *@name Find_Max���ҵ��ýڵ�������������Ǹ�ֵ
 *@param1 T����������ڵ� ���Ҫ��������������ֵ������root
 *@ret��ָ������ֵ�����ڵ� Ϊ���������ұߵ�Ҷ
**/
Search_Tree Binary_Tree::Find_Max(Search_Tree T)
{
	if(T==NULL)
		return NULL;

	if(T->right==NULL)
	{
		return T;
	}
	else
	{
		return Find_Max(T->right);
	}
}

/**
 *@name Find_Max���ҵ��ýڵ����������С���Ǹ�ֵ
 *@param1 T����������ڵ� ���Ҫ������������С��ֵ������root
 *@ret��ָ������ֵ�����ڵ� Ϊ����������ߵ�Ҷ
**/
Search_Tree Binary_Tree::Find_Min(Search_Tree T)
{
	if(T==NULL)
	{
		return NULL;
	}

	if(T->left==NULL)
	{
		return T;
	}
	else
	{
		return Find_Min(T->left);
	}
}

/**
 *@name Insert�������ĺ���λ�ò���ؼ���Ϊdata�Ľڵ�
 *@param1 data�����������
 *@param2 T���ڸýڵ�������в�������
**/
Search_Tree Binary_Tree::Insert(int data,Search_Tree T)
{
	//�ݹ鵽�սڵ� ��ʱ����һ���½ڵ�
	if(T==NULL)
	{
		T=new Tree_node;
		T->data=data;
		T->left=T->right=NULL;
		return T;
	}

	//���������С�ڴ�ʱ�ڵ�����ݣ�����壨�����˸�ֵ������ڵ㣬ָ���βθı䲻�˴���Ĳ���������ȻT->left�½���һ���ڵ㣬����ʱֻ���β�ָ������
	if(T->data>data)
	{
		T->left=Insert(data,T->left);
	}
	//��������ݴ��ڴ�ʱ�ڵ�����ݣ����Ҳ�
	else if(T->data<data)
	{
		T->right=Insert(data,T->right);
	}
	//�����������ݵ��ڴ�ʱ�ڵ�����ݣ�ֱ�ӷ��ظýڵ�
	else
	{
		cout<<"can't insert the same data"<<endl;
	}
	return T;
}

/**
 *@name Delete��ɾ���ؽ���Ϊdata��Ԫ��
 *@param1 data���ؼ���
 *@param2 T���Ӹýڵ����µ�����ɾ��
**/
Search_Tree Binary_Tree::Delete(int data,Search_Tree T)
{
	Search_Tree temp;

	if(T==NULL)
		cout<<"error��without element to delete"<<endl;
	else if(T->data<data)
		T->right=Delete(data,T->right);
	else if(T->data>data)
		T->left=Delete(data,T->left);
	else
	{
		//��ʱdata����T->data
		temp=T;
		if((T->left==NULL)&&(T->right==NULL))	//��ʱ�Ľڵ�ΪҶ 
		{
			delete T;
			T=NULL;
		}
		else
		{
			if(T->left==NULL)				//��ʱ�������Ϊ�գ�ֻ��������
			{
				T=T->right;						//��Tָ���Ҷ��ӽڵ�
				delete temp;					//�ͷŸýڵ���ڴ�
				temp=NULL;
			}
			else if(T->right==NULL)	//��ʱ���Ҷ���Ϊ�գ�ֻ��������
			{
				T=T->left;						//��Tָ������ӽڵ�
				delete temp;					//�ͷŸýڵ���ڴ�
				temp=NULL;
			}
			else														//��ʱ�ȴ����������ִ���������
			{
				temp=Find_Min(T->right);			//�ҵ�����������С�Ľڵ�
				T->data=temp->data;					//���ýڵ��Ԫ�ظ�����ǰ�ڵ�
				T->right=Delete(temp->data,T->right);	//������������һ��ɾ������
			}
		}
	}
	return T;
}

/**
 *@name Print_Tree����ӡ�ýڵ㼰�������нڵ��Ԫ��
 *@param1 T�������ڵ�
**/
void Binary_Tree::Print_Tree(Search_Tree T)
{
	if(T!=NULL)
	{
		cout<<T->data<<endl;
		Print_Tree(T->left);
		Print_Tree(T->right);
	}
}