#include "stack_list.h"

/**
 *@name stack_array：构造函数，初始化top
**/
stack_list::stack_list(void)
{
	sl_top=NULL;
}


stack_list::~stack_list(void)
{
}

/**
 *@name sa_push：入栈
 *@param1 add：入栈数据-地址
 *@param2 num：入栈数据-序号
 *@param3 t：入栈数据-时间
 *@ret：是否入栈成功
**/
bool stack_list::sl_push(string add,string num,string t)
{
	node* temp=new node;
	temp->address=add;
	temp->number=num;
	temp->time=t;
	if(sl_top==NULL)
	{
		temp->next=NULL;
		//如果栈中无节点 则top直接指向新节点
		sl_top=temp;
	}
	else
	{
		//如果栈中有节点，则新节点指向栈顶节点，栈顶指针指向新节点
		temp->next=sl_top;
		sl_top=temp;
	}
	return true;
}

/**
 *@name sa_pop：出栈
 *@ret：出栈是否成功
**/
bool stack_list::sl_pop()
{
	if(sl_top==NULL)
	{
		cout<<"the stack is empty"<<endl;
		return false;
	}
	else
	{
		//不需要考虑只有一个节点，因为此时节点指向空指针
		//故直接将指针指向后一个节点即可
		sl_top=sl_top->next;
		return true;
	}
}

/**
 *@name Print_stack_array：打印所有栈中存储的数据
**/
void stack_list::Print_stack_list()
{
	node *i=sl_top;
	if(sl_top==NULL)
	{
		cout<<"the stack is empty"<<endl;
		return;
	}
	else
	{
		while(i!=NULL)
		{
			cout<<i->address<<" ";
			cout<<i->number<<" ";
			cout<<i->time<<endl;
			i=i->next;
		}
	}
}

