#include "includes.h"

int main()
{
	/*
	//链表排序区 gameover
	List l1,l2;
	int x;
	clock_t starttime,endtime;
	l1=Read_data_to_List("data.txt");
	l2=Read_data_to_List("data.txt");
	Sort sort6;
	cout<<"input 1 is insert_sort, input 2 is mergesort_sort, input 3 is quick_sort，input 4 is heap_sort"<<endl;
	cin>>x;
	starttime=clock();
	switch(x)
	{
	case 1:sort6.Sort_insert(l1);
	case 2:sort6.Sort_mergesort_list(l1,l2,0,4,9);
	case 3:sort6.Sort_quicksort_list(l1,0,9);
	case 4:sort6.Sort_heapsort_list(l1,l1.List_length);
	}
	endtime=clock();
	//sort6.Sort_quicksort_list(l1,0,l1.List_length-1);
	//sort6.Sort_mergesort_list(l1,l2,0,4,9);
	//sort6.Sort_insert(l1);
	l1.Print_List();
	cout<<"the run time is "<<(double)(endtime-starttime)<<"ms"<<endl;*/

	//利用数组实现所有的排序
	int a[100000]={0};
	int copy[100000]={0};
	int x=3;
	int num=100000;
	clock_t starttime,endtime;
	Sort sort9;
	
	/*
	//数组测试代码 100000
	Read_data_to_array("ldata.txt",a,100000);
	Read_data_to_array("ldata.txt",copy,100000);
	starttime=clock();
	//sort9.Sort_mergesort_array(a,copy,0,49999,99999);
	//sort9.Sort_heapsort_array(a,99999);
	sort9.Sort_quicksort_array(a,0,99999);
	//sort9.Sort_insert_array(a,100000);
	endtime=clock();
	cout<<"run time is "<<endtime-starttime<<"ms"<<endl;
	for (int i=0;i<100000;i++)
	{
		cout<<a[i]<<endl;
	}*/
	
	while(1)
	{
	cout<<"Choose the number of data"<<endl;
	cin>>num;
	switch(num)
	{
	case 10000:		Read_data_to_array("data.txt",a,10000);
							Read_data_to_array("data.txt",copy,10000);
							break;
	case 100000:	Read_data_to_array("ldata.txt",a,100000);
							Read_data_to_array("ldata.txt",copy,100000);
							break;
	}
	cout<<"input 1 is insert_sort, input 2 is mergesort_sort, input 3 is quick_sort，input 4 is heap_sort"<<endl;
	cin>>x;
	if(num==10000)
	{
		starttime=clock();
		switch(x)
		{
		case 1: sort9.Sort_insert_array(a,num);
					break;
		case 2:	sort9.Sort_mergesort_array(a,copy,0,4999,9999);
					break;
		case 3:	sort9.Sort_quicksort_array(a,0,9999);
					break;
		case 4:	sort9.Sort_heapsort_array(a,9999);
					break;
		}
		endtime=clock();
		cout<<"run time is "<<endtime-starttime<<"ms"<<endl;
	}
	else if(num==100000)
	{
		starttime=clock();
		switch(x)
		{
		case 1: sort9.Sort_insert_array(a,num);
					break;
		case 2:	sort9.Sort_mergesort_array(a,copy,0,49999,99999);
					break;
		case 3:	sort9.Sort_quicksort_array(a,0,99999);
					break;
		case 4:	sort9.Sort_heapsort_array(a,99999);
					break;
		}
		endtime=clock();
		//for (int i=0;i<num;i++)
		//{
		//	cout<<a[i]<<endl;
		//}
		cout<<"run time is "<<endtime-starttime<<"ms"<<endl;
	}
	}
	
	system("pause");
	return 0;
}