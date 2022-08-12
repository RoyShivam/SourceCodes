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
void top(struct stack *s)
{
    if(isempty(s))
    {
        printf("stack is empty!\n");
        return;
    }
    printf("top value:%d\n",s->arr[s->top]);
}
void push(struct stack *s,int val)
{
    if(isfull(s))
    {
        printf("stack is full!\n");
        return;
    }
    s->top++;
    s->arr[s->top]=val;
}
void pop(struct stack *s)
{
    if(isempty(s))
    {
        printf("stack is empty!\n");
        return;
    }
    printf("popped value:%d\n",s->arr[s->top]);
    s->top--;
}
void display(struct stack *s)
{
    for(int i=0;i<=s->top;i++)
    printf("stack value:%d\n",s->arr[i]);
}