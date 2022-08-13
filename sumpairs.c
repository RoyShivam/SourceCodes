#include"mylib.c"
int main()
{
    int arr[MAX],n=10,rs=0,sp=0;
    genarr(arr,n,30);
    printarr(arr,n);
    scanf("%d",&rs);
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==rs)
            sp++;
        }
    }
    printf("sum pairs:%d\n",sp);
    return 0;
}