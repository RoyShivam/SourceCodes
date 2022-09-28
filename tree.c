#include"mylib.c"
struct node
{
    int data;
    struct node *leftnode,*rightnode;
};
struct node* createnode(int val)
{
    struct node* t=malloc(sizeof(struct node));
    t->data=val;
    t->leftnode=t->rightnode=NULL;
    return t;
}
int insertafter(struct node *root,int valaft,short int s,int val)
{
    if(!root)return 0;
    if(root->data==valaft)
    {
        if(s==-1)root->leftnode=createnode(val);
        else root->rightnode=createnode(val);
        return 1;
    }
    if(root->leftnode&&insertafter(root->leftnode,valaft,s,val))return 1;
    if(root->rightnode)return insertafter(root->rightnode,valaft,s,val);
    return 0;
}
void treelen(struct node *root,int *l)
{
    if(!root)return;
    (*l)++;
    if(root->leftnode)treelen(root->leftnode,l);
    if(root->rightnode)treelen(root->rightnode,l);
}
void pretraverse(struct node* root)
{
    if(!root)return;
    printf("%d\n",root->data);
    if(root->leftnode)pretraverse(root->leftnode);
    if(root->rightnode)pretraverse(root->rightnode);
}
void intraverse(struct node *root)
{
    if(!root)return;
    if(root->leftnode)intraverse(root->leftnode);
    printf("%d\n",root->data);
    if(root->rightnode)intraverse(root->rightnode);
}
void posttraverse(struct node *root)
{
    if(!root)return;
    if(root->leftnode)posttraverse(root->leftnode);
    if(root->rightnode)posttraverse(root->rightnode);
    printf("%d\n",root->data);
}
void prettyprint(struct node *root,int level)
{
    if(!root)return;
    printf("Level-%d:%d->",level,root->data);
    if(root->leftnode)printf("%d,",root->leftnode->data);
    if(root->rightnode)printf("%d\n",root->rightnode->data);
    if(root->leftnode->leftnode||root->leftnode->rightnode)prettyprint(root->leftnode,level+1);
    if(root->rightnode->leftnode||root->rightnode->rightnode)prettyprint(root->rightnode,level+1);
}
void deltree(struct node* root)
{
    if(!root)return;
    deltree(root->leftnode);
    deltree(root->rightnode);
    free(root);
}
int main()
{
    struct node* tree=createnode(1);
    insertafter(tree,1,-1,2);
    insertafter(tree,1,1,3);
    insertafter(tree,2,-1,4);
    insertafter(tree,2,1,5);
    insertafter(tree,3,-1,6);
    insertafter(tree,3,1,7);
    intraverse(tree);
    deltree(tree);
    return 0;
}