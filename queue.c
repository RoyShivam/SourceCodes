#include"mylib.c"
enum type{Linear,Circular};
struct queue
{
    int capacity;
    int front;
    int rear;
    int *arr;
    enum type t;
};
struct queue* createqueue(int capacity,enum type t)
{
    struct queue* q=malloc(sizeof(struct queue));
    q->capacity=capacity;
    q->arr=malloc(sizeof(int)*capacity);
    q->rear=q->front=-1;
    q->t=t;
}
int isfull(struct queue *q)
{
    switch(q->t)
    {
        case Linear:return q->front==0&&q->rear==q->capacity-1;
        case Circular:
        return q->front==0&&q->rear==q->capacity-1||q->rear==q->front-1;
    }
}
int isempty(struct queue *q)
{
    return q->front==-1;
}
void front(struct queue *q)
{
    if(isempty(q))
    {
        printf("queue is empty!");
        return;
    }
    printf("rear value:%d\n",q->arr[q->front]);
}
void rear(struct queue *q)
{
    if(isempty(q))
    {
        printf("queue is empty!");
        return;
    }
    printf("rear value:%d\n",q->arr[q->rear]);
}
void display(struct queue *q)
{
    if(isempty(q))return;
    switch(q->t)
    {
        case Linear:
        for(int i=q->front;i<=q->rear;i++)
        printf("queue value:%d\n",q->arr[i]);
        return;
        case Circular:
        if(q->rear>=q->front)
        {
            for(int i=q->front;i<=q->rear;i++)
            printf("queue value:%d\n",q->arr[i]);
        }
        else
        {
            for(int i=q->front;i<q->capacity;i++)
            printf("queue value:%d\n",q->arr[i]);
            for(int i=0;i<=q->rear;i++)
            printf("queue value:%d\n",q->arr[i]);
        }
        return;
    }
}
void enqueue(struct queue *q,int val)
{
    if(isfull(q))
    {
        printf("queue is full!\n");
        return;
    }
    switch(q->t)
    {
        case Linear:
        if(q->front==-1)q->front=q->rear=0;
        else q->rear++;
        q->arr[q->rear]=val;
        return;
        case Circular:
        if(q->front==-1)q->front=q->rear=0;
        else if(q->rear==q->capacity-1)q->rear=0;
        else q->rear++;
        q->arr[q->rear]=val;
        return;
    }
}
void dequeue(struct queue *q)
{
    if(isempty(q))
    {
        printf("queue is empty!\n");
        return;
    }
    switch(q->t)
    {
        case Linear:
        printf("dequeued value:%d\n",q->arr[q->front++]);
        if(q->front==q->rear+1)q->front=q->rear=-1;
        return;
        case Circular:
        if(q->front==q->capacity-1)q->front=0;
        printf("dequeued value:%d\n",q->arr[q->front++]);
        if(q->front==q->rear+1)q->front=q->rear=-1;
        return;
    }
}