/* Assignment 7 : Hash Table – I
Set A: Write program to implement various types of hash functions which are used to place the data in a hash table 
a. Division Method b. Mid square method 
*/
#include<stdlib.h>
#include<stdio.h>
#define MAX 10

int divide(int value)
{
	return value % MAX;
}
int midsquare(int value)
{
	int sqr = value * value;
	int digit=0,i,rem;
	int temp=sqr;
	while(temp!=0)
	{
		rem = temp %10;
		temp=temp/10;
		digit++;
	}
	printf("\nno.of digits = %d\n",digit);
	for(i=0;i<=digit/2;i++)
	{
		rem=sqr%10;
		sqr=sqr/10;
	}
	printf("\nmiddle digit = %d\n",rem);
	return rem % MAX;
}
int main()
{
	int hashtable[MAX],i,ch,n,ele,key,j,k;
	int ht_midsq[MAX][MAX];
	do
	{
    	for(i=0;i<MAX;i++)
	    {
		    hashtable[i]=-1;
		    ht_midsq[i][0]=-1;
		    ht_midsq[i][1]=-1;
	    }
		printf("\n0.Exit\n1.division\n2.midsquare\n");
		printf("\nEnter ur choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:	exit(0);
			case 1:	
					for(i=0;i<MAX;i++)
						printf("\nBucket %d: %d",i,hashtable[i]);

					printf("\nHow many elements:");
					scanf("%d",&n);
					for(i=0;i<MAX;i++) hashtable[i]=-1;
					for(i=0;i<n;i++)
					{
						printf("\nEnter element:");
						scanf("%d",&ele);
						key=divide(ele);
						if(hashtable[key]==-1)
							hashtable[key]=ele;						
						else 
						{
							printf("\ncollision\n");
							for(j=key+1; j!=key;j=(j+1)%MAX)
							{
								if(hashtable[j]==-1)
								{
									hashtable[j]=ele;	
									break;
								}
							}
							if(j==key) printf("\nHash table full\n");
						}
					}
					printf("\nHash table using division method:\n");
					for(i=0;i<MAX;i++)
						printf("\nBucket %d: %d",i,hashtable[i]);
					break;

			case 2:	
					for(i=0;i<MAX;i++)
						printf("\nBucket %d: %d",i,hashtable[i]);

					printf("\nHow many elements:");
					scanf("%d",&n);
					for(i=0;i<MAX;i++) hashtable[i]=-1;
					for(i=0;i<n;i++)
					{
						printf("\nEnter element:");
						scanf("%d",&ele);
						key=midsquare(ele);
						if(hashtable[key]==-1)
							hashtable[key]=ele;						
						else 
						{
							printf("\ncollision\n");
							for(j=key+1; j!=key;j=(j+1)%MAX)
							{
								if(hashtable[j]==-1)
								{
									hashtable[j]=ele;	
									break;
								}
							}
							if(j==key) printf("\nHash table full\n");
						}
					}
					printf("\nHash table using midsquare method:\n");
					for(i=0;i<MAX;i++)
						printf("\nBucket %d: %d",i,hashtable[i]);
					break;
		}
	}while(ch!=0);
}
