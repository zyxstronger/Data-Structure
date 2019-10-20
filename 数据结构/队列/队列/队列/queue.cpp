#include "queue.h"

/**
 *@name queue�����캯������ʼ��first��last�Լ�total
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
 *@name En_queue���ڶ���β����������
 *@param1 add���������ݡ�����ַ
 *@param2 num���������ݡ������
 *@param3 t���������ݡ���ʱ��
 *@ret���Ƿ����ɹ�
**/
bool	queue::En_queue(string add,string num,string t)
{
	if(q_total==N)
	{
		//��ʱ��������
		cout<<"the queue is full"<<endl;
		return false;
	}
	else
	{
		//���ζ��У���β����1��ȡ�࣬��ͷβ������
		q_last=(q_last+1)%N;
		q_table[q_last][0]=add;
		q_table[q_last][1]=num;
		q_table[q_last][2]=t;
		//�����е����ݼ�1
		q_total++;
		return true;
	}
}

/**
 *@name Del_queue��ɾ�������ײ�����
 *@ret �Ƿ�ɾ���ɹ�
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
		//��ͷ������һ����λ
		q_first=(q_first+1)%N;
		//�����е����ݼ�1
		q_total--;
		return true;
	}
}

/**
 *@name Print_queue����ӡ������������
 *@ret None
**/
void queue::Print_queue()
{
	int i,j;
	if(q_total>0)
	{
		i=q_first;
		//���ȴ�ӡ��������������
		cout<<"the number of  queue is "<<q_total<<endl;
		//���ö������������������Ʊ�������
		for(j=q_total;j>0;j--)
		{
			for(int k=0;k<3;k++)
			{
				//�ֱ��ӡÿһ�����е�����
				cout<<q_table[i][k]<<" ";
			}
			cout<<endl;
			//i��first��ʼ��������
			i=(i+1)%N;
		}
	}
	else
	{
		cout<<"full queue"<<endl;
	}
}

/**
 *@name Read_file�����ļ��ж�ȡ���ݲ�����У���500������
 *@param1 filename���ļ���
**/
bool queue::Read_file(string filename)
{
	ifstream in(filename,ios::in);
	int i,j;
	//���ļ����ж�ȡ���ݴ����м����
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