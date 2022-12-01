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
void deln(struct node *root)
{
	
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
int main()
{
	struct node *root=createnode(1);
	insert(root,2);
	insert(root,3);
	leveltraversal(root);
	delt(root);
	return 0;
}