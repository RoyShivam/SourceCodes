#include"postfixconversion.c"
int isbrace_1(char c)
{
    switch(c)
    {
        case ')':return 1;
        case '(':return 2;
        default:return 0;
    }
}
void prefixconversion(char *infstr,char *prefstr,int opprec(char),int isbrace(char))
{
    int l=len(infstr);
    revstr(infstr,l+1);
    l=postfixconversion(infstr,prefstr,opprec,isbrace);
    revstr(prefstr,l+1);
}