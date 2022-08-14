#include"mylib.c"
struct Node
{
    int data;
    struct Node* next;
};
struct LL
{
    struct Node* h;
};
struct Node* createnode()
{
    struct Node* n=malloc(sizeof(struct Node));
    n->data=INT_MIN;
    n->next=NULL;
    return n;
}
struct LL* createll(int size)
{
    struct LL *ll=malloc(sizeof(struct LL));
    ll->h=NULL;
    if(size<1)return ll;
    struct Node* h=createnode();
    ll->h=h;
    struct Node *th=h;
    for(int i=1;i<size;i++)
    {
        th->next=createnode();
        th=th->next;
    }
    return ll;
}
void del(struct LL *ll)
{
    struct Node* h=ll->h;
    while(h)
    {
        struct Node *n=h->next;
        free(h);
        h=n;
    }
    free(ll);
}
int lenll(struct Node *h)
{
    int l=0;
    while(h)
    {
        h=h->next;
        l++;
    }
    return l;
}
void inpllval(struct Node *h)
{
    int len=0;
    while(h)
    {
        int val=0;
        printf("%d:",len++);
        scanf("%d",&val);
        h->data=val;
        h=h->next;
    }
}
void printll(struct Node *h)
{
    printf("\n");
    while(h)
    {
        printf("%d\n",h->data);
        h=h->next;
    }
}
void printllwithindex(struct Node *h)
{
    printf("\n");
    int l=0;
    while(h)
    {
        printf("%d:%d\n",l++,h->data);
        h=h->next;
    }
}
struct LL* genll(int size,int max)
{
    srand(time(0));
    struct LL *ll=createll(size);
    struct Node *th=ll->h;
    while(th)
    {
        th->data=rand()%max;
        th=th->next;
    }
    return ll;
}
struct Node* mid_1(struct Node *h)
{
    struct Node *m=h;
    int c=0;
    while(h)
    {
        if(c%2)m=m->next;
        c++;
        h=h->next;
    }
    return m;
}
struct Node* mid_2(struct Node *h)
{
    struct Node *s=h;
    struct Node* f=h;
    while(f&&f->next)
    {
        s=s->next;
        f=f->next->next;
    }
    return s;
}
struct Node* mid_3(struct Node *h,int n)
{
    int c=0,m=n/2;
    while(h)
    {
        if(c==m)return h;
        c++;
        h=h->next;
    }
    return NULL;
}
void push(struct LL *ll,int val)
{
    struct Node *nn=createnode();
    nn->data=val;
    nn->next=ll->h;
    ll->h=nn;
}
void insert(struct LL *ll,int ind,int val)
{
    struct Node *nn=createnode();
    nn->data=val;
    struct Node *tn=ll->h;int i=0;
    while(i<ind-1&&tn)
    {
        tn=tn->next;
        i++;
    }
    if(i==ind)
    {
        nn->next=ll->h;
        ll->h=nn;
        return;
    }
    if(ind<0||!tn||!tn->next)
    {
        printf("insert index not found!\n");
        return;
    }
    nn->next=tn->next;
    tn->next=nn;
}
void delllind(struct LL *ll,int ind)
{
    int i=0;
    struct Node *tn=ll->h;
    while(i<ind-1&&tn)
    {
        tn=tn->next;
        i++;
    }
    if(i==ind)
    {
        tn=tn->next;
        free(ll->h);
        ll->h=tn;
        return;
    }
    if(ind<0||!tn||!tn->next)
    {
        printf("delete index not found!\n");
        return;
    }
    struct Node *nn=tn->next->next;
    free(tn->next);
    tn->next=nn;
}
void delllkey(struct LL *ll,int key)
{
    struct Node *tn=ll->h;
    if(tn->data==key)
    {
        tn=tn->next;
        free(ll->h);
        ll->h=tn;
        return;
    }
    while(tn->next)
    {
        if(tn->next->data==key)
        {
            struct Node *nn=tn->next->next;
            free(tn->next);
            tn->next=nn;
            return;
        }
        tn=tn->next;
    }
    printf("key value not found!");
}
void revll(struct LL *ll)
{
    struct Node *prev=NULL;
    struct Node *curr=ll->h;
    struct Node *n=NULL;
    while(curr)
    {
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }
    ll->h=prev;
}