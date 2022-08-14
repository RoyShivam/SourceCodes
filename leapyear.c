#include"mylib.c"
int leapyear(const int y)
{
    if(y%4==0)
    {
        if(y%100==0)
        {
            if(y%400==0)return 1;
        }
        else return 1;
    }
    return 0;
}
int main()
{
    int y=0;
    scanf("%d",&y);
    printf("%s",leapyear(y)?"leap year":"non leap year");
    return 0;
}