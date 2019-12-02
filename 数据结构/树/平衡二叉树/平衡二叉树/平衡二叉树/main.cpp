#include "includes.h"

void main()
{
	Balance_BinaryTree BBT(1);
	for(int i=2;i<=5;i++)
	{
		BBT.root=BBT.Insert(i,BBT.root);
		//cout<<BBT.root->height<<endl;
	}
	BBT.Print_AvlTree(BBT.root);
	system("pause");
}