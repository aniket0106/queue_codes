/*
1.queue is a logical datastructure in which insertion take place from front or from the beginning
and deletion take place from the end called rear

2.we can implement queue using stack and array

3.there are four type of queue-:
     Linear queue
     Priority queue
     Circular queue
     Dequeue
in this particular file we will study about linear queue how to implement it and what are the 
drawbacks of implementing linear queue

4.deletion operation in this case will be tackle in two ways
   4.1.first is by increasing the front but in this case as size is fixed and as we increase front
   we are decreasing size at some time we have size but we cant insert anu element
   4.2.second is by shifting all element from right to left but if there are so many elements 
   then shifting process will took so much time hence performance will be down hence we dont 
   use this queue instead we use circular queue
*/
//implementing queue using array
#include<stdio.h>
#include<stdlib.h>
#define size 5
//declaring the queue
int queue[size];
//creation of front and rear
int front=-1,rear=-1;
//insert operation in queue         time complexity=o(1)
void insert ()
{
	int data;
	//if queue is full
	if(rear == size-1)
	{
		printf("\nqueue is full");
		return;
	}
	printf("\n enter the data: ");
	scanf("%d",&queue[++rear]);
	//if first data is added then we have to increase front also
	if(rear == 1 && front == -1)
		front++;
}
//diplay the data of the queue    time complexity o(n) where n=size;
void display ()
{
	int i=0;
	//if queue is empty
	if(rear == -1)
	{
		printf("\nqueue is empty");
		return;
	}
	for(i=front;i<=rear;i++)
		printf("\n%d",queue[i]);
}
//delete data from the queue     time complexity o(n) where
void deleteN ()
{
	int i=0;
	//if queue is empty
	if(rear==-1)
	{
		printf("\n queue is empty");
		return;
	}
	for(i=front;i<rear;i++)
	{
		queue[i]=queue[i+1];
	}
	rear--;
	//if there is only one node
	if(rear==-1)
		front=-1;
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

