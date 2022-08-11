#include"mylib.c"
int main()
{
    int arr[MAX],n=10;
    genarr(arr,n,30);
    printarr(arr,n);
    for(int i=0;i<n-1;i++)
    {
        int mi=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[mi])
            mi=j;
        }
        if(mi!=i)swap(&arr[mi],&arr[i]);
    }
    printarr(arr,n);
    return 0;
}