#include "List.h"

List::List(node* head_ptr,int number)
{
	head=head_ptr;
	List_length=number;
}

List::~List(void)
{
	node* temp_curr=head;
	node* temp_next=NULL;

	while(temp_curr!=NULL)
	{
		temp_next=temp_curr->next;
		delete temp_curr;
		temp_curr=temp_next;
	}
}

/**
 *@name Print_List����ӡ����
 *@ret��None
**/
void List::Print_List()
{
	node* temp=head;
	for (int i=0;i<List_length;i++)
	{
		//��ӡ��һ���ڵ����������
		cout<<temp->address<<" "<<temp->number<<" "<<temp->time<<endl;
		//ָ��ָ����һ��ָ��
		temp=temp->next;
	}
}

/**
 *@name Insert_List������һ���ڵ�
 *@param1 address���ڵ�ĵ�һ������-��ַ
 *@param2 number���ڵ�ĵڶ�������-���
 *@param3 time��ʱ��
**/
void List::Insert_Node(int posi,string address,string number,string time)
{
	//����һ������ָ��
	node* temp=head;
	if(posi<0)
	{
		cout<<"error,index<0"<<endl;
		return;
	}

	//�����µĽڵ�
	for (int i=0;i<posi-1;i++)
	{
		temp=temp->next;
	}
	//��ʱ�Ѿ�tempָ���˵�posi-1���ڵ�
	//����һ���µĽڵ�
	node* new_node=new node;
	new_node->address=address;
	new_node->number=number;
	new_node->time=time;

	//�����ͷ�����룬����Ҫ����ȷ��ͷ��������ͷ��ָ�뽫ָ���һ���ڵ�
	if(posi==0)
	{
		head=new_node;
		new_node->next=temp;
	}
	else
	{
		//���½ڵ�������ԭ����posi���ڵ��Լ�����Ľڵ�
		new_node->next=temp->next;
		//��posi���ڵ����µĽڵ����
		temp->next=new_node;
	}

	//�ڵ�����Լ�1
	List_length++;


	//int currIndex = 1;
	//node* currNode = head;
	////������ʼֵ��Ϊ1��currNode�������index��
	//while (currNode && posi > currIndex)
	//{
	//	currNode = currNode->next;
	//	currIndex++;
	//}

	//node* newNode = new node;
	//newNode->address = address;
	//if (posi == 0)
	//{
	//	newNode->next = head;
	//	head = newNode;
	//}
	////�ڵ�index���ڵ�������
	//else 
	//{
	//	newNode->next = currNode->next;
	//	currNode->next = newNode;
	//}
}

/**
 *@name Delete_Node��ɾ���ڵ�
 *@param1 posi����Ҫɾ���Ľڵ��λ��
**/
void List::Delete_Node(int posi)
{
	//����һ������ָ��
	node* temp=head;
	node* temp_del;
	if(posi<0)
	{
		cout<<"error,index<0"<<endl;
		return;
	}

	//ɾ���ڵ�
	for (int i=0;i<posi-1;i++)
	{
		temp=temp->next;
	}
	//��ʱ����ָ��������posi-1�Ľڵ�
	if(posi==0)
	{
		head=temp->next;
		delete temp;
	}
	else
	{
		//����posi���ڵ�ɾ��
		temp_del=temp->next;
		temp->next=temp->next->next;
		//�ͷ��ڴ�
		delete temp_del;
	}

	//�ڵ�����Լ�1
	List_length--;
}


/**
 *@name Find_Node_index�����ҽڵ������ݶ�Ӧ��������
 *@param1  count�����ҵ�ֵ 1-��ַ 2-��� 3-ʱ��
 *@param2 add�����ҵĵ�ֵַ
 *@param3 num�����ҵ����
 *@param4 t�����ҵ�ʱ��
**/
int List::Find_Node_index(int count,string add,string num,string t)
{
	node* temp=head;
	int i;
	//����address
	if(count==1)
	{
		for (i=0;i<List_length;i++)
		{
			if((temp->address)==add)
				break;
			temp=temp->next;
		}
		if(i!=List_length)
			return i;
		else
		{
			cout<<"not found address"<<endl;
			return -1;
		}
	}

	//����number
	else if(count==2)
	{
		for (i=0;i<List_length;i++)
		{
			if((temp->number)==num)
				break;
			temp=temp->next;
		}
		if(i!=List_length)
			return i;
		else
		{
			cout<<"not found number"<<endl;
			return -1;
		}
	}

	//����ʱ��
	else if(count==3)
	{
		for (i=0;i<List_length;i++)
		{
			if((temp->time)==t)
				break;
			temp=temp->next;
		}
		if(i!=List_length)
			return i;
		else
		{
			cout<<"not found time"<<endl;
			return -1;
		}
	}
}
