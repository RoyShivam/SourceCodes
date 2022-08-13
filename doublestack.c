#include"mylib.c"
struct dstack
{
    int *arr;
    int top1,top2;
    int cap;
};
int isfull(struct dstack *s)
{
    return s->top2-s->top1==1;
}
void top1(struct dstack *s)
{
    if(s->top1==-1)
    {
        printf("stack1 is empty!\n");
        return;
    }
    printf("stack1 top value:%d\n",s->arr[s->top1]);
}
void top2(struct dstack *s)
{
    if(s->top2==s->cap)
    {
        printf("stack2 is empty!\n");
        return;
    }
    printf("stack2 top value:%d\n",s->arr[s->top2]);
}
struct dstack* createstack(int cap)
{
    struct dstack *s=malloc(sizeof(struct dstack)*cap);
    s->top1=-1;s->top2=cap;
    s->cap=cap;
    return s;
}
void push1(struct dstack *s,int val)
{
    if(s->top1==s->top2-1)
    {
        printf("storage is full!\n");
        return;
    }
    s->top1++;
    s->arr[s->top1]=val;
}
void push2(struct dstack *s,int val)
{
    if(s->top2==s->top1+1)
    {
        printf("storage is full!\n");
        return;
    }
    s->top2--;
    s->arr[s->top2]=val;
}
void pop1(struct dstack *s)
{
    if(s->top1==-1)
    {
        printf("stack1 is empty!\n");
        return;
    }
    printf("stack1 popped value:%d\n",s->arr[s->top1--]);
}
void pop2(struct dstack *s)
{
    if(s->top2==s->cap)
    {
        printf("stack2 is empty!\n");
        return;
    }
    printf("stack2 popped value:%d\n",s->arr[s->top2++]);
}
void display(struct dstack *s)
{
    for(int i=0;i<=s->top1;i++)
    printf("stack1 value:%d\n",s->arr[i]);
    for(int i=s->cap-1;i>=s->top2;i--)
    printf("stack2 value:%d\n",s->arr[i]);
}