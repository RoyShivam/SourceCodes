#include"mylib.c"
int main()
{
    int arr[MAX],n=10;
    genarr(arr,n,30);
    printarr(arr,n);
    for(int i=0;i<n/2;i++)
    swap(&arr[i],&arr[n-i-1]);
    printarr(arr,n);
    return 0;
}