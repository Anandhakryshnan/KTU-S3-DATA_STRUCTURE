//CSL201 DATA STRUCTURES LAB ----- ANANDHA KRISHNAN
#include<stdio.h>
#include<stdlib.h>

struct node
{	
	int data;
	struct node *link;
};
void push(struct node **);
void pop(struct node **);
void display(struct node **);
int main()
{	
	int choice;
	struct node *top=NULL;
	while(1)
	{
		printf("\n\nchoose an option\n\n1.PUSH  2.POP  3.DISPLAY  4.EXIT :- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: push(&top);
                    		break;
            		case 2: pop(&top);
                    		break;
            		case 3: display(&top);
                    		break;
          		case 4 : exit(0);
          			break;
          		default: printf("INVALID INPUT");	
          		}
	}
}
void pop(struct node **tp)
{
	struct node *temp;
	if (*tp==NULL)
		printf("STACK EMPTY");
	else
	{	temp=*tp;
		*tp=(*tp)->link;		
		printf("The POPPED ELEMENT is %d",temp->data);
		free(temp);
	}
}
void push(struct node **tp)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	printf("enter the data : ");
	scanf("%d",&new->data);
	if(*tp==NULL)
	{	
		*tp=new;
		(*tp)->link=NULL;
	}	
	else
	{
		new->link=*tp;
		*tp=new;
	}
}
void display(struct node **tp)
{
	if(*tp==NULL)
		printf("STACK EMPTY");
	else
	{	struct node *temp;
	 	temp=*tp;
	 	printf("THE ELEMENTS IN THE STACK ARE : ");
	 	while (temp!=NULL)
	 	{
	 		printf("%d  ",temp->data);
	 		temp=temp->link;
	 	}
	 }
}	 		
