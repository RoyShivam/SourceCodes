#include<stdio.h>
#include<stdlib.h>
struct qnode
{
	void *data;
	struct qnode *next;
};
struct queue{struct qnode *front,*rear;};
struct qnode *createqnode(void *data)
{
	struct qnode *q=malloc(sizeof(struct qnode));
	q->next=NULL;
	q->data=data;
	return q;
}
struct queue *createqueue()
{
	struct queue *q=malloc(sizeof(struct queue));
	q->front=q->rear=NULL;
	return q;
}
int isempty(struct queue *q){return q->front==NULL;}
void enqueue(struct queue *q,void *data)
{
	struct qnode *qn=createqnode(data);
	if(isempty(q))
	{
		q->front=q->rear=qn;
		return;
	}
	q->rear->next=qn;
	q->rear=qn;
}
void *dequeue(struct queue *q)
{
	if(isempty(q))return NULL;
	struct qnode *qn=q->front;
	q->front=qn->next;
	void *data=qn->data;
	free(qn);
	return data;
}
void delq(struct queue *q)
{
	struct qnode *qn=q->front;
	while(qn)
	{
		struct qnode *next=qn->next;
		free(qn);
		qn=next;
	}
	free(q);
}