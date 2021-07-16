//implementing circular queue using linked list
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
//insert in the circular queue
void insert ()
{
	int data;
	struct Queue *p;
	printf("\nenter the data: ");
	scanf("%d",&data);
	p=nn(data);
	if(front == NULL)
	{
		front=p;
		rear=p;
		rear->next=front;
	}
	else
	{
		p->next=rear->next;
		rear->next=p;
		rear=p;
	}
}
//delete node in the circular queue
void deleteN ()
{
	struct Queue *ptr;
	if(front == NULL)
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
			rear->next=front;
			free(ptr);
			ptr=NULL;
		}
	}
}
//display in the circular queue
void display ()
{
	struct Queue *ptr=front;
	if(front == NULL)
	{
		printf("\nqueue is empty");
		return;
	}
	do
	{
		printf("\n%d",ptr->data);
		ptr=ptr->next;
	}while(ptr != front);
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
