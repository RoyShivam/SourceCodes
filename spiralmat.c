#include"mylib.c"
struct mat
{
    int *arr;
    int r,c;
};
struct mat* createmat(int r,int c)
{
    struct mat *m=malloc(sizeof(struct mat));
    m->arr=malloc(sizeof(int)*r*c);
    m->r=r;
    m->c=c;
    return m;
}
int main()
{
    int r=4,c=5;
    scanf("%d%d",&r,&c);
    int tr=r,tc=c;
    struct mat *m=createmat(r,c);
    genmatarr(m->arr,r,c,30);
    printmatarr(m->arr,r,c);
    int i=0,j=0;
    while(i<tr&&j<tc)
    {
        for(int k=j;k<tc;k++)
        printf("%d->",getmatval(m->arr,i,k,c));
        i++;
        for(int k=i;k<tr;k++)
        printf("%d->",getmatval(m->arr,k,tc-1,c));
        tc--;
        for(int k=tc-1;k>=j;k--)
        printf("%d->",getmatval(m->arr,tr-1,k,c));
        tr--;
        for(int k=tr-1;k>=i;k--)
        printf("%d->",getmatval(m->arr,k,j,c));
        j++;
    }
    return 0;
}