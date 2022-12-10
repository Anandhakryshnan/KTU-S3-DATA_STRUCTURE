//CSL201 DATA STRUCTURES LAB ----- ANANDHA KRISHNAN
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data,exp;
    struct node* link;
};
struct node* poly1,*poly2,*respoly;

void display();
void insertlast(int ,int,int);
void multiplicator();

int main()
{
	int i,j,k,data;
	printf("Enter highest degree of polynomial A:");
	scanf("%d",&j);
	for(i=j;i>=0;i--)
	{	printf("enter the coef of term with exp[%d] :",i);
		scanf("%d",&data);
		insertlast(i,1,data);
	}
	printf("\n");
	printf("enter highest degree of polynomial B:");
	scanf("%d",&k);
	for(i=k;i>=0;i--)
	{	printf("Enter the coef of term with exp[%d] :",i);
		scanf("%d",&data);
		insertlast(i,2,data);
	}
	
	multiplicator();
	display();

}


void multiplicator()
{	int coef, sumexp;
	struct node*temp1=poly1,*temp2;
	while(temp1!=NULL)
	{
		temp2=poly2;
		while(temp2!=NULL)
		{
			coef=((temp1->data)*(temp2->data));
			sumexp=((temp1->exp)+(temp2->exp));
			insertlast(sumexp,3,coef);
			temp2=temp2->link;
		}
		temp1=temp1->link;
	}
}



void display()
{
    struct node* temp,*temp1;
    int f;
    temp=respoly;
    temp1=respoly;
    printf("the result  is:\n");
    while(temp!=NULL)
    {
      while(temp1->link!=NULL)
      {
        if(temp->exp==temp1->link->exp)
        {
          f=temp->data;
          temp->data=temp1->link->data+f;
          temp1->link=temp1->link->link;
          }
          else
          temp1=temp1->link;
         } 
          temp=temp->link;
          temp1=temp;
          
          }
          temp=respoly;
      while(temp!=NULL)
      {
        printf("%dx^[%d] ", temp->data,temp->exp);
        temp=temp->link;
    }
    printf("\n");

}

void insertlast(int i,int opt,int data)
{
    struct node* newnode,*head,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->link=NULL;
    newnode->exp=i;
    newnode->data=data;
    
    if(opt==1)
    {
    	head=poly1;
    }
    else if(opt ==2)
    	head=poly2;
    else
    {	head=respoly;}
    
    temp=head;
    
    if((head==NULL)&&(opt==1))
    {
    	poly1=newnode;
    }
    else if((head==NULL)&&(opt==2))
    	poly2=newnode;
    else if((head==NULL)&&(opt==3))
    	respoly=newnode;
    else{
    	while(temp->link!=NULL)
    	{
    	    temp=temp->link;
    	}
   		 temp->link=newnode;}
}
