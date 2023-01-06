#include<stdio.h>

#include<stdlib.h>

#define SIZE 10

void insert(int);

void delete(int);

void search(int);

struct node {

    int data;

    struct node* next;

} *chain[SIZE];

int main()

{

    int choice,n,data;

    while(1){

    printf("\n1.insert \n2.delete\n3.search\n4.exit\n enter your choice:");

    scanf("%d",&n);

    switch(n)

    {

    case 1 :

        printf("enter number: ");

        scanf("%d",&data);

        insert(data);

        break;

    case 2:

        printf("enter number: ");

        scanf("%d",&data);

        delete(data);

        break;

    case 3 :

         printf("enter number: ");

        scanf("%d",&data);

        search(data);

        break;

   case 4:exit(0);

    }

    }

    return(0);

}

void insert(int data)

{

    struct node *newnode= malloc(sizeof(struct node));

    newnode->data=data;

    newnode->next=NULL;

    int key=data%SIZE;

    if(chain[key]==NULL)

    {

        chain[key]=newnode;

    }

    else

    {

        struct node *temp =chain[key];

        while(temp->next!=NULL)

        {

            temp=temp->next;

        }

        temp->next=newnode;

    }

}

void delete(int data)

{

    int key,flag=0;

    key=data%SIZE;

    struct node *temp =chain[key];

    struct node *temp2 =chain[key];

     

     if(chain[key]!=NULL){

    if((chain[key]->data==data))

    {

        temp=chain[key]->next;

        free(chain[key]);

        chain[key]=temp;

        flag=1;

    }

    else

    {

        temp=chain[key];

        while(temp->next!=NULL)

        {

            if(temp->next->data==data)

            {

                temp2=(temp->next)->next;

                free(temp->next);

                temp->next=temp2;

                flag=1;

                break;

            }

            temp=temp->next;

        }

    }

    }

    if(flag==0)

    {

        printf("not present");

    }

    

}

void search(int data)

{

    int flag=0,key;

    key=data%SIZE;

    struct node *temp =chain[key];

    while(temp!=NULL)

    {

        if(temp->data==data)

        {

            flag=1;

            break;

        }

        temp=temp->next;

    }

    if(flag==1)

    {

        printf("Present in chain at %d",key);

    }

    else

    {

        printf("not found");

    }

}
