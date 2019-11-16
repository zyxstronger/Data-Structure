#include "Sort.h"

Sort::Sort(void)
{
}


Sort::~Sort(void)
{
}

/**
 *@name Sort_bubble：冒泡排序
 *@param1 string s[500][3]：传入一个二维字符串数组
 *@param2 sort_num：选择排序的标准 (0-地点 1-序号 2-时间)
 *@return none
**/
void Sort::Sort_bubble(string (*s)[3],int sort_num)
{
	int i,j,k;
	string temp;
	//冒泡算法
	for(i=0;i<500;i++)
	{
		for(j=1;j<500-i;j++)
		{
			//如果前面的大于后面的，则交换顺序（沉底）
			if(s[j-1][sort_num]>s[j][sort_num])
			{
				//交换
				for(k=0;k<3;k++)
				{
					temp=s[j-1][k];
					s[j-1][k]=s[j][k];
					s[j][k]=temp;
				}
			}
		}
	}
}

/**
 *@name Sort_insert：插入排序
 *@param1 L：传入一个链表
**/
void Sort::Sort_insert(List L)
{
	int temp;
	List new_list;
	int j;

	new_list.Insert_Node(0,L.Find_Node(0));
	for (int i=1;i<L.List_length-1;i++)
	{
		//提取出链表中第i个元素
		temp=L.Find_Node(i);
		for (j=0;j<new_list.List_length;j++)
		{
			//一直比较，直到小于链表中的某个元素时，在该位置插入一个新节点
			if(temp<new_list.Find_Node(j))
			{
				new_list.Insert_Node(j,temp);
				break;
			}
		}
		if(j==new_list.List_length)
			new_list.Insert_Node(j,temp);
		cout<<"the sort order is "<<i<<endl;
	}
	//new_list.Print_List();

	for (int i=0;i<L.List_length;i++)
	{
		L.Change_Node(i,new_list.Find_Node(i));
	}
}

/**
 *@name Sort_insert_array：使用插入排序对数组进行排序
 *@param1 a：需要排序的数组名
**/
void Sort::Sort_insert_array(int* a,int N)
{
	int copy[100000]={0};
	int temp;
	int index;
	copy[0]=a[0];
	for (int i=1;i<N;i++)
	{
		temp=a[i];
		index=i;
		//默认copy在i之前的序列都已排序完毕
		//将a[i]从copy的i-1开始向前比较，如果小于，则copy在该位置后移，留出空位
		while((index>0)&&(temp<copy[index-1]))
		{
			//必须先移位再自减
			copy[index]=copy[index-1];
			index--;
		}
		copy[index]=temp;
	}
	for (int i=0;i<N;i++)
	{
		a[i]=copy[i];
	}
}

/**
 *@name merge：对数组的[start]-[end]经过排序后合并
 *@param1 a：传入的需要排序的数组
 *@param2 copy：中间量的数组
 *@param3 start：需要合并的起始位置
 *@param4 midden：需要合并的中间位置
 *@param5 end：需要合并的末端位置
**/
void merge_array(int* a,int *copy,int start,int midden,int end)
{
	int ptr_i=start;
	int ptr_j=midden+1;
	int ptr_k=start;
	int len=end-start;
	//首先先从start和midden+1开始比较，直到满足某一序列已全部进入copy
	while((ptr_i<=midden)&&(ptr_j<=end))
	{
		if(a[ptr_i]<a[ptr_j])
			copy[ptr_k++]=a[ptr_i++];
		else
			copy[ptr_k++]=a[ptr_j++];
	}

	//将start-midden序列中剩下的元素全部丢入copy
	while(ptr_i<=midden)
	{
		copy[ptr_k++]=a[ptr_i++];
	}

	//将midden+1-end序列中剩下的元素全部丢入copy
	while(ptr_j<=end)
	{
		copy[ptr_k++]=a[ptr_j++];
	}

	//将copy中的元素反赋值给a
	for(int i=start;i<=end;i++)
	{
		a[i]=copy[i];
	}
}

/**
 *@name Sort_mergesort：归并排序
 *@param1 a：传入的需要排序的数组
 *@param2 copy：作为中间量的数组
 *@param3 start：需要合并的起始位置
 *@param4 midden：需要合并的中间位置
 *@param5 end：需要合并的末端位置
**/
void Sort::Sort_mergesort_array(int* a,int *copy,int start,int midden,int end)
{
	int len=end-start;
	//只有end>=start时，才需要分治
	if(len>=1)
	{
		//将start-end的序列分成两段，然后合并
		Sort_mergesort_array(a,copy,start,(midden+start)/2,midden);
		Sort_mergesort_array(a,copy,midden+1,(midden+1+end)/2,end);
		merge_array(a,copy,start,midden,end);
	}
	else
		return;
}

/**
 *@name merge_list：合并算法(List)
  *@param1 l1：传入的需要排序的链表
 *@param2 l2：中间量的链表
 *@param3 start：需要合并的起始位置
 *@param4 midden：需要合并的中间位置
 *@param5 end：需要合并的末端位置
**/
void merge_list(List l1,List l2,int start,int midden,int end)
{
	int len=end-start;
	int ptr_i=start;
	int ptr_j=midden+1;
	int ptr_k=start;
	//此时将start-midden序列与midden+1-end序列进行合并
	while((ptr_i<=midden)&&(ptr_j<=end))
	{
		if(l1.Find_Node(ptr_i)<l1.Find_Node(ptr_j))
		{
			l2.Change_Node(ptr_k++,l1.Find_Node(ptr_i++));
		}
		else
		{
			l2.Change_Node(ptr_k++,l1.Find_Node(ptr_j++));
		}
	}

	//将start-midden序列剩余的存入l2
	while(ptr_i<=midden)
	{
		l2.Change_Node(ptr_k++,l1.Find_Node(ptr_i++));
	}

	//将midden+1-end序列剩余的存入l2
	while(ptr_j<=end)
	{
		l2.Change_Node(ptr_k++,l1.Find_Node(ptr_j++));
	}

	//l2序列赋值给l1
	for (int i=start;i<=end;i++)
	{
		l1.Change_Node(i,l2.Find_Node(i));
	}
}

/**
 *@name Sort_mergesort_list：归并排序(List)
 *@param1 l1：传入的需要排序的链表
 *@param2 l2：中间量的链表
 *@param3 start：需要合并的起始位置
 *@param4 midden：需要合并的中间位置
 *@param5 end：需要合并的末端位置
**/
void Sort::Sort_mergesort_list(List l1,List l2,int start,int midden,int end)
{
	int len=end-start;
	//只有end>=start时，才需要分治
	if(len>=1)
	{
		//将链表分成两个序列 分治
		Sort_mergesort_list(l1,l2,start,(start+midden)/2,midden);
		Sort_mergesort_list(l1,l2,midden+1,(midden+1+end)/2,end);
		merge_list(l1,l2,start,midden,end);
	}
	else
		return ;
}

/**
 *@name Swap：交换两元素(int*)
 *@param1 x：需要交换的一个元素的地址
 *@param2 y：需要交换的另一个元素的地址
**/
void Swap(int* x,int* y)
{
	int temp;
	temp=(*x);
	(*x)=(*y);
	(*y)=temp;
}

/**
 *@name Sort_quicksort_array：快速排序（数组）
 *@name a：需要排序的数组
 *@start：起始位置
 *@end：终止位置
**/
void Sort::Sort_quicksort_array(int*a,int start,int end)
{
	if(start>end)
	{
		return;
	}

	int i=start+1;
	int j=end;
	Swap(&a[start],&a[(start+end)/2]);
	int cmp=a[start];

	//取基准元 并将序列分成左右两个序列
	//左边小于基准元，右边大于基准元
	while(i<j)
	{
		//找到右边开始的第一个小于cmp的元素 如果加上= 就会很慢。。。
		while((a[j]>=cmp)&&(i<j))
		{
			j--;
		}
		//找到左边第一个大于cmp的元素
		while((a[i]<=cmp)&&(i<j))
		{
			i++;
		}
		
		if(i<j)
		{
			//交换 小于cmp的元素从右边序列到左边序列 大于cmp的元素从左边序列到右边序列
			Swap(&a[i++],&a[j--]);
		}
	}
	//cout<<j<<endl;
	//将基准元放到中间
	Swap(&a[j],&a[start]);
	
	//对左边序列进行快排
	Sort_quicksort_array(a,start,j-1);
	//对右边序列进行快排
	Sort_quicksort_array(a,j+1,end);
}

/**
 *@name Sort_quicksort_array：快速排序（链表）
 *@name a：需要排序的链表
 *@start：起始位置
 *@end：终止位置
**/
void Sort::Sort_quicksort_list(List l,int start,int end)
{
	if(start>=end)
		return ;

	int i=start;
	int j=end;
	int cmp=l.Find_Node(start);

	while(i<j)
	{
		while((l.Find_Node(j)>=cmp)&&(i<j))
			j--;
		while((l.Find_Node(i)<=cmp)&&(i<j))
			i++;

		if(i<j)
			l.Swap_Node(i,j);
	}
	l.Swap_Node(start,j);
	
	Sort_quicksort_list(l,start,j-1);
	Sort_quicksort_list(l,j+1,end);
}

/**
 *@name Build_Heap：构建大根堆(顺着一个节点，将小节点往下放)
 *@param1 a：传入需要建立堆的数组
 *@param2 i：输入需要操作的节点
 *@param3 len：数组的长度，防止越界，越界意味着没有子节点
**/
void Build_Heap(int* a,int i,int len)
{
	int Child;
	int temp;
	//只要存在儿子就继续向下比较
	while((2*i)<=len)
	{
		Child=2*i;
		//取左右儿子节点大的那个
		if(((Child+1)<=len)&&(a[Child]<a[Child+1]))
			Child++;
		//如果儿子比父亲大的话就交换，同时索引节点变为儿子
		//否则的话就证明顺着该节点的次序是对的
		if(a[i]<a[Child]) 
		{
			Swap(&(a[Child]),&(a[i]));
			i=Child;
		}
		else
			break;
	}
}

/**
 *@name Sort_heapsort_array：堆排序
  *@param1 a：传入需要堆排序的数组
 *@param2 N：数组的大小
**/
void Sort::Sort_heapsort_array(int* a,int N)
{
	//对每一个节点进行下滤（小的节点往下走）
	//得到一个大根堆
	for (int i=N;i>=0;i--)
	{
		Build_Heap(a,i,N);
	}
	//从最后一个位置开始，与根交换后再对前半部分重新建立堆
	//效果即成功排序
	for (int i=N;i>0;i--)
	{
		Swap(&(a[0]),&(a[i]));
		Build_Heap(a,0,i-1);
	}
}

void Build_Heap_List(List L,int i,int len)
{
	int Child;
	while((2*i+1)<=len)
	{
		Child=2*i+1;
		if(((Child+1)<=len)&&(L.Find_Node(Child+1)>=L.Find_Node(Child)))
			Child++;
		if(L.Find_Node(i)<L.Find_Node(Child))
		{
			L.Swap_Node(i,Child);
			i=Child;
		}
		else
			break;
	}
}

void Sort::Sort_heapsort_list(List L,int N)
{
	for (int i=N-1;i>=0;i--)
	{
		Build_Heap_List(L,i,N-1);
	}
	for (int i=N-1;i>=0;i--)
	{
		L.Swap_Node(0,i);
		Build_Heap_List(L,0,i-1);
	}
}