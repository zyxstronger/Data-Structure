#include <fstream>
#include "List.h"

/**
 *@name Readfile�����ı��ж������ݣ���������ʽ�洢
 *@param1 * head_ptr��ָ������ͷ����ָ��
 *@param2 filename���ļ���
 *@ret�������ͷָ��
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
		//��������
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