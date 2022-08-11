#include"mylib.c"
int partindex(int *arr,int si,int ei)
{
    int i=si-1;
    for(int j=si;j<ei;j++)
    {
        if(arr[j]<arr[ei])
        {
            i++;swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[ei]);
    return i+1;
}
void quicksort(int *arr,int si,int ei)
{
    if(si>ei)return;
    int pi=partindex(arr,si,ei);
    quicksort(arr,si,pi-1);
    quicksort(arr,pi+1,ei);
}
int main()
{
    int arr[MAX],n=10;
    genarr(arr,n,30);
    printarr(arr,n);
    quicksort(arr,0,n-1);
    printarr(arr,n);
    return 0;
}