#include<stdio.h>
int main()
{
	int a=2,b=55,q=0,r=0;
	for(r=b;r>=a;q++)
	r-=a;
	printf("%d:%d\n",q,r);
	return 0;
}