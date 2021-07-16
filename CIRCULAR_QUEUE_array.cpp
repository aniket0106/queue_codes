//implementation circular queue using array
#include<stdio.h>
#include<stdlib.h>
#define size 5
//creation of queue
int Queue[size];
//creation of front and rear
int front=-1,rear=-1;
//insert data into queue
void insert ()
{
	int data;
	//if(front==rear+1 || (front ==0 && rear == size-1 ))
	if(front == (rear+1)%size)
	{
		printf("\nqueue is full");
		return;
	}
		if(rear == -1)
		{
			front=0;
			rear=0;
		}
		else
	   	 if(front !=0 && rear==size-1)
			rear=0;
		else
			rear++;
	printf("\nenter the data: ");
	scanf("%d",&Queue[rear]);
}
//delete in circular queue
void deleteN ()
{
	if(front == -1)
	{
		printf("\nqueue is empty");
		return;
	}
		if(rear == 0)
			front=rear=-1;
		else if(front == size-1)
				front =0;
		else
			front++;
}
//display in circular queue
void display ()
{
	int i=0;
	if(front == -1)
	{
		printf("\nqueue is empty");
		return;
	}
		if(front <= rear)
		{
			for(i=front;i<=rear;i++)
				printf("\n%d",Queue[i]);
		}
		else
		{
			for(i=front;i<=size-1;i++)
				printf("\n%d",Queue[i]);
			for(i=0;i<=rear;i++)
				printf("\n%d",Queue[i]);
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
