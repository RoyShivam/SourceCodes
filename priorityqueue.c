#include"mylib.c"
struct data
{
    int val;
    int p;
};
struct queue
{
    int front,rear;
    struct data *arr;
    int capacity;
};
struct queue* createqueue(int cap)
{
    struct queue *q=malloc(sizeof(struct queue));
    q->front=q->rear=-1;
    q->arr=malloc(sizeof(struct data)*cap);
    q->capacity=cap;
    return q;
}
int isempty(struct queue *q)
{
    return q->front==-1;
}
int isfull(struct queue *q)
{
    return q->front==0&&q->rear==q->capacity-1||q->rear==q->front-1;
}
void enqueue(struct queue *q,int val,int p)
{
    if(isfull(q))
    {
        printf("queue is full!\n");
        return;
    }
    if(q->front==-1)q->front=q->rear=0;
    else if(q->rear==q->capacity-1)q->rear=0;
    else q->rear++;
    q->arr[q->rear].val=val;
    q->arr[q->rear].p=p;
}
int highpriorindex(struct queue *q)
{
    int ind=q->front;
    if(q->rear==q->front)return q->front;
    if(q->rear>=q->front)
    {
        for(int i=q->front+1;i<=q->rear;i++)
        {
            if(q->arr[i].p>q->arr[ind].p)
            ind=i;
        }
    }
    else
    {
        for(int i=q->front+1;i<q->capacity;i++)
        {
            if(q->arr[i].p>q->arr[ind].p)
            ind=i;
        }
        for(int i=0;i<=q->rear;i++)
        {
            if(q->arr[i].p>q->arr[ind].p)
            ind=i;
        }
    }
    return ind;
}
void dequeue(struct queue *q)
{
    if(isempty(q))
    {
        printf("queue is empty!\n");
        return;
    }
    int ind=highpriorindex(q);
    struct data val=q->arr[ind];
    printf("dequeued value:%d:%d\n",val.val,val.p);
    if(ind==q->front)
    {
        if(q->front==q->rear)q->front=q->rear=-1;
        else if(q->front==q->capacity-1)q->front=0;
        else q->front++;
    }
    else if(ind==q->rear)
    {
        if(q->rear==0)q->capacity-1;
        else q->rear--;
    }
    else
    {
        for(int i=ind;i<q->capacity-1;i++)
        {
            q->arr[i].val=q->arr[i+1].val;
            q->arr[i].p=q->arr[i+1].p;
        }
        q->arr[q->capacity-1].val=q->arr[0].val;
        q->arr[q->capacity-1].p=q->arr[0].p;
        for(int i=0;i<q->rear;i++)
        {
            q->arr[i].val=q->arr[i+1].val;
            q->arr[i].p=q->arr[i+1].p;
        }
        q->rear--;
    }
}
void display(struct queue *q)
{
    if(isempty(q))return;
    if(q->rear>=q->front)
    {
        for(int i=q->front;i<=q->rear;i++)
        printf("%d:%d\n",q->arr[i].val,q->arr[i].p);
    }
    else
    {
        for(int i=q->front;i<q->capacity;i++)
        printf("%d:%d\n",q->arr[i].val,q->arr[i].p);
        for(int i=0;i<=q->rear;i++)
        printf("%d:%d\n",q->arr[i].val,q->arr[i].p);
    }
}