#pragma once
#include <string>
#include <iostream>
using namespace std;

//����ڵ�ṹ��
struct node
{
	int data;
	node* next;
};

class List
{
public:
	List(void);
	~List(void);
	void Insert_Node(int posi,int data);
	void Delete_Node(int posi);
	void Print_List();
	int Find_Node(int posi);
	void Change_Node(int posi,int data);
	void Swap_Node(int posi1,int posi2);

	//����ͷ�ڵ�
	node* head;

	//��������ĳ���
	long int List_length;
};

