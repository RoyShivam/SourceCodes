#include"mylib.c"
void ndecimalconversion(int n,int nd,int *cn)
{
    int i=0;
    while(n)
    {
        int r=n%nd;
        *cn+=r*pow(10,i);
        n/=nd;i++;
    }
}