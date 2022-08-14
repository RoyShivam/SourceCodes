#include"linkedlist.c"
int floydcycledetect(struct Node *h)
{
    struct Node *sn=h;
    struct Node *fn=h;
    while(fn&&fn->next)
    {
        sn=sn->next;
        fn=fn->next->next;
        if(fn&&sn==fn->next)return 1;
    }
    return 0;
}
int looplen(struct Node *h)
{
    struct Node *sn=h;
    struct Node *fn=h;
    while(fn&&fn->next)
    {
        sn=sn->next;
        fn=fn->next->next;
        if(fn&&sn==fn->next)
        {
            int c=1;
            struct Node *n=sn;
            struct Node *tn=sn->next;
            while(tn!=n)
            {
                tn=tn->next;
                c++;
            }
            return c;
        }
    }
    return 0;
}