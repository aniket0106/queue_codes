//implementing priority queue using array
#include<stdio.h>
#include<stdlib.h>
#define size 5
//creating structure for priority queue
struct PQueue
{
	int data;
	int key;
};
//declaring array of structure
struct PQueue p[size];
int front=-1,rear=-1;
//insert function for priority queue
void insert ()
{
	int data,key,i,j;
	//if queue is full
	if(rear == size)
	{
		printf("\nqueue is full");
		return;
	}
	else 
	{
		printf("\nenter the data: ");
		scanf("%d",&data);
		printf("\nenter the key: ");
		scanf("%d",&key);
		//if queue is empty
		if(front==-1)
		{
			front=rear=0;
			p[front].data=data;
			p[front].key=key;
		}
		//if queue is not empty
		else
		{
			for(i=rear;i>=0 && p[i].key>key;i--)
			{
				p[i+1].data=p[i].data;
				p[i+1].key=p[i].key;
			}
			p[i+1].data=data;
			p[i+1].key=key;
			rear++;
		}
	}	
}
//delete function for priority queue
void deleteN ()
{
	int i=0;
	//if queue is empty
	if(rear == 0)
	{
		printf("\nqueue is empty");
		return;	
	}
	//if queue is not empty	
	else
	{
		i=front;
		for(i=front;i<=rear;i++)
		{
			p[i].data=p[i+1].data;
			p[i].key=p[i+1].key;
		}
		rear--;
	}
}
//display function for priority queue 
void display ()
{
	int i=front;
	//if queue is empty
	if(front==-1)
	{
		printf("\nqueue is empty");
		return;
	}
	for(i=front;i<=rear;i++)
	{
		printf("\n%d--->%d",p[i].data,p[i].key);
	}
}
int main ()
{
	int n;
	while(1)
	{
		printf("\n1.insert");
		printf("\n2.delete");
		printf("\n3.display");
		printf("\n4.exit");
		printf("\nenter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: insert();
			break;
			case 2: deleteN();
			break;
			case 3: display();
			break;
			case 4: return 0;
			break;
			default: printf("\ninvalid input");
			break;
		}
	}
}
