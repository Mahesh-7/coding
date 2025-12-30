#include<iostream>
using namespace std;

typedef struct 
{
    int front;
    int rear;
    int data[5];
}queue_st;

queue_st queue;

void enqueue(int data)
{
    if(queue.rear==4)
    {
        cout<<"queue is full\n";
    }
    else
    {
        queue.rear++;
        queue.data[queue.rear]=data; 
    }
}
void dequeue()
{
    if(queue.front==queue.rear)
    {
        cout<<"queue is empty\n";
    }
    else
    {
        queue.front++; 
    }
}
void display()
{
    for(int i=queue.front;i<=queue.rear;i++)
    {
        cout<<queue.data[i]<<endl;
    }
}

int main()
{
    queue.front=-1;
    queue.rear=-1;
    dequeue();
    enqueue(1);
    enqueue(2);
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(3);
    dequeue();
    display();
    return 0;
}