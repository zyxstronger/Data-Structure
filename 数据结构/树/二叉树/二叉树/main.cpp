#include "includes.h"

void main()
{
	Binary_Tree BT1(4);
	BT1.root=BT1.Make_empty(BT1.root);
	for (int i=0;i<5;i++)
	{
		BT1.root=BT1.Insert(3*i,BT1.root);
	}
	cout<<endl;
	BT1.Print_Tree(BT1.root);
	//BT1.root=BT1.Delete(0,BT1.root);
	//cout<<"the max element is "<<BT1.Find_Max(BT1.root)->data<<endl;
	//cout<<"the min element is "<<BT1.Find_Min(BT1.root)->data<<endl;
	system("pause");
}