#include "queue_list.h"

/**
 *@name queue：构造函数，初始化first和last以及total
**/
queue_list::queue_list(void)
{
	//初始化链表 first和last都为空指针
	ql_first=NULL;
	ql_last=NULL;
	ql_total=0;
}

queue_list::~queue_list(void)
{
}

/**
 *@name En_queue：在队列尾部插入新的数据节点
 *@param1 add：插入数据节点——地址
 *@param2 num：插入数据节点——序号
 *@param3 t：插入数据节点——时间
 *@ret：是否插入成功
**/
bool queue_list::En_queue_list(string add, string num,string t)
{
	node *temp=new node;
	temp->address=add;
	temp->number=num;
	temp->time=t;
	if(ql_first==NULL)
	{
		//队列中还没有节点存在时，将first和last同时指向创建的节点
		ql_first=temp;
		ql_last=temp;
		ql_total++;
	}
	else
	{
		//将尾节点指向新节点，同时last指向新节点
		ql_last->next=temp;
		ql_last=temp;
		ql_total++;
	}
	return true;
}

/**
 *@name Del_queue：删除队列首部节点
 *@ret 是否删除成功
**/
bool queue_list::Del_queue_list()
{
	if(ql_first==NULL)
	{
		cout<<"have no data to delete"<<endl;
		return false;
	}
	else if(ql_first==ql_last)
	{
		//只有一个节点时，直接将first和last都指向NULL
		ql_first==NULL;
		ql_last=NULL;
		ql_total--;
		return true;
	}
	else
	{
		//存在多个节点时，将first向后移一个节点
		ql_first=ql_first->next;
		ql_total--;
		return true;
	}
}

/**
 *@name Print_queue：打印队列所有数据
 *@ret None
**/
void queue_list::Print_queue_list()
{
	node* i=ql_first;
	cout<<"the number of  queue_list is "<<ql_total<<endl;
	for (int j=ql_total;j>0;j--)
	{
		//输出节点数据并移到下一个节点
		cout<<i->address<<" "<<i->number<<" "<<i->time<<endl;
		i=i->next;	
	}
}

/**
 *@name Read_file：从文件中读取数据插入队列，共500个数据
 *@param1 filename：文件名
**/
bool queue_list::Read_file(string filename)
{
	ifstream in(filename,ios::in);
	//从文件流中读取数据存入中间变量
	string temp_add;
	string temp_num;
	string temp_t;
	for(int i=0;i<500;i++)
	{
		in>>temp_add;
		in>>temp_num;
		in>>temp_t;
		if(!En_queue_list(temp_add, temp_num,temp_t))
			return false;
	}
	return true;
}