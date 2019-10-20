#pragma once
#include "includes.h"
class queue_list
{
public:
	queue_list(void);
	~queue_list(void);
	bool En_queue_list(string add, string num,string t);
	bool Del_queue_list();
	void Print_queue_list();
	bool Read_file(string filename);
	node* ql_first;
	node* ql_last;
	int ql_total;
};

