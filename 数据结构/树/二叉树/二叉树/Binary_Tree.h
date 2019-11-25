#pragma once
typedef struct Tree_node *Search_Tree;

//����������ڵ�Ľṹ��
struct Tree_node
{
	int data;
	Tree_node* left;
	Tree_node* right;
};

//�������������
class Binary_Tree
{
public:
	Binary_Tree(int data);		
	~Binary_Tree(void);
	Search_Tree Make_empty(Search_Tree T);	//ɾ��һ����
	Search_Tree Find_Position(int data,Search_Tree T);//���ҹؼ������ڵ����Ľڵ㣬���ظýڵ��ָ��
	Search_Tree Find_Max(Search_Tree T);	//���ҹؼ����������ڵ�
	Search_Tree Find_Min(Search_Tree T); //���ҹؼ�����С�����ڵ�
	Search_Tree Insert(int data,Search_Tree T);	//����һ��Ԫ��
	Search_Tree Delete(int data,Search_Tree T);	//ɾ���ؼ������ڵĽڵ�
	void Print_Tree(Search_Tree T);

	Search_Tree root;								//���ڵ��ָ��
};

