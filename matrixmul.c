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
    int r1,c1,r2,c2;
    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
    if(c1!=r2)
    {
        printf("Multiplication not possible!\n");
        return 0;
    }
    struct mat *m3=createmat(r1,c2);
    struct mat *m1=createmat(r1,c1);
    genmatarr(m1->arr,r1,c1,30);
    printmatarr(m1->arr,r1,c1);
    struct mat *m2=createmat(r2,c2);
    genmatarr(m2->arr,r2,c2,30);
    printmatarr(m2->arr,r2,c2);
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            int s=0;
            for(int k=0;k<c1;k++)
            s+=getmatval(m1->arr,i,k,c1) * getmatval(m2->arr,k,j,c2);
            setmatval(m3->arr,i,j,c2,s);
        }
    }
    printmatarr(m3->arr,r1,c2);
    free(m1);
    free(m2);
    free(m3);
    return 0;
}