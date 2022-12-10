//CSL201 DATA STRUCTURES LAB ----- ANANDHA KRISHNAN
#include<stdio.h>
#define MAX 20
#define SET 25
struct node
{
	int row,col,value;
}a[SET];
int mat[MAX][MAX];
void sparse(int ,int);
void display();

int main()
{	int r,c;
	printf("enter the no of rows:");
	scanf("%d",&r);
	printf("enter the no of columns:");
	scanf("%d",&c);
	printf("enter the matrix:\n");
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			printf("[%d][%d] : ",i,j);
			scanf("%d",&mat[i][j]);
		}
	}
	sparse(r,c);
	display();
}

void sparse(int r,int c)
{	int count=0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if((mat[i][j])!=0)
				{
					count++;	
				}
			}
		}
		a[0].row=r;
		a[0].col=c;
		a[0].value=count;
		int k=1;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if((mat[i][j])!=0)
				{
					a[k].row=i;
					a[k].col=j;
					a[k].value=mat[i][j];
					k++;	
				}
			}
		}
}
void display()

{	int i=0;
	printf("The matrix is\n");
	for(int i=1;i<a[0].value+1;i++)
	{
		
		printf("%6d %6d %8d\n",a[i].row,a[i].col,a[i].value);
	}
}
