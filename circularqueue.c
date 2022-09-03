#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int item[SIZE];
int front=-1, rear=-1;
int isFull()
{
    if((front==rear+1) || (front==0 && rear==SIZE-1)) return 1;
    return 0;
}
int isEmpty()
{
    if(front==-1) return 1;
    return 0;
}

void enQueue(int val)
{
    if (isFull()){
        printf("OVERFLOW");
    }
    else
    {
        if(front==-1)
        front=0;
        rear=(rear+1)% SIZE;
        item[rear]=val;
        printf("Inserted %d\n",val);
    }
}

int dequeue(){
    int element;
    if(isEmpty()){
        printf("UNDERFLOW");
        return -1;
    }
else{
    element=item[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else{
        front=(front+1)%SIZE;
    }
    printf("DELETED ELEMENT %d\n",element);
    return element;
}

}
void display()
{
    int i;
    if(isEmpty())
    {
        printf("EMPTY QUEUE");
    }
    else{
        // printf("front %d\n",front);
        for(i=front;i!=rear;i=(i+1)%SIZE)
        {
            printf("items=%d\n",item[i]);
        }
        // printf("%d",item[i]);
        // printf("rear= %d\n",rear);
    }

}
int main()
{
    enQueue(5);
    enQueue(6);
    enQueue(7);
    enQueue(9);
    enQueue(12);
    display();
    printf("After display: \n");
    dequeue();
    display();
}