#include"mylib.c"
int main()
{
	int arr[MAX],n=10,sv=0;
	genarr(arr,n,MAX);
	printarrwithindex(arr,n);
	scanf("%d",&sv);
	for(int i=0;i<n;i++)
	{
		if(arr[i]==sv)
		{
			printf("Search Value found at index: %d",i);
			return 0;
		}
	}
	printf("Search Value not found!");
	return 0;
}
