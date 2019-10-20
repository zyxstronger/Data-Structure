#include "queue.h"

/**
 *@name queue：构造函数，初始化first和last以及total
**/
queue::queue(void)
{
	q_first=0;
	q_last=N-1;
	q_total=0;
}

queue::~queue(void)
{

}

/**
 *@name En_queue：在队列尾部插入数据
 *@param1 add：插入数据——地址
 *@param2 num：插入数据——序号
 *@param3 t：插入数据——时间
 *@ret：是否插入成功
**/
bool	queue::En_queue(string add,string num,string t)
{
	if(q_total==N)
	{
		//此时队列已满
		cout<<"the queue is full"<<endl;
		return false;
	}
	else
	{
		//环形队列，故尾部加1后取余，将头尾串起来
		q_last=(q_last+1)%N;
		q_table[q_last][0]=add;
		q_table[q_last][1]=num;
		q_table[q_last][2]=t;
		//队列中的数据加1
		q_total++;
		return true;
	}
}

/**
 *@name Del_queue：删除队列首部数据
 *@ret 是否删除成功
**/
bool queue::Del_queue()
{
	if(q_total==0)
	{
		cout<<"no data can be delete"<<endl;
		return false;
	}
	else
	{
		//将头部后移一个单位
		q_first=(q_first+1)%N;
		//队列中的数据减1
		q_total--;
		return true;
	}
}

/**
 *@name Print_queue：打印队列所有数据
 *@ret None
**/
void queue::Print_queue()
{
	int i,j;
	if(q_total>0)
	{
		i=q_first;
		//首先打印队列中数据数量
		cout<<"the number of  queue is "<<q_total<<endl;
		//利用队列中数据数量来控制遍历次数
		for(j=q_total;j>0;j--)
		{
			for(int k=0;k<3;k++)
			{
				//分别打印每一个队列的数据
				cout<<q_table[i][k]<<" ";
			}
			cout<<endl;
			//i从first开始遍历队列
			i=(i+1)%N;
		}
	}
	else
	{
		cout<<"full queue"<<endl;
	}
}

/**
 *@name Read_file：从文件中读取数据插入队列，共500个数据
 *@param1 filename：文件名
**/
bool queue::Read_file(string filename)
{
	ifstream in(filename,ios::in);
	int i,j;
	//从文件流中读取数据存入中间变量
	string temp_add;
	string temp_num;
	string temp_t;
	if(!in.is_open())
	{
		cout<<"error"<<endl;
	}
	else
	{
		for(i=0;i<500;i++)
		{
			in>>temp_add;
			in>>temp_num;
			in>>temp_t;
			if(!En_queue(temp_add,temp_num,temp_t))
			{
				return false;
			}
		}
	}
	in.close();
	return true;
}