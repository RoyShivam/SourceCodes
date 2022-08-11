#include"mylib.c"
int main()
{
    int arr[MAX],n=10;
    genarr(arr,n,30);
    printarr(arr,n);
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        while(j>0)
        {
            if(arr[j]<arr[j-1])
            swap(&arr[j],&arr[j-1]);
            j--;
        }   
    }
    printarr(arr,n);
    return 0;
}