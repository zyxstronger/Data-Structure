#include "operate_file.h"

/**
 *@name Readfile：从txt中读取数据
 *@param1 (*s)[3]：传入一个二维数组的地址
 *@param2 filename：所要读取的文件名
**/
void Readfile(string (*s)[3],string filename)
{
	int i,j;
	ifstream in(filename,ios::in);
	if(!in.is_open())
	{
		//如果没有打开文件则报错
		cout<<"error"<<endl;
	}
	else
	{
		//若顺利打开文件 将文件内容放入二维string数组 in每次读取到空格或换行
		for(i=0;i<500;i++)
		{
			for(j=0;j<3;j++)
			{
				in>>s[i][j];
			}
		}
	}
	in.close();
}

/**
 *@name Writefile：将数据写入txt文件中
 *@param1 (*s)[3]：传入一个二维数组的地址
 *@param2 filename：所要读取的文件名
**/
void Writefile(string (*s)[3],string filename)
{
	int i,j;
	ofstream out(filename,ios::out);
	for(i=0;i<500;i++)
	{
		for(j=0;j<3;j++)
		{
			out<<s[i][j]<<' ';
		}
		out<<'\n';
	}
	out.close();
}

/**
 *@name Read_data_to_List：将文本数据读入链表
 *@param1 filename：文件名
**/
List Read_data_to_List(string filename)
{
	int temp;
	List l;
	ifstream in(filename,ios::in);
	for (long int i=0;i<10000;i++)
	{
		in>>temp;
		l.Insert_Node(i,temp);//Insert_Node(i,temp);
	}
	in.close();
	return l;
}

/**
 *@name Read_data_to_array_10000：将10000个数据读入数组中
 *@param1 filename：文件名
 *@param2 a：数组名
**/
void Read_data_to_array(string filename,int* a,int N)
{
	ifstream in(filename,ios::in);
	if(!in.is_open())
	{
		cout<<"error"<<endl;
	}
	else
	{
		for (int i=0;i<N;i++)
		{
			in>>a[i];
		}
	}
	in.close();
}