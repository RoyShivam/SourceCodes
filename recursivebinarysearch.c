#include"mylib.c"
void binarysearch(int *arr,int si,int ei,int sv)
{
    if(si>ei)
    {
        printf("Search Value not found!");
        return;
    }
    int mi=(si+ei)/2;
    int arrv=arr[mi];
    if(arrv==sv)
    {
        printf("Search Value found at %d",mi);
        return;
    }
    else if(sv>arrv)si=mi+1;
    else ei=mi-1;
    binarysearch(arr,si,ei,sv);
}
int main()
{
    int arr[MAX],n=10,sv=0;
    gensortarr(arr,n);
    printarrwithindex(arr,n);
    scanf("%d",&sv);
    binarysearch(arr,0,n-1,sv);
    return 0;
}