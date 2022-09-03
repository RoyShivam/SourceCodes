#include"mylib.c"
struct Node
{
    int data;
    struct Node *leftNode,*rightNode;
};
struct Node* createnode(int val)
{
    struct Node* t=malloc(sizeof(struct Node));
    t->data=val;
    t->leftNode=t->rightNode=NULL;
    return t;
}
int insertafter(struct Node *root,int valaft,int s,int val)
{
    if(!root)return 0;
    if(root->data==val)
    {
        if(s==-1)root->leftNode=createnode(val);
        else root->rightNode=createnode(val);
        return 1;
    }
    if(root->leftNode)return insertafter(root->leftNode);
    else if(root->rightNode)return insertafter(root->rightNode);
    return 0;
}
void treelen(struct Node *root,int *l)
{
    if(!root)return;
    (*l)++;
    if(root->leftNode)treelen(root->leftNode,l);
    if(root->rightNode)treelen(root->rightNode,l);
}
void pretraverse(struct Node* root)
{
    if(!root)return;
    printf("%d\n",root->data);
    if(root->leftNode)recrtraverse(root->leftNode);
    if(root->rightNode)recrtraverse(root->rightNode);
}
void intraverse(struct Node *root)
{
    if(!root)return;
    if(root->leftNode)recrtraverse(root->leftNode);
    printf("%d\n",root->data);
    if(root->rightNode)recrtraverse(root->rightNode);
}
void posttraverse(struct Node *root)
{
    if(!root)return;
    if(root->leftNode)recrtraverse(root->leftNode);
    if(root->rightNode)recrtraverse(root->rightNode);
    printf("%d\n",root->data);
}
void deltree(struct Node* root)
{
    if(!root)return;
    struct Node* ln=root->leftNode;
    struct Node* rn=root->rightNode;
    free(root);
    deltree(ln);
    deltree(rn);
}