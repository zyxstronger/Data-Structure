#include "Sort.h"

Sort::Sort(void)
{
}


Sort::~Sort(void)
{
}

/**
 *@name Sort_bubble��ð������
 *@param1 string s[500][3]������һ����ά�ַ�������
 *@param2 sort_num��ѡ������ı�׼ (0-�ص� 1-��� 2-ʱ��)
 *@return none
**/
void Sort::Sort_bubble(string (*s)[3],int sort_num)
{
	int i,j,k;
	string temp;
	//ð���㷨
	for(i=0;i<500;i++)
	{
		for(j=1;j<500-i;j++)
		{
			//���ǰ��Ĵ��ں���ģ��򽻻�˳�򣨳��ף�
			if(s[j-1][sort_num]>s[j][sort_num])
			{
				//����
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
 *@name Sort_insert����������
 *@param1 L������һ������
**/
void Sort::Sort_insert(List L)
{
	int temp;
	List new_list;
	int j;

	new_list.Insert_Node(0,L.Find_Node(0));
	for (int i=1;i<L.List_length-1;i++)
	{
		//��ȡ�������е�i��Ԫ��
		temp=L.Find_Node(i);
		for (j=0;j<new_list.List_length;j++)
		{
			//һֱ�Ƚϣ�ֱ��С�������е�ĳ��Ԫ��ʱ���ڸ�λ�ò���һ���½ڵ�
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
 *@name Sort_insert_array��ʹ�ò�������������������
 *@param1 a����Ҫ�����������
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
		//Ĭ��copy��i֮ǰ�����ж����������
		//��a[i]��copy��i-1��ʼ��ǰ�Ƚϣ����С�ڣ���copy�ڸ�λ�ú��ƣ�������λ
		while((index>0)&&(temp<copy[index-1]))
		{
			//��������λ���Լ�
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
 *@name merge���������[start]-[end]���������ϲ�
 *@param1 a���������Ҫ���������
 *@param2 copy���м���������
 *@param3 start����Ҫ�ϲ�����ʼλ��
 *@param4 midden����Ҫ�ϲ����м�λ��
 *@param5 end����Ҫ�ϲ���ĩ��λ��
**/
void merge_array(int* a,int *copy,int start,int midden,int end)
{
	int ptr_i=start;
	int ptr_j=midden+1;
	int ptr_k=start;
	int len=end-start;
	//�����ȴ�start��midden+1��ʼ�Ƚϣ�ֱ������ĳһ������ȫ������copy
	while((ptr_i<=midden)&&(ptr_j<=end))
	{
		if(a[ptr_i]<a[ptr_j])
			copy[ptr_k++]=a[ptr_i++];
		else
			copy[ptr_k++]=a[ptr_j++];
	}

	//��start-midden������ʣ�µ�Ԫ��ȫ������copy
	while(ptr_i<=midden)
	{
		copy[ptr_k++]=a[ptr_i++];
	}

	//��midden+1-end������ʣ�µ�Ԫ��ȫ������copy
	while(ptr_j<=end)
	{
		copy[ptr_k++]=a[ptr_j++];
	}

	//��copy�е�Ԫ�ط���ֵ��a
	for(int i=start;i<=end;i++)
	{
		a[i]=copy[i];
	}
}

/**
 *@name Sort_mergesort���鲢����
 *@param1 a���������Ҫ���������
 *@param2 copy����Ϊ�м���������
 *@param3 start����Ҫ�ϲ�����ʼλ��
 *@param4 midden����Ҫ�ϲ����м�λ��
 *@param5 end����Ҫ�ϲ���ĩ��λ��
**/
void Sort::Sort_mergesort_array(int* a,int *copy,int start,int midden,int end)
{
	int len=end-start;
	//ֻ��end>=startʱ������Ҫ����
	if(len>=1)
	{
		//��start-end�����зֳ����Σ�Ȼ��ϲ�
		Sort_mergesort_array(a,copy,start,(midden+start)/2,midden);
		Sort_mergesort_array(a,copy,midden+1,(midden+1+end)/2,end);
		merge_array(a,copy,start,midden,end);
	}
	else
		return;
}

/**
 *@name merge_list���ϲ��㷨(List)
  *@param1 l1���������Ҫ���������
 *@param2 l2���м���������
 *@param3 start����Ҫ�ϲ�����ʼλ��
 *@param4 midden����Ҫ�ϲ����м�λ��
 *@param5 end����Ҫ�ϲ���ĩ��λ��
**/
void merge_list(List l1,List l2,int start,int midden,int end)
{
	int len=end-start;
	int ptr_i=start;
	int ptr_j=midden+1;
	int ptr_k=start;
	//��ʱ��start-midden������midden+1-end���н��кϲ�
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

	//��start-midden����ʣ��Ĵ���l2
	while(ptr_i<=midden)
	{
		l2.Change_Node(ptr_k++,l1.Find_Node(ptr_i++));
	}

	//��midden+1-end����ʣ��Ĵ���l2
	while(ptr_j<=end)
	{
		l2.Change_Node(ptr_k++,l1.Find_Node(ptr_j++));
	}

	//l2���и�ֵ��l1
	for (int i=start;i<=end;i++)
	{
		l1.Change_Node(i,l2.Find_Node(i));
	}
}

/**
 *@name Sort_mergesort_list���鲢����(List)
 *@param1 l1���������Ҫ���������
 *@param2 l2���м���������
 *@param3 start����Ҫ�ϲ�����ʼλ��
 *@param4 midden����Ҫ�ϲ����м�λ��
 *@param5 end����Ҫ�ϲ���ĩ��λ��
**/
void Sort::Sort_mergesort_list(List l1,List l2,int start,int midden,int end)
{
	int len=end-start;
	//ֻ��end>=startʱ������Ҫ����
	if(len>=1)
	{
		//������ֳ��������� ����
		Sort_mergesort_list(l1,l2,start,(start+midden)/2,midden);
		Sort_mergesort_list(l1,l2,midden+1,(midden+1+end)/2,end);
		merge_list(l1,l2,start,midden,end);
	}
	else
		return ;
}

/**
 *@name Swap��������Ԫ��(int*)
 *@param1 x����Ҫ������һ��Ԫ�صĵ�ַ
 *@param2 y����Ҫ��������һ��Ԫ�صĵ�ַ
**/
void Swap(int* x,int* y)
{
	int temp;
	temp=(*x);
	(*x)=(*y);
	(*y)=temp;
}

/**
 *@name Sort_quicksort_array�������������飩
 *@name a����Ҫ���������
 *@start����ʼλ��
 *@end����ֹλ��
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

	//ȡ��׼Ԫ �������зֳ�������������
	//���С�ڻ�׼Ԫ���ұߴ��ڻ�׼Ԫ
	while(i<j)
	{
		//�ҵ��ұ߿�ʼ�ĵ�һ��С��cmp��Ԫ�� �������= �ͻ����������
		while((a[j]>=cmp)&&(i<j))
		{
			j--;
		}
		//�ҵ���ߵ�һ������cmp��Ԫ��
		while((a[i]<=cmp)&&(i<j))
		{
			i++;
		}
		
		if(i<j)
		{
			//���� С��cmp��Ԫ�ش��ұ����е�������� ����cmp��Ԫ�ش�������е��ұ�����
			Swap(&a[i++],&a[j--]);
		}
	}
	//cout<<j<<endl;
	//����׼Ԫ�ŵ��м�
	Swap(&a[j],&a[start]);
	
	//��������н��п���
	Sort_quicksort_array(a,start,j-1);
	//���ұ����н��п���
	Sort_quicksort_array(a,j+1,end);
}

/**
 *@name Sort_quicksort_array��������������
 *@name a����Ҫ���������
 *@start����ʼλ��
 *@end����ֹλ��
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
 *@name Build_Heap�����������(˳��һ���ڵ㣬��С�ڵ����·�)
 *@param1 a��������Ҫ�����ѵ�����
 *@param2 i��������Ҫ�����Ľڵ�
 *@param3 len������ĳ��ȣ���ֹԽ�磬Խ����ζ��û���ӽڵ�
**/
void Build_Heap(int* a,int i,int len)
{
	int Child;
	int temp;
	//ֻҪ���ڶ��Ӿͼ������±Ƚ�
	while((2*i)<=len)
	{
		Child=2*i;
		//ȡ���Ҷ��ӽڵ����Ǹ�
		if(((Child+1)<=len)&&(a[Child]<a[Child+1]))
			Child++;
		//������ӱȸ��״�Ļ��ͽ�����ͬʱ�����ڵ��Ϊ����
		//����Ļ���֤��˳�Ÿýڵ�Ĵ����ǶԵ�
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
 *@name Sort_heapsort_array��������
  *@param1 a��������Ҫ�����������
 *@param2 N������Ĵ�С
**/
void Sort::Sort_heapsort_array(int* a,int N)
{
	//��ÿһ���ڵ�������ˣ�С�Ľڵ������ߣ�
	//�õ�һ�������
	for (int i=N;i>=0;i--)
	{
		Build_Heap(a,i,N);
	}
	//�����һ��λ�ÿ�ʼ������������ٶ�ǰ�벿�����½�����
	//Ч�����ɹ�����
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