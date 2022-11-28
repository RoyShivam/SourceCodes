#include<stdio.h>
//from:A to:C aux:B
void solve(int disks,char from,char to,char aux)
{
	if(disks==1)
	{
		printf("%d moved from %c to %c\n",disks,from,to);
		return;
	}
	//move n-1 disks from:A to:B
	solve(disks-1,from,aux,to);
	//move nth disk from:A to:C
	printf("%d moved from %c to %c\n",disks,from,to);
	//move n-1 disks from:B to:C
	solve(disks-1,aux,to,from);
}
int main()
{
	solve(3,'A','C','B');
	return 0;
}