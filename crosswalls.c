#include"mylib.c"
int main()
{
    int heights[MAX],n=10,x=10,y=1,tj=0;
    genarr(heights,n,12);
    printarr(heights,n);
    for(int i=0;i<n;i++)
    {
        int th=heights[i],ch=0;
        while(1)
        {
            ch+=x;
            tj++;
            if(ch>=th)break;
            ch-=y;
        }
    }
    printf("jumps required:%d\n",tj);
    return 0;
}