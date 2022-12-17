#include<stdio.h>
#define MAX  20 
void sort(int a[],int n);
void display(int a[],int);
int main()
{
	int a[20],n;
	
	printf("enter the limit:");
	scanf("%d",&n);
	printf("enter the elements:\n");
	for (int i=0;i<n;i++)
	{scanf("%d",&a[i]);}
	sort(a,n);
	display(a,n);
}

void sort(int a[],int n)
{ 
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j+1]<a[j])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

void display(int a[],int n)
{	printf("the sorted list is:");
	for (int i=0;i<n;i++)
	{printf("%d ",a[i]);}
	printf("\n");
}
