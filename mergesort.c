#include"mylib.c"
void merge(int *arr,int si,int ei,int mi)
{
    int l1=mi+1-si;
    int l2=ei-mi;
    int typesize=sizeof(int);
    int *arr1=malloc(l1*typesize);
    for(int l=0;l<l1;l++)arr1[l]=arr[l+si];
    int *arr2=malloc(l2*typesize);
    for(int l=0;l<l2;l++)arr2[l]=arr[l+mi+1];
    int i=0,j=0,k=si;
    while(i<l1&&j<l2)
    {
        if(arr1[i]<arr2[j])
        arr[k++]=arr1[i++];
        else arr[k++]=arr2[j++];
    }
    for(;i<l1;i++)arr[k++]=arr1[i];
    for(;j<l2;j++)arr[k++]=arr2[j];
    free(arr1);
    free(arr2);
}
void mergesort(int *arr,int si,int ei)
{
    if(si==ei)return;
    int mi=(si+ei)/2;
    mergesort(arr,si,mi);
    mergesort(arr,mi+1,ei);
    merge(arr,si,ei,mi);
}
int main()
{
    int arr[MAX],n=10;
    genarr(arr,n,30);
    printarr(arr,n);
    mergesort(arr,0,n-1);
    printarr(arr,n);
    return 0;
}