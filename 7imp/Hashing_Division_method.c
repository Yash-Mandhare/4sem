/* Assignment 7 SET B
Hashing - Division method. Handle Collision using Linear Probing */

#include <stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 10

int h[TABLE_SIZE]={};

void insert()
{

 int key,index,i,flag=0,hkey;
 printf("\nenter a value to insert into hash table\n");
 scanf("%d",&key);
 hkey=key%TABLE_SIZE;
 for(i=0;i<TABLE_SIZE;i++)
    {
          
     index=(hkey+i)%TABLE_SIZE;

     if(h[index] == 0)
     {
        h[index]=key;
         break;
         
     }
     else
     	printf("\nCollision");

    }

    if(i == TABLE_SIZE)

     printf("\nelement cannot be inserted\n");
}
void deleteKey()
{
    int key, index, i, flag = 0, hkey;
    printf("\nEnter the element to delete: ");
    scanf("%d", &key);
    hkey = key % TABLE_SIZE;

    for (i = 0; i < TABLE_SIZE; i++)
    {
        index = (hkey + i) % TABLE_SIZE;
        if (h[index] == key)
        {
            h[index] = 0;
            printf("\nElement %d deleted successfully!", key);
            break;
        }
    }

    if (i == TABLE_SIZE)
        printf("\nElement not found in the hash table!");
}

void display()
{

  int i;

  printf("\nelements in the hash table are \n");

  for(i=0;i< TABLE_SIZE; i++)

  printf("\nat index %d \t value =  %d",i,h[i]);

}
main()
{
    int opt,i;
    while(1)
    {
        printf("\nPress \n1. Insert\t\n2. Display \t\n3.delete \t\n4.Exit \n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                 deleteKey();
                break;
            case 4:exit(0);
        }
    }
}
