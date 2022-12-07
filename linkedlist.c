#include<stdio.h>
#include<stdlib.h>
struct node
{
	void *data;
	struct node *next;
};
struct node *createnode(void *data)
{
	struct node *n=malloc(sizeof(struct node));
	n->data=data;
	n->next=NULL;
	return n;
}
void insert(struct node *root,void *data)
{
	struct node *newNode=createnode(data);
	while(root->next)root=root->next;
	root->next=newNode;
}
void delnode(struct node **root,void *data)
{
	struct node *head=*root;
	if(head->data==data)
	{
		*root=head->next;	
		free(head);
		return;
	}
	while(head->next&&head->next->data!=data)head=head->next;
	struct node *delNode=head->next;
	head->next=delNode->next;
	free(delNode);
}
void *pop(struct node **root)
{
	struct node *head=*root;
	struct node *data=head->data;
	*root=head->next;
	free(head);
	return data;
}
void del(struct node *root)
{
	while(root)
	{
		struct node *nextNode=root->next;
		free(root);
		root=nextNode;
	}
}
void reverse(struct node **root)
{
	struct node *prevHead=*root,*newHead=NULL;
	while(prevHead)
	{
		struct node *nextNode=newHead;
		newHead=prevHead;
		prevHead=prevHead->next;
		newHead->next=nextNode;
	}
	*root=newHead;
}