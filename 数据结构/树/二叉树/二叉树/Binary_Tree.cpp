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
 *@name Make_empty：递归删除该节点以及该节点下所有的子树
 *@param1 T：指向该节点的指针
 *@ret：将NULL返回给删除的该节点
**/
Search_Tree Binary_Tree::Make_empty(Search_Tree T )
{
	//这里使用了递归删除
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
 *@name Find_Position：查找关键字所在的树的节点
 *@param1 data：需要匹配的关键字
 *@param2 T：从哪一个节点开始往下找 只会向下查找
 *@ret：指向匹配到关键字的节点的指针 没有找到则返回NULL
**/
Search_Tree Binary_Tree::Find_Position(int data,Search_Tree T)
{
	if(T==NULL)
	{
		return NULL;	
	}

	//如果数据比该节点的关键字小的话，查找去左子树中查找
	if(T->data>data)
	{
		return Find_Position(data,T->left);	
	}
	//如果数据比该节点的关键字大的话，查找去右子树中查找
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
 *@name Find_Max：找到该节点的子树中最大的那个值
 *@param1 T：传入的树节点 如果要找整根树中最大的值则输入root
 *@ret：指向存最大值的树节点 为子树中最右边的叶
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
 *@name Find_Max：找到该节点的子树中最小的那个值
 *@param1 T：传入的树节点 如果要找整根树中最小的值则输入root
 *@ret：指向存最大值的树节点 为子树中最左边的叶
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
 *@name Insert：在树的合适位置插入关键字为data的节点
 *@param1 data：插入的数据
 *@param2 T：在该节点的子树中插入数据
**/
Search_Tree Binary_Tree::Insert(int data,Search_Tree T)
{
	//递归到空节点 这时建立一个新节点
	if(T==NULL)
	{
		T=new Tree_node;
		T->data=data;
		T->left=T->right=NULL;
		return T;
	}

	//插入的数据小于此时节点的数据，往左插（别忘了赋值给子左节点，指针形参改变不了传入的参数，即虽然T->left新建了一个节点，但此时只有形参指向它）
	if(T->data>data)
	{
		T->left=Insert(data,T->left);
	}
	//插入的数据大于此时节点的数据，往右插
	else if(T->data<data)
	{
		T->right=Insert(data,T->right);
	}
	//如果插入的数据等于此时节点的数据，直接返回该节点
	else
	{
		cout<<"can't insert the same data"<<endl;
	}
	return T;
}

/**
 *@name Delete：删除关节字为data的元素
 *@param1 data：关键字
 *@param2 T：从该节点以下的树中删除
**/
Search_Tree Binary_Tree::Delete(int data,Search_Tree T)
{
	Search_Tree temp;

	if(T==NULL)
		cout<<"error：without element to delete"<<endl;
	else if(T->data<data)
		T->right=Delete(data,T->right);
	else if(T->data>data)
		T->left=Delete(data,T->left);
	else
	{
		//此时data等于T->data
		temp=T;
		if((T->left==NULL)&&(T->right==NULL))	//此时的节点为叶 
		{
			delete T;
			T=NULL;
		}
		else
		{
			if(T->left==NULL)				//此时的左儿子为空，只有右子树
			{
				T=T->right;						//将T指向右儿子节点
				delete temp;					//释放该节点的内存
				temp=NULL;
			}
			else if(T->right==NULL)	//此时的右儿子为空，只有左子树
			{
				T=T->left;						//将T指向左儿子节点
				delete temp;					//释放该节点的内存
				temp=NULL;
			}
			else														//此时既存在左子树又存在右子树
			{
				temp=Find_Min(T->right);			//找到右子树中最小的节点
				T->data=temp->data;					//将该节点的元素赋给当前节点
				T->right=Delete(temp->data,T->right);	//对右子树进行一次删除操作
			}
		}
	}
	return T;
}

/**
 *@name Print_Tree：打印该节点及以下所有节点的元素
 *@param1 T：给定节点
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