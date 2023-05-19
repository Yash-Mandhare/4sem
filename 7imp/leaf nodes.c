//Assignment1 set A-b)
//Program to count total nodes and leaf nodes in the binary search tree

#include<stdio.h>
#include "leaf_nodes.c"

int main()
{
	int ch,data,con;
	TREE *t,*t1;
	init(&t);
	do
	{
		printf("\n0.Exit\n1.Insert\n2.Count leaf nodes\n3.Count non-leaf nodes\n");
		printf("Enter ur choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:	exit(0);
			case 1:	do
				{
					printf("Data : ");
					scanf("%d",&data);
					insert(&t,data);
					printf("\nContinue?(1/0): ");
					scanf("%d",&con);
				}while(con!=0);
				break;
			case 2: printf("No. of leafnodes = %d\n",countleaf(t));break;
			case 3: printf("No. of non-leafnodes = %d\n",countnonleaf(t));break;
		}			
	}while(ch!=0);
}

/*0.Exit
1.Insert
2.Count leaf nodes
3.Count non-leaf nodes
Enter ur choice :1 
Data : 42

Continue?(1/0): 1
Data : 16

Continue?(1/0): 1
Data : 80

Continue?(1/0): 1
Data : 19

Continue?(1/0): 1
Data : 4

Continue?(1/0): 1
Data : 10

Continue?(1/0): 1
Data : 5

Continue?(1/0): 1
Data : 17

Continue?(1/0): 1
Data : 43

Continue?(1/0): 1
Data : 49

Continue?(1/0): 1
Data : 31

Continue?(1/0): 0

0.Exit
1.Insert
2.Count leaf nodes
3.Count non-leaf nodes
Enter ur choice :2
No. of leafnodes = 4

0.Exit
1.Insert
2.Count leaf nodes
3.Count non-leaf nodes
Enter ur choice :3

cnt=0
cnt=1
cnt=2
cnt=3
cnt=4
cnt=4
cnt=5
cnt=5
cnt=5
cnt=6
cnt=7No. of non-leafnodes = 7*/