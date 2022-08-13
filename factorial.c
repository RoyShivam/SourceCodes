#include"mylib.c"
//non tail call recursive
int fact(int n)
{
    return n<2?1:n*fact(n-1);
}
//tail call recursive
int factTCR(int n,int a)
{
    return n<2?a:factTCR(n-1,a*n);
}
//tail call elimination
int factTCE(int n)
{
    int a=1;
    start:
    if(n<2)
    return a;
    a*=n;
    n--;
    goto start;
}