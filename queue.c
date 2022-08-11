#include"mylib.c"
enum type{Linear,Circular,Double};
struct queue
{
    int capacity;
    int front;
    int rear;
    int *arr;
    int isfull,isempty;
    enum type t;
};
struct queue* createqueue(int capacity,enum type t)
{
    struct queue* q=malloc(sizeof(struct queue));
    q->capacity=capacity;
    q->arr=malloc(sizeof(int)*capacity);
    q->rear=q->front=-1;
    q->isempty=1;
    q->isfull=0;
    q->t=t;
}
void displayqueuestatus(struct queue *q)
{
    printf("front:%d\n",q->front);
    printf("rear:%d\n",q->rear);
    printf("capacity:%d\n",q->capacity);
    printf("isempty?%s\n",q->isempty?"True":"False");
    printf("isfull?%s\n",q->isfull?"True":"False");
    switch(q->t)
    {
        case Linear:
        for(int i=q->front+1;i<=q->rear;i++)
        printf("%d\n",q->arr[i]);
        return;
        case Circular:
        if(q->rear>q->front)
        {
            for(int i=q->front+1;i<=q->rear;i++)
            printf("%d\n",q->arr[i]);
        }
        else
        {
            for(int i=q->front+1;i<q->capacity;i++)
            printf("%d\n",q->arr[i]);
            for(int i=0;i<=q->rear;i++)
            printf("%d\n",q->arr[i]);
        }
        return;
    }
}
void enqueue(struct queue *q,int val)
{
    if(q->isfull)
    {
        printf("queue overflow might occur!");
        return;
    }
    q->isempty=0;
    switch(q->t)
    {
        case Linear:
        q->rear++;
        q->arr[q->rear]=val;
        q->isfull=q->rear==q->capacity-1;
        break;
        case Circular:
        if(q->rear==q->capacity-1)q->rear=-1;
        q->rear++;
        q->arr[q->rear]=val;
        q->isfull=q->front==-1&&q->rear==q->capacity-1||q->rear==q->front;
        break;
    }
}
int dequeue(struct queue *q)
{
    int val=INT_MIN;
    if(q->isempty)
    {
        printf("queue underflow might occur!");
        return val;
    }
    q->isfull=0;
    switch(q->t)
    {
        case Linear:
        q->front++;
        val=q->arr[q->front];
        q->isempty=q->front==q->rear;
        break;
        case Circular:
        if(q->front==q->capacity-1)q->front=-1;
        q->front++;
        val=q->arr[q->front];
        q->isempty=q->rear==-1&&q->front==q->capacity-1||q->rear==q->front;
        break;   
    }
    return val;
}
int main()
{
    struct queue *q=NULL;
    while(1)
    {
        char c=' ';int val=0;
        printf("Create a New Queue with key:'C'\n");
        if(q!=NULL)
        {
            printf("Enequeue a value into queue with key:'A'\n");
            printf("Dequeue a value from queue with key:'P'\n");
            printf("Display Queue Status with key:'D'\n");
        }
        printf("Press any other key to quit.\n");
        printf("Enter you choice:");
        c=getch();
        printf("%c",c);getch();
        system("cls");
        switch(c)
        {
            case 'C':case 'c':
            if(q!=NULL)free(q);
            printf("Enter the capacity:");
            scanf("%d",&val);int t=0;
            printf("Enter the type of queue[0:Linear,1:Circular]:");
            scanf("%d",&t);
            q=createqueue(val,t);
            break;
            case 'A':case 'a':
            printf("Enter a value to enqueue:");
            scanf("%d",&val);
            enqueue(q,val);
            getch();
            break;
            case 'P':case 'p':
            int val=dequeue(q);
            if(val!=INT_MIN)printf("Dequeued Value is:%d\n",val);
            getch();
            break;
            case 'D':case 'd':
            displayqueuestatus(q);
            getch();
            break;
            default:
            if(q!=NULL)free(q);
            system("cls");
            return 0;
        }
        system("cls");
    }
    return 0;
}