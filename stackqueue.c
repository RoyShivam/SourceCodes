#include"mylib.c"
struct stack
{
    int capacity;
    int top;
    int *arr;
};
struct stack* createstack(int capacity)
{
    struct stack* s=malloc(sizeof(struct stack));
    s->capacity=capacity;
    s->arr=malloc(sizeof(int)*capacity);
    s->top=-1;
    return s;
}
int isempty(struct stack *s)
{
    return s->top==-1;
}
int isfull(struct stack *s)
{
    return s->top==s->capacity-1;
}
void push(struct stack *s,int val)
{
    s->top++;
    s->arr[s->top]=val;
}
int pop(struct stack *s)
{
    return s->arr[s->top--];
}
struct queue
{
    struct stack* s;    
};
struct queue* createqueue(int capacity)
{
    struct queue *q=malloc(sizeof(struct queue));
    q->s=createstack(capacity);
    return q;
}
void enqueue(struct queue *q,int val)
{
    if(isfull(q->s))
    {
        printf("queue is full!\n");
        return;
    }
    push(q->s,val);
}
int dequeuerec(struct queue *q)
{
    int x=pop(q->s);
    if(isempty(q->s))return x;
    else 
    {
        int y=dequeuerec(q);
        push(q->s,x);
        return y;
    }
}
void dequeue(struct queue *q)
{
    if(isempty(q->s))
    {
        printf("queue is empty!\n");
        return;
    }
    int x=dequeuerec(q);
    printf("dequeued value:%d\n",x);
}
void displayrec(struct queue *q)
{
    int x=pop(q->s);
    if(isempty(q->s))
    {
        printf("queue value:%d\n",x);
        push(q->s,x);
        return;
    }
    else
    {
        displayrec(q);
        printf("queue value:%d\n",x);
        push(q->s,x);
    }
}
void display(struct queue *q)
{
    if(isempty(q->s))
    return;
    displayrec(q);
}