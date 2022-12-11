#include"lib.c"
//searches sequentialy by traversing one by one.
int search(int *arr,int n,int sv)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]==sv)return i;
	}
	return -1;
}
int main()
{
	int n=6;
	int arr[6]={5,9,3,7,6,8};
	int i=search(arr,n,9);
	printarr(arr,n);
	if(i==-1)printf("searching failed!\n");
	else printf("search value index:%d\n",i);
	return 0;
}