#include<stdio.h>
#include"ll_stack.c"
struct node
{
	char data;
	struct node *left,*right;
};
struct node *createnode(char c)
{
	struct node *n=malloc(sizeof(struct node));
	n->data=c;
	n->left=n->right=NULL;
	return n;
}
void intraversal(struct node *root)
{
	if(!root)return;
	if(root->left)intraversal(root->left);
	printf("%c ",root->data);
	if(root->right)intraversal(root->right);
}
int isop(char c)
{
	switch(c)
	{
		case '+':case '-':case '*':case '/':return 1;
		default:return 0;
	}
}
int opresult(char c,int a,int b)
{
	switch(c)
	{
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
		default:return 0;
	}
}
void conversion(char *exp,int n,struct node **root)
{
	struct stack *s=createstack();
	for(int i=0;i<n;i++)
	{
		char c=exp[i];
		struct node *n=createnode(c);
		if(isop(c))
		{
			struct node *n2=(struct node*)pop(s);
			struct node *n1=(struct node*)pop(s);
			n->left=n1;n->right=n2;
			push(s,n);
		}
		else push(s,n);
	}
	struct node *r=(struct node*)pop(s);
	*root=r;
	dels(s);
}
int calc(struct node *root)
{
	if(!root)return 0;
	char c=root->data;
	if(isop(c))
	{
		int leftval=calc(root->left);
		int rightval=calc(root->right);
		int r=opresult(c,leftval,rightval);
		return r;
	}
	else
	{
		printf("%c value:",c);
		int val=0;
		scanf("%d",&val);
		return val;
	}
}
int main()
{
	char exp[]="abc*+de*f-g*/";int n=13;
	struct node *root=NULL;
	conversion(exp,n,&root);
	intraversal(root);printf("\n");
	printf("result:%d",calc(root));
	return 0;
}