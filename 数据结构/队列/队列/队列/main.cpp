#include "queue.h"
#include "queue_list.h"

void main()
{
	//测试代码 数组实现队列
	/*
	queue q;
	q.En_queue("a","a","a");
	q.En_queue("b","b","b");
	q.En_queue("c","c","c");
	q.Del_queue();
	q.Read_file("500.txt");
	q.Print_queue();
	*/

	//测试代码 链表实现队列
	queue_list ql;
	ql.En_queue_list("1","1","1");
	ql.En_queue_list("2","2","2");
	ql.Del_queue_list();
	ql.Read_file("500.txt");
	ql.Print_queue_list();
	system("pause");
}