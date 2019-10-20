#pragma once
#include "includes.h"
class stack_list
{
public:
	stack_list(void);
	~stack_list(void);
	bool sl_push(string add,string num,string t);
	bool sl_pop();
	void Print_stack_list();
	node* sl_top;
};

