#include"mylib.c"
/*probability that among n persons atleast 2 persons have the same birthdays.
let p(same) be the probability that atleast 2 persons have the same birthdays.
therefore p(diff) is the probability that all n persons have different birthdays.
therefore p(same)=1-p(diff)
therefore p(diff)=1*(364/365)*(363/365)*...*[{365-(n-1)}/365]
therefor for e^x~1+x then e^-(n-1)/365~e^-n*(n-1)/(2*365)*/
double sameprob(double n)
{
    double pd=exp((-n*(n-1))/730);
    double ps=1-pd;
}
int perlen(double ps)
{
    double pd=1-ps;
    double k=log(pd)*730;
    double d=sqrt(1-4*k);
    int n=ceil((1+d)/2);
    return n;
}