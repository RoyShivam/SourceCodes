//Newton-Raphson Method for finding root of an equation
#include<stdio.h>
float f(float x)
{
	return 4*x+3;
}
float df(float x)
{
	return 4;
}
int findroot(float x,float *r,float e,int ic)
{
	int i=0;
	while(i<ic)
	{
		if(f(x)<e)
		{
			*r=x;
			return 1;
		}
		x=x-f(x)/df(x);
		ic++;
	}
	return 0;
}
int main()
{
	float x0=0,r=0,e=0.2;int ic=10;
	int flag=findroot(x0,&r,e,ic);
	if(flag)printf("root:%f\n",r);
	else printf("root not found or iteration count not sufficient!\n");
	return 0;
}