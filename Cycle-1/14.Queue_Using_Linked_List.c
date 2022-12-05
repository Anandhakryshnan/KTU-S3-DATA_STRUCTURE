//CSL201 DATA STRUCTURES LAB ----- ANANDHA KRISHNAN
#include<stdio.h>
#include<stdlib.h>
void endq();
void deq();
void display();
struct node
{
	int data;
	struct node *link;
};
struct node *front=NULL,*rear=NULL;
int main()
{
	int choice;
	while(1)
	{
		printf("\n 1.endqueue\n 2.dequeue\n 3.display\n 4.exit\n Enter the choice:");
		scanf("%d",&choice);
		switch(choice)
		{
	 		case 1:endq(); break;
	  		case 2:deq(); break;
	  		case 3:display(); break;
	  		case 4:exit(0);break;
	  		default:printf("invalid choice\n");
		}
	}
}
void endq()
{	
	struct node *temp;
	if (rear==NULL)
	{
		front=rear=(struct node *)malloc(sizeof(struct node));
		printf("enter element:");
    		scanf("%d",&rear->data);
    		rear->link=NULL;	
	}
	else
	{
		temp=rear;
		rear=(struct node *)malloc(sizeof(struct node));
		temp->link=rear;
		printf("enter element:");
    		scanf("%d",&rear->data);
    		rear->link=NULL;
    	}		
}
void deq()
{
	struct node *temp;
	if (front==NULL)
    		printf("under flow\n");
    	else if	(front==rear)
    	{
		temp=front;
		printf("dequed element:%d\n",temp->data);
		front=front->link;
		free(temp);
		rear=NULL;
	}
	else
	{
		temp=front;
		printf("dequed element:%d\n",temp->data);
		front=front->link;
		free(temp);
	}
}
void display()
{
	if(front==NULL)
		printf("queue empty\n");
	else
	{
		struct node *temp=front;
		while(temp!= NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->link;		
		}

	}
}
