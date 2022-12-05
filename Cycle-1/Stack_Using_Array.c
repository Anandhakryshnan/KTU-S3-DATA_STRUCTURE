//CSL201 DATA STRUCTURES LAB ----- ANANDHA KRISHNAN S
#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
int a[100];
int top=-1;
int main()
{
	int n;
	while(n!=4)
	{
		printf("enter your choice\n1.push\n2.pop\n3.display\n4.exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:display();
			break;
			case 4:exit(0);
			break;
		}
	}
	return(0);
}
void push()
{
	int data;
	if(top==10-1)
	{
		printf("overflow\n");
	}
	else
	{
		printf("push number");
		scanf("%d",&data);
		top++;
		a[top]=data;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("underflow\n");
	}
	else
	{
		printf("popped number is %d",a[top]);
		top--;
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("underflow\n");
	}
	else
	{
		printf("present elements are\n");
	for(i=top;i>=0;i--)
		printf("%d\n",a[i]);
	}
}	
