#include "operate_file.h"

/**
 *@name Readfile����txt�ж�ȡ����
 *@param1 (*s)[3]������һ����ά����ĵ�ַ
 *@param2 filename����Ҫ��ȡ���ļ���
**/
void Readfile(string (*s)[3],string filename)
{
	int i,j;
	ifstream in(filename,ios::in);
	if(!in.is_open())
	{
		//���û�д��ļ��򱨴�
		cout<<"error"<<endl;
	}
	else
	{
		//��˳�����ļ� ���ļ����ݷ����άstring���� inÿ�ζ�ȡ���ո����
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
 *@name Writefile��������д��txt�ļ���
 *@param1 (*s)[3]������һ����ά����ĵ�ַ
 *@param2 filename����Ҫ��ȡ���ļ���
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
 *@name Read_data_to_List�����ı����ݶ�������
 *@param1 filename���ļ���
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
 *@name Read_data_to_array_10000����10000�����ݶ���������
 *@param1 filename���ļ���
 *@param2 a��������
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