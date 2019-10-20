#include "queue_list.h"

/**
 *@name queue�����캯������ʼ��first��last�Լ�total
**/
queue_list::queue_list(void)
{
	//��ʼ������ first��last��Ϊ��ָ��
	ql_first=NULL;
	ql_last=NULL;
	ql_total=0;
}

queue_list::~queue_list(void)
{
}

/**
 *@name En_queue���ڶ���β�������µ����ݽڵ�
 *@param1 add���������ݽڵ㡪����ַ
 *@param2 num���������ݽڵ㡪�����
 *@param3 t���������ݽڵ㡪��ʱ��
 *@ret���Ƿ����ɹ�
**/
bool queue_list::En_queue_list(string add, string num,string t)
{
	node *temp=new node;
	temp->address=add;
	temp->number=num;
	temp->time=t;
	if(ql_first==NULL)
	{
		//�����л�û�нڵ����ʱ����first��lastͬʱָ�򴴽��Ľڵ�
		ql_first=temp;
		ql_last=temp;
		ql_total++;
	}
	else
	{
		//��β�ڵ�ָ���½ڵ㣬ͬʱlastָ���½ڵ�
		ql_last->next=temp;
		ql_last=temp;
		ql_total++;
	}
	return true;
}

/**
 *@name Del_queue��ɾ�������ײ��ڵ�
 *@ret �Ƿ�ɾ���ɹ�
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
		//ֻ��һ���ڵ�ʱ��ֱ�ӽ�first��last��ָ��NULL
		ql_first==NULL;
		ql_last=NULL;
		ql_total--;
		return true;
	}
	else
	{
		//���ڶ���ڵ�ʱ����first�����һ���ڵ�
		ql_first=ql_first->next;
		ql_total--;
		return true;
	}
}

/**
 *@name Print_queue����ӡ������������
 *@ret None
**/
void queue_list::Print_queue_list()
{
	node* i=ql_first;
	cout<<"the number of  queue_list is "<<ql_total<<endl;
	for (int j=ql_total;j>0;j--)
	{
		//����ڵ����ݲ��Ƶ���һ���ڵ�
		cout<<i->address<<" "<<i->number<<" "<<i->time<<endl;
		i=i->next;	
	}
}

/**
 *@name Read_file�����ļ��ж�ȡ���ݲ�����У���500������
 *@param1 filename���ļ���
**/
bool queue_list::Read_file(string filename)
{
	ifstream in(filename,ios::in);
	//���ļ����ж�ȡ���ݴ����м����
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