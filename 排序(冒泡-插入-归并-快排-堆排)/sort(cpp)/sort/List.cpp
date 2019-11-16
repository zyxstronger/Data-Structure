#include "List.h"


List::List(void)
{
	head=NULL;
	List_length=0;
}


List::~List(void)
{
}

//插入节点
void List::Insert_Node(int posi,int data)
{
	node* temp=head;
	node* new_node=new node;
	new_node->data=data;
	//超出插入范围
	if((posi>List_length)||(posi<0))
	{
		cout<< "insert error index is out of the range"<<endl;
	}
	//插入头节点
	else if(posi==0)
	{
		new_node->next=head;
		head=new_node;
		List_length++;
	}
	//插入其他节点
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

//删除节点
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

//打印链表
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

//返回第posi个节点的data
int List::Find_Node(int posi)
{
	node* temp=head;
	for (int i=0;i<posi;i++)
	{
		//将指针指向目标位置的节点
		temp=temp->next;
	}
	return temp->data;
}

//交换第posi1位置和posi2位置的节点
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

	//交换两个节点的数据
	temp_data=temp1->data;
	temp1->data=temp2->data;
	temp2->data=temp_data;
}

//改变某一节点的数据
void List::Change_Node(int posi,int data)
{
	node* temp=head;

	for (int i=0;i<posi;i++)
	{
		temp=temp->next;
	}

	temp->data=data; 
}