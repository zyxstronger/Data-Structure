#include "stack_array.h"

/**
 *@name stack_array�����캯������ʼ��top
**/
stack_array::stack_array(void)
{
	sa_top=-1;
}


stack_array::~stack_array(void)
{
}

/**
 *@name sa_push����ջ
 *@param1 add����ջ����-��ַ
 *@param2 num����ջ����-���
 *@param3 t����ջ����-ʱ��
 *@ret���Ƿ���ջ�ɹ�
**/
bool stack_array::sa_push(string add,string num,string t)
{
	if(sa_top==N-1)
	{
		cout<<"the stack is full"<<endl;
		return false;
	}
	else
	{
		//���ջû��������ջ������һ������
		sa_top++;
		sa_table[sa_top][0]=add;
		sa_table[sa_top][1]=num;
		sa_table[sa_top][2]=t;
		return true;
	}
}

/**
 *@name sa_pop����ջ
 *@ret����ջ�Ƿ�ɹ�
**/
bool stack_array::sa_pop()
{
	if(sa_top==-1)
	{
		//��ʱջ��
		cout<<"the stack is empty"<<endl;
		return false;
	}
	else
	{
		sa_top--;
		return true;
	}
}

/**
 *@name Print_stack_array����ӡ����ջ�д洢������
**/
void stack_array::Print_stack_array()
{
	if(sa_top==-1)
	{
		cout<<"the stack is empty"<<endl;
		return;
	}
	else
	{
		cout<<"the number of stack data is "<<sa_top+1<<endl;
		for (int i=sa_top;i>=0;i--)
		{
			//��ջ����ʼ���
			cout<<sa_table[i][0]<<" ";
			cout<<sa_table[i][1]<<" ";
			cout<<sa_table[i][2]<<endl;
		}
	}
}

/**
 *@name Read_file����ȡ�ļ��е����ݣ�����ջ��
 *@param1 filename���ļ���
**/
void stack_array::Read_file(string filename)
{
	ifstream in(filename,ios::in);
	string temp_add;
	string temp_num;
	string temp_t;
	for (int i=0;i<500;i++)
	{
		in>>temp_add;
		in>>temp_num;
		in>>temp_t;
		if(!sa_push(temp_add,temp_num,temp_t))
			return;
	}
}


