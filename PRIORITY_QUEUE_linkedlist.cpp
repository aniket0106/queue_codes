//implementing priority queue using linked list
#include<stdio.h>
#include<stdlib.h>
//defining the structure of the linked list
struct PQueue
{
	int data;
	int key;
	struct PQueue *next;
};
//creation of front
struct PQueue *front=NULL;
//creation of node for the Priority Queue
struct PQueue* nn (int data,int key)
{
	struct PQueue *p=(struct PQueue*)malloc(sizeof(struct PQueue));
	p->data=data;
	p->key=key;
	p->next=NULL;
	return p;	
} 
//inserting node in the priority queue
void insert ()
{
	struct PQueue *ptr,*ptr1;
	int data,key;
    struct PQueue *p;
	printf("\nenter the data: ");
	scanf("%d",&data);
	printf("\nenter the priority: ");
	scanf("%d",&key);
	p=nn(data,key);
	if(front == NULL)
		front=p;
	else
	{
		ptr=front;
		if(front->key > p->key)
		{
			p->next=front;
			front=p;
		}
		while(ptr->key < p->key)
		{
			ptr1=ptr;
			ptr=ptr->next;
		}
		if(ptr)
			ptr1->next=p;
		p->next=ptr;
		ptr1->next=p;
	}
}
//deleting node in the priority queue
void deleteN ()
{
	struct PQueue *ptr;
	if(front == NULL)
	{
		printf("\nqueue is empty");
		return;
	}
	if(front->next==NULL)
	{
		free(front);
		front=NULL;
	}
	ptr=front;
	front=front->next;
	free(ptr);
	ptr=NULL;
}
//display node in the priority queue
void display ()
{
	struct PQueue *ptr=front;
	if(ptr)
	{
		printf("\nqueue is empty");
		return;
	}
	while(ptr)
	{
		printf("\n%d",ptr->data);
		ptr=ptr->next;
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
