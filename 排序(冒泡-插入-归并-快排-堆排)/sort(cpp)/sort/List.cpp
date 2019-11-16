#include "List.h"


List::List(void)
{
	head=NULL;
	List_length=0;
}


List::~List(void)
{
}

//����ڵ�
void List::Insert_Node(int posi,int data)
{
	node* temp=head;
	node* new_node=new node;
	new_node->data=data;
	//�������뷶Χ
	if((posi>List_length)||(posi<0))
	{
		cout<< "insert error index is out of the range"<<endl;
	}
	//����ͷ�ڵ�
	else if(posi==0)
	{
		new_node->next=head;
		head=new_node;
		List_length++;
	}
	//���������ڵ�
	else
	{
		for (int i=0;i<posi-1;i++)
		{
			temp=temp->next;
		}
		new_node->next=temp->next;
		temp->next=new_node;
		List_length++;
	}
}

//ɾ���ڵ�
void List::Delete_Node(int posi)
{
	node* temp=head;
	node* del_temp;
	if((posi+1>List_length)||(posi<0))
	{
		cout<<" delete error index is out of the range"<<endl;
	}
	else if(posi==0)
	{
		del_temp=head;
		head=head->next;
		delete del_temp;
		List_length--;
	}
	else
	{
		for (int i=0;i<posi-1;i++)
		{
			temp=temp->next;
		}
		del_temp=temp->next;
		temp->next=(temp->next)->next;
		delete del_temp;

		List_length--;
	}
}

//��ӡ����
void List::Print_List()
{
	node* temp=head;
	cout<<"the length is "<<List_length<<endl;
	for (int i=0;i<List_length;i++)
	{
		cout<<"the List "<<i<<" is"<<temp->data<<endl;
		temp=temp->next;
	}
}

//���ص�posi���ڵ��data
int List::Find_Node(int posi)
{
	node* temp=head;
	for (int i=0;i<posi;i++)
	{
		//��ָ��ָ��Ŀ��λ�õĽڵ�
		temp=temp->next;
	}
	return temp->data;
}

//������posi1λ�ú�posi2λ�õĽڵ�
void List::Swap_Node(int posi1,int posi2)
{
	node* temp1=head;
	node* temp2=head;
	int temp_data;

	for (int i=0;i<posi1;i++)
	{
		temp1=temp1->next;
	}

	for (int i=0;i<posi2;i++)
	{
		temp2=temp2->next;
	}

	//���������ڵ������
	temp_data=temp1->data;
	temp1->data=temp2->data;
	temp2->data=temp_data;
}

//�ı�ĳһ�ڵ������
void List::Change_Node(int posi,int data)
{
	node* temp=head;

	for (int i=0;i<posi;i++)
	{
		temp=temp->next;
	}

	temp->data=data; 
}