//CSL201 DATA STRUCTURES LAB ----- ANANDHA KRISHNAN
#include<stdio.h>
int binarysearch(int a[],int,int,int);
int main()
	{
		int a[10],data,n,status,i;
			printf("\nenter the size of the array: \n");
			scanf("%d",&n);
			printf("\nenter the elements in ascending order : \n:");
				for (i=0;i<n;i++)
					scanf("%d",&a[i]);
					printf("enter the data to be searched : ");
					scanf("%d",&data);
					status=binarysearch(a,data,0,n-1);
				if(status==(-1))
					printf("\nitem not present\n");
				else
					printf("\nthe item is located in position array[%d]\n",status);
						return 0;
	}
		int binarysearch(int a[],int data,int l,int h)
		{
			int mid;
				if(l>h)
					return (-1);
				else
					{
						mid=(l+h)/2;
				if(a[mid]==data)
					return mid;
				else if (a[mid]>data)
					return binarysearch(a,data,l,mid-1);
				else
					return binarysearch(a,data,mid+1,h);
					}
		}
