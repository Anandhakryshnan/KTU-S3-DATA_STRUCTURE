#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
};

struct node * insert(struct node *,int);
struct node *delete(struct node *,int);
struct node * inorder(struct node *);
struct node * postorder(struct node *);
struct node *preorder(struct node *);
struct node *minnode(struct node *);

int main()
{	struct node *root=NULL;
    int choice,data;
    while(1)
    {
        printf("\n 1.insert \n 2.delete \n 3.inorder \n 4.preorder\n 5.postorder\n 6.exit\n");
        printf("enter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:	printf("enter data:");
            		scanf("%d",&data); 
            		root=insert(root,data);
                    break;
            case 2: 
            		printf("enter data:");
            		scanf("%d",&data); 
            		root=delete(root,data);
                    break;
            case 3: inorder(root);
                    break;
            case 4:preorder(root); break;
            case 5: postorder(root); break;
            case 6: exit(0);
            default : printf("invalid option:");
        }
    }
    return(0);
}


struct node *delete(struct node *root,int data)
{	struct node *temp;
	if(root==NULL)
	{
		printf("element not present\n");
		return root;
	}
	else if(data<(root->data))
	{	root->left=delete(root->left,data);}
	else if(data>(root->data))
	{	root->right=delete(root->right,data);}
	else
	{
		if(root->left==NULL && root->right ==NULL)
		{
			
			free(root);
			return NULL;
		}
		else if(root->left==NULL)
		{
		
			temp=root->right;
			
			free(root);
			return(temp);
		}
		else if(root->right==NULL)
		{
		
			temp=root->left;
			
			free(root);
			return(temp);
		}
		else
		{
			temp=minnode(root->right);
			root->data=temp->data;
			root->right=delete(root->right,temp->data);
			
		}
		
	
	}
	return root;
	
}
struct node * insert(struct node *root,int data)
{
	struct node *newnode;
	if(root==NULL)
	{
	
		newnode=(struct  node*)malloc(sizeof(struct node));
		newnode->left=newnode->right=NULL;
		newnode->data=data;
		return newnode;
				
	}
	else 
	{
		if((root->data)>data)
			{root->left=insert(root->left,data);}
		else
			{root->right=insert(root->right,data);}
	}
	return root;

}
struct node * minnode(struct node *root)
{	struct node *temp=root;
	
	while(temp->left!=NULL)
	{			temp=temp->left;
	
	}
	return temp;
}

struct node * inorder(struct node * root)
{
	if(root==NULL)
		{return root;}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
	return root;	
}
struct node * preorder(struct node * root)
{
	if(root==NULL)
		{return root;}
	printf("%d ",root->data);
	preorder(root->left);
	
	preorder(root->right);
	return root;	
}
struct node * postorder(struct node * root)
{
	if(root==NULL)
		{return root;}
	postorder(root->left);
	
	postorder(root->right);
	printf("%d ",root->data);
	return root;	
}
