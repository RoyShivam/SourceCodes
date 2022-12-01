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
int main()
{
	return 0;
}