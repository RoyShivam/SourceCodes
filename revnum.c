#include"mylib.c"
int main()
{
    int n=0,rn=0;
    scanf("%d",&n);
    while(n)
    {
        int r=n%10;
        rn=rn*10+r;
        n/=10;
    }
    printf("%d\n",rn);
    return 0;
}