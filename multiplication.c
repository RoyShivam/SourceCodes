#include<stdio.h>
int main()
{
	int a=2,b=10,r=0;
	int i=a>b?a:b;
	int n=a>b?b:a;
	for(int j=1;j<=n;j++)
		r+=i;
	printf("%d\n",r);
	return 0;
}