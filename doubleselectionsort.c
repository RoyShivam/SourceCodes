#include"mylib.c"
int main()
{
    int arr[MAX],n=10;
    genarr(arr,n,30);
    printarr(arr,n);
    for(int i=0;i<n-i-1;i++)
    {
        int mi=i;
        int hi=n-i-1;
        if(arr[hi]<arr[mi])swap(&arr[mi],&arr[hi]);
        for(int j=i+1;j<n-i-1;j++)
        {
            if(arr[j]<arr[mi])mi=j;
            else if(arr[j]>arr[hi])hi=j;
        }
        if(mi!=i)swap(&arr[mi],&arr[i]);
        if(hi!=n-i-1)swap(&arr[hi],&arr[n-i-1]);
    }
    printarr(arr,n);
    return 0;
}