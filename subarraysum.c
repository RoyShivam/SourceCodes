#include"lib.c"
int findsubarr(int *arr,int n,int sum,int *s,int *e)
{
	if(sum==0)return 0;
	int rsum=0,i=0,j=0;
	while(i<n&&j<n)
	{
		if(rsum<sum)
		{
			rsum+=arr[j];
			j++;
			if(rsum==sum)
			{
				*s=i+1;*e=j;
				return 1; 
			}
		}
		else
		{
			rsum-=arr[i];
			i++;
			if(rsum==sum)
			{
				*s=i+1;*e=j;
				return 1; 
			}
		}
	}
	return 0;
}
int main()
{
	int n=5,arr[5]={1,2,3,7,5},sum=12,s=0,e=0;
	int flag=findsubarr(arr,n,sum,&s,&e);
	if(flag)printf("%d:%d\n",s,e);
	else printf("not found!\n");
	return 0;
}