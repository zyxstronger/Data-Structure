#include "stack_list.h"

/**
 *@name stack_array�����캯������ʼ��top
**/
stack_list::stack_list(void)
{
	sl_top=NULL;
}


stack_list::~stack_list(void)
{
}

/**
 *@name sa_push����ջ
 *@param1 add����ջ����-��ַ
 *@param2 num����ջ����-���
 *@param3 t����ջ����-ʱ��
 *@ret���Ƿ���ջ�ɹ�
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
		//���ջ���޽ڵ� ��topֱ��ָ���½ڵ�
		sl_top=temp;
	}
	else
	{
		//���ջ���нڵ㣬���½ڵ�ָ��ջ���ڵ㣬ջ��ָ��ָ���½ڵ�
		temp->next=sl_top;
		sl_top=temp;
	}
	return true;
}

/**
 *@name sa_pop����ջ
 *@ret����ջ�Ƿ�ɹ�
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
		//����Ҫ����ֻ��һ���ڵ㣬��Ϊ��ʱ�ڵ�ָ���ָ��
		//��ֱ�ӽ�ָ��ָ���һ���ڵ㼴��
		sl_top=sl_top->next;
		return true;
	}
}

/**
 *@name Print_stack_array����ӡ����ջ�д洢������
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

