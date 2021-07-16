//implementing stack using singly linked list
#include<stdio.h>
#include<stdlib.h>
//creation of top pointing to the last element of the stack
struct Stack *top1=NULL;
struct Stack *top2=NULL;
//structure of the node
struct Stack
{
	int data;
	struct Stack *next;
};
//creation of node 
struct Stack* nn (int ele)
{
	struct Stack *p=(struct Stack*)malloc(sizeof(struct Stack));
	p->data=ele;
	p->next=NULL;
}
//inserting at the beginning of the stack(linked list) = push
void push1 ()
{
	struct Stack *p;
	int data;
	printf("\nenter the data: ");
	scanf("%d",&data);
	p=nn(data);
	//if the stack is empty
	if(top1 == NULL)
		top1=p;
	//insert at the beginning
	else
	{
		p->next=top1;
		top1=p;
	}
}
//inserting at the beginning of the stack(linked list) = push
void push2 (int data)
{
	struct Stack *p;
	p=nn(data);
	//if the stack is empty
	if(top2 == NULL)
		top2=p;
	//insert at the beginning
	else
	{
		p->next=top2;
		top2=p;
	}
}
//deleting at the beginning of the stack(linked list) = pop
void pop ()
{
	struct Stack *ptr=NULL;
	int data;
	//check if the stack is empty
	if(top1 == NULL && top2 == NULL)
	{
		printf("\nqueue is empty");
		return;
	}
	else
	{
		if(top1 != NULL)
		{
			while(top1)
			{
				data=top1->data;
				push2(data);
				ptr=top1;
				top1=top1->next;
				free(ptr);
				ptr=NULL;
			}
			ptr=top2;
			top2=top2->next;
			free(ptr);
			ptr=NULL;
		}
			else
			{
				ptr=top2;
				top2=top2->next;
				free(ptr);
				ptr=NULL;
			}
	}
}
int main ()
{
	int n;
	 while(1)
	 {
	 	printf("\n<------WELCOME USER------>");
	 	printf("\n1.push");
		printf("\n2.pop");
		printf("\n3.exit");
		printf("\nenter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
		case 1: push1 ();
			break;	
		case 2: pop ();
			break;
		case 3: return 0;
			break;	
		default: printf("\ninvalid input");
			break;	
		}	
     }
 }
