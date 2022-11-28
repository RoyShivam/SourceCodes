#include<stdio.h>
struct node
{
	int coeff,exp;
	struct *node next;
};
struct *node createnode(int coeff,int exp)
{
	struct *node n=malloc(sizeof(struct node));
	n->coeff=coeff;
	n->exp=exp;
}
int main()
{
	return 0;
}