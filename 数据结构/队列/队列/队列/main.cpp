#include "queue.h"
#include "queue_list.h"

void main()
{
	//���Դ��� ����ʵ�ֶ���
	/*
	queue q;
	q.En_queue("a","a","a");
	q.En_queue("b","b","b");
	q.En_queue("c","c","c");
	q.Del_queue();
	q.Read_file("500.txt");
	q.Print_queue();
	*/

	//���Դ��� ����ʵ�ֶ���
	queue_list ql;
	ql.En_queue_list("1","1","1");
	ql.En_queue_list("2","2","2");
	ql.Del_queue_list();
	ql.Read_file("500.txt");
	ql.Print_queue_list();
	system("pause");
}