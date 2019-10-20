#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
	string address;
	string number;
	string time;
	node* next;
};

class List
{
public:
	List(node* head_ptr,int number);																		//���캯������ʼ��ͷָ���������
	~List(void);
	void Print_List();																									//��ӡ����
	void Insert_Node(int posi,string address,string number,string time);			//����ڵ�
	void Delete_Node(int posi);																				//ɾ���ڵ�
	int Find_Node_index(int count,string address,string number,string time);	//���ҽڵ�
	node* head;																										//ͷָ��
	int List_length;																									//������
};

