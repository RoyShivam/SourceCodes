#include"mylib.c"
struct nstack
{
    int *arr;
    int *top;
    int *next;
    int cap,free,n;
};
struct nstack* createstack(int cap,int n)
{
    struct nstack *s=malloc(sizeof(struct nstack));
    s->n=n;
    s->arr=malloc(sizeof(int)*cap);
    s->top=malloc(sizeof(int)*n);
    s->next=malloc(sizeof(int)*cap);
    for(int i=0;i<n;i++)s->top[i]=-1;
    for(int i=0;i<cap;i++)s->next[i]=i+1;
    s->free=0;
    s->cap=cap;
    return s;
}
int isfull(struct nstack *s)
{
    return s->free==s->cap;
}
int isempty(struct nstack *s,int ind)
{
    return s->top[ind]==-1;
}
void push(struct nstack *s,int ind,int val)
{
    if(isfull(s))
    {
        printf("storage is full!\n");
        return;
    }
    int i=s->free;
    s->free=s->next[i];
    s->next[i]=s->top[ind];
    s->top[ind]=i;
    s->arr[i]=val;
}
void pop(struct nstack *s,int ind)
{
    if(isempty(s,ind))
    {
        printf("stack%d is empty!\n",ind);
        return;
    }
    int i=s->top[ind];
    s->top[ind]=s->next[i];
    s->next[i]=s->free;
    s->free=i;
    printf("stack%d popped value:%d\n",ind,s->arr[i]);
}
void revdisplay(struct nstack *s)
{
    for(int i=0;i<s->n;i++)
    {
        int j=s->top[i];
        while(j!=-1)
        {
            printf("stack%d value:%d\n",i,s->arr[j]);
            j=s->next[j];
        }
    }
}