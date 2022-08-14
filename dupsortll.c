#include"linkedlist.c"
void delduplicate(struct Node *h)
{
    while(h->next)
    {
        if(h->next->data==h->data)
        {
            struct Node *n=h->next->next;
            free(h->next);
            h->next=n;
            continue;
        }
        h=h->next;
    }
}