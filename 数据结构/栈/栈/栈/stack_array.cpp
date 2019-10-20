#include "stack_array.h"

/**
 *@name stack_array：构造函数，初始化top
**/
stack_array::stack_array(void)
{
	sa_top=-1;
}


stack_array::~stack_array(void)
{
}

/**
 *@name sa_push：入栈
 *@param1 add：入栈数据-地址
 *@param2 num：入栈数据-序号
 *@param3 t：入栈数据-时间
 *@ret：是否入栈成功
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
		//如果栈没有满则往栈中推入一个数据
		sa_top++;
		sa_table[sa_top][0]=add;
		sa_table[sa_top][1]=num;
		sa_table[sa_top][2]=t;
		return true;
	}
}

/**
 *@name sa_pop：出栈
 *@ret：出栈是否成功
**/
bool stack_array::sa_pop()
{
	if(sa_top==-1)
	{
		//此时栈空
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
 *@name Print_stack_array：打印所有栈中存储的数据
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
			//从栈顶开始输出
			cout<<sa_table[i][0]<<" ";
			cout<<sa_table[i][1]<<" ";
			cout<<sa_table[i][2]<<endl;
		}
	}
}

/**
 *@name Read_file：读取文件中的数据，存入栈中
 *@param1 filename：文件名
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


