/*
implementing dequeue using linked list
dequeue is double ended queue
there are two type of dequeue-:
1.input restricted -: input at rear only and delete from both the end
2.output restricted -: input from both end and delete from front
*/ 
#include<stdio.h>
#include<stdlib.h>
//structure for dequeue
struct dequeue
{
	int data;
	struct dequeue *next;
};
//declaring front and rear
struct dequeue *front=NULL,*rear=NULL;
//creation of node in the dequeue
struct dequeue* nn (int data)
{
	struct dequeue *p=(struct dequeue*)malloc(sizeof(struct dequeue));
	p->data=data;
	p->next=NULL;
	return p;
}
//insert at the beginning
void insertBeg ()
{
	struct dequeue *p;
	int data;
	printf("\nenter the data: ");
	scanf("%d",&data);
	p=nn(data);
	if(front==NULL)
		front=rear=p;
	else
	{
		p->next=front;
		front=p;
	}
	
}
//insert at the end
void insertEnd ()
{
	struct dequeue *p;
	int data;
	printf("\nenter the data: ");
	scanf("%d",&data);
	p=nn(data);
	if(front==NULL)
		front=rear=p;
	else
	{
		rear->next=p;
		rear=p;
	}	
}
//delete from the beginning
void deleteBeg ()
{
	struct dequeue *ptr;
   if(front==NULL)
   {
   		printf("\nqueue is empty");
   		return;
   }
   else
   {
   		if(front->next==NULL)
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
//delete from the end
void deleteEnd ()
{
	struct dequeue *ptr;
	if(front==NULL)
	{
		printf("\nqueue is empty");
		return;
	}
	else
	{
		if(front->next==NULL)
		{
			free(front);
			front=rear=NULL;
		}
		else
		{
			ptr=front;
			while(ptr->next!=rear)
				ptr=ptr->next;
			free(ptr->next);
			ptr->next=NULL;
			rear=ptr;
		}
	}
}
//diplay function for the queue
void display ()
{
	struct dequeue *ptr;
	if(front==NULL)
	{
		printf("\nqueue is empty");
		return;
	}
	ptr=front;
	while(ptr)
	{
		printf("\n%d",ptr->data);
		ptr=ptr->next;
	}
}
int main ()
{
	int n,m;
	printf("\n<------WELCOME USER------>");
	while(1)
	{
		printf("\nenter your choice: ");
		printf("\n1.input restricted dequeue");
		printf("\n2.output restricted dequeue");
		printf("\n3.exit");
		scanf("%d",&n);
		switch(n)
		{
			while(1)
			{
			case 1:printf("\n1.insert at the end");
			       printf("\n2.delete from the beginning");
			       printf("\n3.delete from the end");
			       printf("\n4.display");
			       printf("\n5.exit");
			       printf("\nenter your choice");
			       scanf("%d",&m);
			       switch(m)
			       {
			       		case 1:insertEnd();
			       		break;
			       		case 2:deleteBeg();
			       		break;
			       		case 3:deleteEnd();
			       		break;
			       		case 4:display();
			       		break;
			       		case 5:return 0;
			       		break;
			       		default:printf("\ninvalid option");
			       		break;
				   }
			}
				break;
			while(1)
			{
			case 2:printf("\n1.insert at the beginning");
			       printf("\n2.insert from the end");
			       printf("\n3.delete from the beginning");
			       printf("\n4.display");
			       printf("\n5.exit");
			       printf("\nenter your choice");
			       scanf("%d",&m);
			       switch(m)
			       {
			       		case 1:insertBeg();
			       		break;
			       		case 2:insertEnd();
			       		break;
			       		case 3:deleteBeg();
			       		break;
			       		case 4:display();
			       		break;
			       		case 5:return 0;
			       		break;
			       		default:printf("\ninvalid option");
			       	    break;
				   }
			}
				break;
			case 3:return 0;
			    break;
			default:printf("\ninvalid option");
			    break;
		}
	}
}
