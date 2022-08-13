#include"mylib.c"
int main()
{
    int arr[MAX],n=10;
    genarr(arr,n,30);
    printarrwithindex(arr,n);
    for(int i=1;i<n-1;i++)
    {
        if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])
        {
            printf("peak element index:%d\n",i);
            return 0;
        }
    }
    printf("peak element index:%d\n",0);
    return 0;
}