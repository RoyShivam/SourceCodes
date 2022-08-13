#include"mylib.c"
int main()
{
    int arr[MAX],n=10,rs=0,ts=0,si=0;
    genarr(arr,n,30);
    printarrwithindex(arr,n);
    scanf("%d",&rs);
    for(int i=0;i<n;i++)
    {
        ts+=arr[i];
        if(ts==rs)
        {
            printf("%d:%d\n",si,i);
            return 0;
        }
        else if(ts>rs)
        {
            int j=si;
            while(j<i)
            {
                ts-=arr[j++];
                if(ts==rs)
                {
                    printf("%d:%d\n",j,i);
                    return 0;
                }
            }
            ts=0;
            si=i+1;
        }
    }
    printf("required subarray for the sum not found!\n");
    return 0;
}