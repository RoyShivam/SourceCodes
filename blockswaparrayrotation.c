#include"mylib.c"
void swapsubarray(int *arr,int fi,int si,int k)
{
    for(int i=0;i<k;i++)
    swap(&arr[fi+i],&arr[si+i]);
}
void blockswap(int *arr,int di,int n)
{
    if(di>=n||di<=0)return;
    if(n-di==di)
    {
        swapsubarray(arr,0,n-di,di);
        return;
    }
    if(di<n-di)
    {
        swapsubarray(arr,0,n-di,di);
        blockswap(arr,di,n-di);
    }
    else
    {
        swapsubarray(arr,0,di,n-di);
        blockswap(arr+n-di,2*di-n,di);
    }
}
int main()
{
    int arr[MAX],n=10,di=0;
    genarr(arr,n,30);
    printarrwithindex(arr,n);
    scanf("%d",&di);
    blockswap(arr,di,n);
    printarrwithindex(arr,n);
    return 0;
}