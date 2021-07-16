#include<stdio.h>
#include<stdlib.h>
#define size 5
struct PQueue
{
	int data;
	int key;
};
struct PQueue p1[size];
struct PQueue p2[size];
int front1=-1,rear1=-1;
int front2=-1,rear2=-1;
void insert ()
{
	int data,key;
	if(rear1==size-1 && rear2==size-1)
	{
		printf("\nqueue is full");
		return;
	}
	printf("\nenter the element: ");
	scanf("%d",&data);
	printf("\nenter the key: ");
	scanf("%d",&key);
	if(key==1)
	{
		if(rear1==size-1)
		{
			printf("\nqueue is full");
			return;
		}
		else
		{
			if(front1==-1)
				front1=0;
			rear1++;
			p1[rear1].data=data;
			p1[rear1].key=key;
		}
	}
	else if(key == 2)
	{
		if(rear2==size-1)
		{
			printf("\nqueue is full");
			return;
		}
		else
		{
			if(front2==-1)
				front2=0;
			rear2++;
			p2[rear2].data=data;
			p2[rear2].key=key;
		}
	}
	else
	{
		printf("\ninvalid input");
		return;
	}
}
void deleteN ()
{
	int i=0;
	if(rear1==-1 && rear2==-1)
	{
		printf("\nqueue is empty");
		return;
	}
	if(rear1!=-1)
	{
		for(i=front1;i<=rear1;i++)
		{
			p1[i].data=p1[i+1].data;
			p1[i].key=p1[i+1].key;	
		}	
		rear1--;
		if(rear1==-1)
			front1=-1;
	}
	else 
	{
		for(i=front2;i<=rear2;i++)
		{
			p2[i].data=p2[i+1].data;
			p2[i].key=p2[i+1].key;
		}
		rear2--;
		if(rear2==-1)
			front2=-1;
	}
}
void display ()
{
	int i;
	if(front1==-1&&front2==-1)
	{
		printf("\nqueue is empty");
		return;	
	}
	else if(rear1!=-1)
	{
		for(i=front1;i<=rear1;i++)
			printf("\n%d--->%d",p1[i].data,p1[i].key);
		if(rear2!=-1)
			for(i=front2;i<=rear2;i++)
				printf("\n%d--->%d",p2[i].data,p2[i].key);	
	}
	else if(rear2!=-1)
	{
		for(i=front2;i<=rear2;i++)
			printf("\n%d--->%d",p2[i].data,p2[i].key);	
	}	
}
int main ()
{
	int n=0;
	while(1)
	{
		printf("\n<------WELCOME USER------>");
		printf("\n1.insert");
		printf("\n2.display");
		printf("\n3.delete");
		printf("\n4.exit");
        printf("\n enter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:insert();
			break;
			case 2:display();
			break;
			case 3:deleteN();
			break;
			case 4:return 0;
			break;
			default:printf("\ninvalid input");
			break;
		}		
	}
}

