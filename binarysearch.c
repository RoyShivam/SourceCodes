#include"lib.c"
//iterative
int iter_search(int *arr,int s,int e,int sv)
{
	while(s<=e)
	{
		int m=(s+e)/2;
		if(sv==arr[m])return m;
		else if(sv>arr[m])s=m+1;
		else e=m-1;
	}
	return -1;
}
<<<<<<< Updated upstream
=======
<<<<<<< HEAD
int recur_search(int *arr,int s,int e,int sv)
{
	if(s>e)return -1;
	return -1;
}
=======
>>>>>>> Stashed changes
//recursive
int recur_search(int *arr,int s,int e,int sv)
{
	if(s>e)return -1;
	int m=(s+e)/2;
	if(sv==arr[m])return m;
	else if(sv>arr[m])return recur_search(arr,m+1,e,sv);
	else return recur_search(arr,s,m-1,sv);
}
//searches the middle element within a sorted list.
<<<<<<< Updated upstream
=======
>>>>>>> 517248f9c574e8c7bd0fccfcf970ca0c4e88c147
>>>>>>> Stashed changes
int main()
{
	int n=6;
	int arr[6]={3,5,6,7,8,9};
	printarr(arr,n);
	int i=recur_search(arr,0,n-1,6);//iter_search(arr,0,n-1,9);
	if(i==-1)printf("searching failed!\n");
	else printf("search value index:%d\n",i);
	return 0;
}