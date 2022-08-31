#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct ArrayQueue
{
    int front,rear;
    int capacity;
    int *array;
};

struct ArrayQueue* CreateQueue(int capacity)
{
    struct ArrayQueue *Q=malloc(sizeof(struct ArrayQueue));
    if(!Q) return (NULL);
    Q->capacity=capacity;
    Q->front=Q->rear=-1;
    Q->array=malloc(Q->capacity*sizeof(int));
    if(!Q->array)
        return(NULL);
    else
        return Q;
}
int isEmpty(struct ArrayQueue *Q)
{
    if(Q->front==-1)
        return(1);
    else
        return (0);
}
int isFull(struct ArrayQueue *Q)
{
    return ((Q->rear+1)%Q->capacity==Q->front);
}
int QueueSize(struct ArrayQueue *Q)
{
    return ((Q->capacity-Q->front+Q->rear+1)%Q->capacity);
}
void enQueue(struct ArrayQueue *Q,int data)
{
    if(isFull(Q))
    {
        printf("OVERFLOW\n");
        getch();
    }
    else
    {
        Q->rear=(Q->rear+1)%Q->capacity;
        Q->array[Q->rear]=data;
        if(Q->front==-1)
            Q->front=Q->rear;
    }
}
int deQueue(struct ArrayQueue *Q)
{
    int data=-1;
    if(isEmpty(Q))
      {
        printf("Queue is Empty\n");
        return(-1);
      }
    else
    {
        data=Q->array[Q->front];
        if(Q->front==Q->rear)
            Q->front=Q->rear=-1;
        else
            Q->front=(Q->front+1)%Q->capacity;
    }
    return (data);
}
void deleteQueue(struct ArrayQueue *Q)
{
    if(Q)
    {
        if(Q->array)
        {
            free(Q->array);
        }
        free(Q);
    }
}
int main()
{
    struct ArrayQueue *Q;
    int data,capacity,a,b,c;
    printf("Select the lenth of the queue:");
    scanf("%d",&capacity);
    Q=CreateQueue(capacity);
    system("cls");
    while(1)
    {
    printf("1.add value to the queue\n");
    printf("2.remove value from the queue\n");
    printf("3.Show queue size\n");
    printf("4.delete Queue\n");
    printf("5.Exit\n");
    printf("ENTER CHOICE:");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        {
        printf("enter the number you want to insert in queue:");
        scanf("%d",&data);
        enQueue(Q,data);break;
        }
    case 2:{
        b=deQueue(Q);
        printf("%d",b);
        getch();break;
    }
    case 3:{
        c=QueueSize(Q);
        printf("%d",c);
        getch();break;
    }
    case 4:{
        deleteQueue(Q);
        printf("Your Queue is deleted :)\n");
        getch();break;
    }
    case 5:
        exit(0);break;
    default:
        printf("Invalid Input");
        getch();break;
    }
    system("cls");
    }
}
