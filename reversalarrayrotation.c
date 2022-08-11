#include"mylib.c"
int main()
{
    int arr[MAX],n=10,d=0;
    genarr(arr,n,30);
    printarrwithindex(arr,n);
    scanf("%d",&d);
    for(int j=0;j<d;j++)
    {
        int t=arr[0];
        for(int i=0;i<n-1;i++)
        arr[i]=arr[i+1];
        arr[n-1]=t;
    }
    printarr(arr,n);
    return 0;
}