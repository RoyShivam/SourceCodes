#include"mylib.c"
int main()
{
    int arr[MAX],n=10;
    genarr(arr,n,30);
    printarr(arr,n);
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            swap(&arr[j],&arr[j+1]);
        }
    }
    printarr(arr,n);
    return 0;
}