#include<stdio.h>
#include"levelsort.c"

int main()
{
	int ch,data,con;
	TREE *t,*t1;
	init(&t);
	do
	{
		printf("\n 0.Exit\n 1.Insert\n 2.Levelwise Display\n");
		printf("Enter ur choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0: exit(0);
			case 1: do
				{
					printf("Data: ");
					scanf("%d",&data);
					insert(&t,data);
					printf("\n Continue? (1/0): ");
					scanf("%d",&con);
				}
				while(con!=0);
					inorder(t);break;
				
			case 2: 
				level(t);break;
		}
	}
	while(ch!=0);
}
