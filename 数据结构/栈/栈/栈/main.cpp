#include "stack_array.h"
#include "stack_list.h"

void main()
{
	//测试代码 数组实现的栈
	/*
	stack_array sa;
	sa.sa_push("a","a","a");
	sa.sa_push("b","b","b");
	sa.Read_file("500.txt");
	sa.sa_pop();
	sa.Print_stack_array();
	*/

	//测试代码 链表实现的栈
	stack_list sl;
	sl.sl_push("1","1","1");
	sl.sl_push("2","2","2");
	sl.sl_push("3","3","3");
	sl.sl_pop();
	sl.Print_stack_list();
	system("pause");
}