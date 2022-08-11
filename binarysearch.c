#include"mylib.c"
int main()
{
    int arr[MAX],n=10,sv=0,si=0,ei=n;
    gensortarr(arr,n);
    printarrwithindex(arr,n);
    scanf("%d",&sv);
    while(si<=ei)
    {
        int mi=(si+ei)/2;
        int arrv=arr[mi];
        if(arrv==sv)
        {
            printf("Search Value found at %d",mi);
            return 0;
        }
        else if(sv>arrv)si=mi+1;
        else ei=mi-1;
    }
    printf("Search Value not found!");
    return 0;
}