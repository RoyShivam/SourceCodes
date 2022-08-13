#include"mylib.c"
int main()
{
    int arr[MAX],n=10;int li=n-1;
    gennegarr(arr,n,30);
    printarr(arr,n);
    for(int i=n-1;i>-1;i--)
    {
        if(arr[i]<0)
        {
            int t=arr[i];
            for(int j=i;j<li;j++)
            arr[j]=arr[j+1];
            arr[li]=t;
            li--;
        }
    }
    printarr(arr,n);
    return 0;
}