//CSL201 DATA STRUCTURES LAB ----- ANANDHA KRISHNAN
#include<stdio.h>
int linearsearch(int a[],int,int);
int main()
{
	int a[10],data,n,status,i;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the data to be searched : ");
	scanf("%d",&data);
	status=linearsearch(a,data,n);
	if(status==(-1))
		printf("\nItem not present\n");
	else
		printf("\nThe item is located in position a[%d]\n",status);
	return 0;
}
int linearsearch(int a[],int data,int n)
{
	int i,flag=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==data)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		return i;
	else
		return (-1);
}				
