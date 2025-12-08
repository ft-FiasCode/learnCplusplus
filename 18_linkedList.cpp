#include<stdio.h>
struct node
{
	int info;
	struct node *link;
};o

struct node *HEAD=NULL;
struct node* createNode()
{
	struct node *n;
	n= (struct node *)malloc(sizeof(struct node));
	return	(n);
}

void insertNode()
{
	struct node *temp,*t;
	temp= createNode();
	printf("Enter a number");
	scanf("%d",&temp->info);
	temp->link=NULL;
	
	if(HEAD==NULL)
	  HEAD=temp;
	  
	else
	{
		t=HEAD;
		while(t->link!=NULL)
		t->link;
		t->=temp;
	}
	
	
}
