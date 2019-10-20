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
	List(node* head_ptr,int number);																		//构造函数，初始化头指针和链表长度
	~List(void);
	void Print_List();																									//打印链表
	void Insert_Node(int posi,string address,string number,string time);			//插入节点
	void Delete_Node(int posi);																				//删除节点
	int Find_Node_index(int count,string address,string number,string time);	//查找节点
	node* head;																										//头指针
	int List_length;																									//链表长度
};

