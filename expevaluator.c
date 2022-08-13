#include"postfixconversion.c"
struct dstack
{
    int capacity;
    int top;
    double *arr;
};
struct dstack* createdstack(int capacity)
{
    struct dstack* s=malloc(sizeof(struct dstack));
    s->capacity=capacity;
    s->arr=malloc(sizeof(double)*capacity);
    s->top=-1;
    return s;
}
int isdempty(struct dstack *s)
{
    return s->top==-1;
}
int isdfull(struct dstack *s)
{
    return s->top==s->capacity-1;
}
void dpush(struct dstack *s,double val)
{
    s->top++;
    s->arr[s->top]=val;
}
double dpop(struct dstack *s)
{
    return s->arr[s->top--]; 
}
double eval(double a,double b,char c)
{
    switch(c)
    {
        case '-':return a-b;
        case '+':return a+b;
        case '%':return a-((int)a/(int)b)*b;
        case '/':return a/b;
        case '*':return a*b;
        case '^':return pow(a,b);
    }
}
double expresult(char *infexp,char *postfexp,double eval(double,double,char),int opprec(char),int isbrace(char))
{
    double r=0;
    int l=postfixconversion(infexp,postfexp,opprec,isbrace);
    struct dstack *s=createdstack(l);
    for(int i=0;i<l;i++)
    {
        char c=postfexp[i];
        int o=opprec(c);
        if(o)
        {
            double b=dpop(s);
            double a=dpop(s);
            dpush(s,eval(a,b,c));
        }
        else
        {   
            double val=0;
            scanf("%lf",&val);
            dpush(s,val);
        }
    }
    r=dpop(s);
    free(s);
    return r;
}