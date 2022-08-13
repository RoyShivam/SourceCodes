#include"mylib.c"
int binarysearch(int *arr,int si,int ei,int sv)
{
    if(si>ei)
    return -1;
    int mi=(si+ei)/2;
    int arrv=arr[mi];
    if(arrv==sv)
    return mi;
    else if(sv>arrv)si=mi+1;
    else ei=mi-1;
    return binarysearch(arr,si,ei,sv);
}
int small(int n1,int n2,int n3)
{
    return n3<n2&&n3<n1?n3:n1<n2?n1:n2;
}
void printcommonelements(int *arr1,int *arr2,int *arr3,int n1,int n2,int n3)
{
    int i=0;
    while(i<n1)
    {
        int si=binarysearch(arr2,0,n2-1,arr1[i]);
        si=si==-1?-1:binarysearch(arr3,0,n3-1,arr1[i]);
        if(si!=-1)printf("%d\n",arr1[i]);
        i++;
    }
}
int main()
{
    int arr1[MAX]={1,5,10,20,40,80},n1=6;
    int arr2[MAX]={6,7,20,80,100},n2=5;
    int arr3[MAX]={3,4,15,20,30,70,80,120},n3=8;
    int n=small(n1,n2,n3);
    if(n==n1)printcommonelements(arr1,arr2,arr3,n1,n2,n3);
    else if(n==n2)printcommonelements(arr2,arr1,arr3,n2,n1,n3);
    else printcommonelements(arr3,arr1,arr2,n3,n1,n2);
    return 0;
}