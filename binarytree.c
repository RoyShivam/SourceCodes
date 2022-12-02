#include"ll_queue.c"
struct node
{
	int data;
	struct node *left,*right;
};
struct node *createnode(int data)
{
	struct node *n=malloc(sizeof(struct node));
	n->data=data;
	n->left=n->right=NULL;
	return n;
}
void insert(struct node *root,int data)
{
	struct node *nn=createnode(data);
	struct queue *q=createqueue();
	enqueue(q,root);
	while(!isempty(q))
	{
		struct node *n=(struct node*)dequeue(q);
		if(!n->left){n->left=nn;return;}
		else if(!n->right){n->right=nn;return;}
		if(n->left)enqueue(q,n->left);
		if(n->right)enqueue(q,n->right);
	}
	delq(q);
}
void deldeepest(struct node *root,struct node *dnode)
{
	struct queue *q=createqueue();
	enqueue(q,root);
	while(!isempty(q))
	{
		struct node *n=(struct node*)dequeue(q);
		if(n->left)
		{
			if(n->left==dnode){n->left=NULL;return;}
			enqueue(q,n->left);
		}
		if(n->right)
		{
			if(n->right==dnode){n->right=NULL;return;}
			enqueue(q,n->right);
		}
	}
	delq(q);
}
void deln(struct node **root,int data)
{
	struct node *visitNode=NULL,*delNode=NULL,*delRootNode=NULL;
	struct queue *q=createqueue();
	enqueue(q,*root);
	while(!isempty(q))
	{
		visitNode=(struct node*)dequeue(q);
		if(visitNode->data==data)delNode=visitNode;
		if(visitNode->left)
		{
			enqueue(q,visitNode->left);
			if(visitNode->left->data==data)
			{
				delRootNode=visitNode;
				delNode=visitNode->left;
			}
		}
		if(visitNode->right)
		{
			enqueue(q,visitNode->right);
			if(visitNode->right->data==data)
			{
				delRootNode=visitNode;
				delNode=visitNode->right;
			}
		}
	}
	delq(q);
	if(delNode)
	{
		if(!delRootNode)
		{
			deldeepest(*root,visitNode);
			visitNode->left=(*root)->left;
			visitNode->right=(*root)->right;
			*root=visitNode;
		}
		else if(visitNode==delNode)
		{
			if(delRootNode->left&&delRootNode->left==delNode)delRootNode->left=NULL;
			else delRootNode->right=NULL;
		}
		else
		{
			visitNode->left=delNode->left;
			visitNode->right=delNode->right;
			if(delNode->left==visitNode)visitNode->left=NULL;
			else if(delNode->right==visitNode)visitNode->right=NULL;
			deldeepest(*root,visitNode);
			if(delRootNode->left&&delRootNode->left==delNode)delRootNode->left=visitNode;
			else delRootNode->right=visitNode;
		}
		free(delNode);
	}
}
void pretraversal(struct node *root)
{
	printf("%d,",root->data);
	if(root->left)pretraversal(root->left);
	if(root->right)pretraversal(root->right);	
}
void posttraversal(struct node *root)
{
	if(root->left)posttraversal(root->left);
	if(root->right)posttraversal(root->right);
	printf("%d,",root->data);	
}
void intraversal(struct node *root)
{
	if(root->left)intraversal(root->left);
	printf("%d,",root->data);
	if(root->right)intraversal(root->right);
}
void delt(struct node *root)
{
	if(root->left)delt(root->left);
	if(root->right)delt(root->right);
	free(root);
}
void leveltraversal(struct node *root)
{
	struct queue *q=createqueue();
	enqueue(q,root);
	while(!isempty(q))
	{
		struct node *n=(struct node*)dequeue(q);
		printf("%d,",n->data);
		if(n->left)enqueue(q,n->left);
		if(n->right)enqueue(q,n->right);
	}
	delq(q);
}