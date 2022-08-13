#include"mylib.c"
struct stack
{
    int capacity;
    int top;
    char *arr;
};
struct stack* createstack(int capacity)
{
    struct stack* s=malloc(sizeof(struct stack));
    s->capacity=capacity;
    s->arr=malloc(sizeof(char)*capacity);
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
char top(struct stack *s)
{
    return s->arr[s->top];
}
void push(struct stack *s,char val)
{
    s->top++;
    s->arr[s->top]=val;
}
char pop(struct stack *s)
{
    char c=s->arr[s->top];
    s->top--;
    return c;
}
int isbrace(char c)
{
    switch(c)
    {
        case '(':return 1;
        case ')':return 2;
        default:return 0;
    }
}
int opprec(char c)
{
    switch(c)
    {
        case '-':return 1;
        case '+':return 2;
        case '%':return 3;
        case '/':return 4;
        case '*':return 5;
        case '^':return 6;
        default:return 0;
    }
}
int postfixconversion(char *infstr,char *postfstr,int opprec(char),int isbrace(char))
{
    int n=len(infstr);int j=0;
    struct stack* s=createstack(n);
    for(int i=0;i<n;i++)
    {
        char c=infstr[i];
        int op=opprec(c);
        int b=isbrace(c);
        if(op)
        {
            if(isempty(s)||opprec(c)>opprec(top(s)))
            push(s,c);
            else
            {
                while(!isempty(s)&&!isbrace(top(s))&&opprec(c)<opprec(top(s)))
                postfstr[j++]=pop(s);
                push(s,c);
            }
        }
        else if(b)
        {
            if(b==1)push(s,c);
            else if(b==2)
            {
                while(!isempty(s)&&isbrace(top(s))!=1)
                postfstr[j++]=pop(s);
                pop(s);
            }
        }
        else postfstr[j++]=c;
    }
    while(!isempty(s))postfstr[j++]=pop(s);
    postfstr[j]='\0';
    free(s);
    return j;
}