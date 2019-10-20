#include <fstream>
#include "List.h"

/**
 *@name Readfile：从文本中读入数据，以链表形式存储
 *@param1 * head_ptr：指向链表头部的指针
 *@param2 filename：文件名
 *@ret：链表的头指针
**/
node* Readfile(string filename)
{
	node* head_ptr;
	node* temp;
	ifstream in(filename,ios::in);
	temp=new node;
	head_ptr=temp;
	for (int i=0;i<500;i++)
	{
		//创建链表
		in>>temp->address;
		in>>temp->number;
		in>>temp->time;
		temp->next=new node;
		temp=temp->next;
	}
	temp->next=NULL;
	return head_ptr;
}

void main()
{
	node* temp;
	List li(Readfile("500.txt"),500);
	li.Insert_Node(2,"asd","1","2");
	//li.Delete_Node(0);
	//cout<<li.Find_Node_index(1,"asd","1","2")<<endl;
	li.Print_List();
	system("pause");
}