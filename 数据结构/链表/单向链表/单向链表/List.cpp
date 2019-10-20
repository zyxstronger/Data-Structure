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
 *@name Print_List：打印链表
 *@ret：None
**/
void List::Print_List()
{
	node* temp=head;
	for (int i=0;i<List_length;i++)
	{
		//打印出一个节点的三个数据
		cout<<temp->address<<" "<<temp->number<<" "<<temp->time<<endl;
		//指针指向下一个指针
		temp=temp->next;
	}
}

/**
 *@name Insert_List：插入一个节点
 *@param1 address：节点的第一个数据-地址
 *@param2 number：节点的第二个数据-序号
 *@param3 time：时间
**/
void List::Insert_Node(int posi,string address,string number,string time)
{
	//定义一个遍历指针
	node* temp=head;
	if(posi<0)
	{
		cout<<"error,index<0"<<endl;
		return;
	}

	//插入新的节点
	for (int i=0;i<posi-1;i++)
	{
		temp=temp->next;
	}
	//此时已经temp指向了第posi-1个节点
	//创建一个新的节点
	node* new_node=new node;
	new_node->address=address;
	new_node->number=number;
	new_node->time=time;

	//如果在头部加入，则需要重新确定头部，否则头部指针将指向第一个节点
	if(posi==0)
	{
		head=new_node;
		new_node->next=temp;
	}
	else
	{
		//在新节点后面挂上原来第posi个节点以及后面的节点
		new_node->next=temp->next;
		//第posi个节点由新的节点代替
		temp->next=new_node;
	}

	//节点个数自加1
	List_length++;


	//int currIndex = 1;
	//node* currNode = head;
	////索引初始值设为1，currNode会迭代到index处
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
	////在第index个节点后面插入
	//else 
	//{
	//	newNode->next = currNode->next;
	//	currNode->next = newNode;
	//}
}

/**
 *@name Delete_Node：删除节点
 *@param1 posi：所要删除的节点的位置
**/
void List::Delete_Node(int posi)
{
	//定义一个遍历指针
	node* temp=head;
	node* temp_del;
	if(posi<0)
	{
		cout<<"error,index<0"<<endl;
		return;
	}

	//删除节点
	for (int i=0;i<posi-1;i++)
	{
		temp=temp->next;
	}
	//此时遍历指针来到了posi-1的节点
	if(posi==0)
	{
		head=temp->next;
		delete temp;
	}
	else
	{
		//将第posi个节点删除
		temp_del=temp->next;
		temp->next=temp->next->next;
		//释放内存
		delete temp_del;
	}

	//节点个数自减1
	List_length--;
}


/**
 *@name Find_Node_index：查找节点中数据对应的索引号
 *@param1  count：查找的值 1-地址 2-序号 3-时间
 *@param2 add：查找的地址值
 *@param3 num：查找的序号
 *@param4 t：查找的时间
**/
int List::Find_Node_index(int count,string add,string num,string t)
{
	node* temp=head;
	int i;
	//查找address
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

	//查找number
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

	//查找时间
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
