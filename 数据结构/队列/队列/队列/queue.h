#pragma once
#include "includes.h"
#define N 550

class queue
{
public:
	queue(void);
	bool En_queue(string add,string num,string t);
	bool Del_queue();
	bool Read_file(string filename);
	void Print_queue();
	~queue(void);
	int q_first;
	int q_last;
	int q_total;
	string q_table[N][3];
};

