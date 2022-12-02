#include<stdlib.h>
#include<stdlib.h>
struct snode
{
	void *data;
	struct snode *next;
};
struct stack{struct snode *top;};
struct snode *createsnode(void *data)
{
	struct snode *n=malloc(sizeof(struct snode));
	n->data=data;
	n->next=NULL;
	return n;
}
struct stack *createstack()
{
	struct stack *s=malloc(sizeof(struct stack));
	s->top=NULL;
	return s;
}
int isempty(struct stack *s){return s->top==NULL;}
void push(struct stack *s,void *data)
{
	struct snode *n=createsnode(data);
	n->next=s->top;
	s->top=n;
}
void *pop(struct stack *s)
{
	struct snode *n=s->top;
	s->top=n->next;
	void *data=n->data;
	free(n);
	return data;
}
void dels(struct stack *s)
{
	struct snode *n=s->top;
	while(n)
	{
		struct snode *next=n->next;
		free(n);
		n=next;
	}
	free(s);
}