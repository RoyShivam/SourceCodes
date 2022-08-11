#include"mylib.c"
struct stack
{
    int capacity;
    int top;
    int *arr;
    int isfull,isempty;
};
struct stack* createstack(int capacity)
{
    struct stack* s=malloc(sizeof(struct stack));
    s->capacity=capacity;
    s->arr=malloc(sizeof(int)*capacity);
    s->top=-1;
    s->isempty=1;
    s->isfull=0;
    return s;
}
void push(struct stack *s,int val)
{
    if(s->isfull)
    {
        printf("stack overflow might occur!\n");
        return;
    }
    s->top++;
    s->arr[s->top]=val;
    s->isfull=s->top==s->capacity-1;
    s->isempty=0;
}
int pop(struct stack *s)
{
    if(s->isempty)
    {
        printf("stack underflow might occur!\n");
        return INT_MIN;
    }
    int val=s->arr[s->top--];
    s->isfull=0;
    s->isempty=s->top==-1;
    return val;
}
void displaystackstatus(struct stack *s)
{
    printf("top:%d\n",s->top);
    printf("capacity:%d\n",s->capacity);
    printf("isempty?%s\n",s->isempty?"True":"False");
    printf("isfull?%s\n",s->isfull?"True":"False");
    for(int i=0;i<s->top+1;i++)
    printf("%d\n",s->arr[i]);
}
int main()
{
    struct stack *s=NULL;
    while(1)
    {
        char c=' ';int val=0;
        printf("Create a New Stack with key:'C'\n");
        if(s!=NULL)
        {
            printf("Push a value into stack with key:'A'\n");
            printf("Pop a value from stack with key:'P'\n");
            printf("Display Stack Status with key:'D'\n");
        }
        printf("Press any other key to quit.\n");
        printf("Enter you choice:");
        c=getch();
        printf("%c",c);getch();
        system("cls");
        switch(c)
        {
            case 'C':case 'c':
            if(s!=NULL)free(s);
            printf("Enter the capacity:");
            scanf("%d",&val);
            s=createstack(val);
            break;
            case 'A':case 'a':
            printf("Enter a value to push:");
            scanf("%d",&val);
            push(s,val);
            getch();
            break;
            case 'P':case 'p':
            int val=pop(s);
            if(val!=INT_MIN)printf("Popped Value is:%d\n",val);
            getch();
            break;
            case 'D':case 'd':
            displaystackstatus(s);
            getch();
            break;
            default:
            if(s!=NULL)free(s);
            system("cls");
            return 0;
        }
        system("cls");
    }
}