#pragma once
#include "includes.h"

class Sort
{
public:
	Sort(void);
	~Sort(void);
	void Sort_bubble(string (*s)[3],int sort_num);
	void Sort_insert(List L);
	void Sort_insert_array(int* a,int N);
	void Sort_mergesort_array(int* a,int *copy,int start,int midden,int end);
	void Sort_mergesort_list(List l1,List l2,int start,int midden,int end);
	void Sort_quicksort_array(int*a,int start,int end);
	void Sort_quicksort_list(List l,int start,int end);
	void Sort_heapsort_array(int* a,int N);
	void Sort_heapsort_list(List L,int N);
};
