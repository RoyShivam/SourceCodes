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
   if(isempty(s))return INT_MIN;
   return s->arr[s->top--];
}
void movedisk(char s,char d,struct stack *ss,struct stack *ds)
{
    int sv=pop(ss);
    int dv=pop(ds);
    if(dv==INT_MIN||sv!=INT_MIN&&sv<dv)
    {
        if(dv!=INT_MIN)push(ds,dv);
        push(ds,sv);
        printf("move %d from %c to %c\n",sv,s,d);
    }
    else
    {
        if(sv!=INT_MIN)push(ss,sv);
        push(ss,dv);
        printf("move %d from %c to %c\n",dv,d,s);
    }
}
void tohiterative(int dn)
{
    struct stack* ss=createstack(dn);
    struct stack* as=createstack(dn);
    struct stack* ds=createstack(dn);
    char s='A',a='B',d='C';
    int n=pow(2,dn)-1;
    if(dn%2==0)swapc(&a,&d);
    for(int i=dn;i>0;i--)push(ss,i);
    for(int i=1;i<=n;i++)
    {
        switch(i%3)
        {
            case 1:movedisk(s,d,ss,ds);break;
            case 2:movedisk(s,a,ss,as);break;
            case 0:movedisk(a,d,as,ds);break;
        }
    }
    free(ss);
    free(as);
    free(ds);
}
void tohrec(int n,char s,char a,char d)
{
    if(n==0)return;
    tohrec(n-1,s,d,a);
    printf("move %d from %c to %c\n",n,s,d);
    tohrec(n-1,a,s,d);
}