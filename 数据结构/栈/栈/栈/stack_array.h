#pragma once
#include "includes.h"
#define N 500
class stack_array
{
public:
	stack_array(void);
	~stack_array(void);
	bool sa_push(string add,string num,string t);
	bool sa_pop();
	void Print_stack_array();
	void Read_file(string filename);
	int sa_top;
	string sa_table[N][3];
};

