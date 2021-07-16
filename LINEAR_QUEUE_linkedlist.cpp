//implementation of queue using linked list
#include<stdio.h>
#include<stdlib.h>
//structure of queue
struct Queue
{
	int data;
	struct Queue *next;
};
//declaring front and rear
struct Queue *front=NULL,*rear=NULL;
//creation of node
struct Queue* nn (int data)
{
	struct Queue *p=(struct Queue*)malloc(sizeof(struct Queue));
	p->data=data;
	p->next=NULL;
	return p;
}
//insert node in the queue
void insert ()
{
	int data;
	struct Queue *p;
	printf("\nenter data: ");
	scanf("%d",&data);
	p=nn(data);
	if(front == NULL)
		front=rear=p;
	else
	{
		rear->next=p;
		rear=p;
	}
}
//delete node in the queue
void deleteN ()
{
	struct Queue *ptr=NULL;
	if(rear == NULL)
		printf("\nqueue is empty");
	else
	{
		if(front == rear)
		{
			free(front);
			front=rear=NULL;
		}
		else
		{
			ptr=front;
			front=front->next;
			free(ptr);
			ptr=NULL;
		}
	}
}
//display all node in the queue
void display ()
{
	struct Queue *ptr=front;
	if(front == NULL)
		printf("\nqueue is empty");
	else
	{
		while(ptr != rear)
		{
			printf("\n%d",ptr->data);
			ptr=ptr->next;
		}
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
