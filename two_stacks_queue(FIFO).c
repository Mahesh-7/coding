#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int top;
    int size;
    int cap;
}stack_t;

typedef struct
{
    stack_t *s1;
    stack_t *s2;
}queue_t;

queue_t queue;

void push(int data,stack_t *s)
{
    if(s->top == s->cap -1)
    {
        printf("stack overflow\n");
    }
    else
    {
        s->data[++s->top] = data;
        //printf("push:%d ",s->data[s->top]);
    }
}

int pop(stack_t *s)
{
    if(s->top == -1)
    {
        printf("stack underflow\n");
        return -1;
    }
    //else
    {
        int ret = s->data[s->top--];
        //printf("pop:%d ",data[s->top]);
        return ret;
    }
}

void initQueue()
{
    printf("init started\n");
    queue.s1 = malloc(sizeof(stack_t));
    queue.s2 = malloc(sizeof(stack_t));
    queue.s1->top = -1;
    queue.s2->top = -1;
    queue.s1->data = malloc(4 * sizeof(int));
    queue.s2->data = malloc(4 * sizeof(int));
    queue.s1->size = 0;
    queue.s2->size = 0;
    queue.s1->cap = 4;
    queue.s2->cap = 4;
    printf("init done\n");
}

void enqueue(int data)
{
    if(queue.s1->top == queue.s1->cap-1)
    {
        //if(queue.s1->size == queue.s1->cap)
        {
            queue.s1->cap *= 2;
            queue.s1->data = realloc(queue.s1->data,queue.s1->cap * sizeof(int));
        }

    }
    push(data,queue.s1);
    queue.s1->size++;
}

int dequeue()
{
    if(queue.s2->top == -1)
    {
        while(queue.s1->top != -1)
        {
            if(queue.s2->top == queue.s2->cap-1)
            {
                queue.s2->cap *= 2;
                queue.s2->data = realloc(queue.s2->data ,queue.s2->cap * sizeof(int));
            }
            push(pop(queue.s1),queue.s2);
            queue.s1->size--;
            queue.s2->size++;
        }
    }
    int ret = pop(queue.s2);
    queue.s2->size--;
    return ret;
}

void display()
{
    int loop;
    if(queue.s2->top == -1)
    {
        while(queue.s1->top != -1)
        {
            if(queue.s2->top == queue.s2->cap-1)
            {
                queue.s2->cap *= 2;
                queue.s2->data = realloc(queue.s2->data ,queue.s2->cap * sizeof(int));
            }
            int val = pop(queue.s1);
            queue.s1->size--;
            push(val, queue.s2);
            queue.s2->size++;
        }
    }
    for(loop=queue.s2->top;loop>=0;loop--)
    {
        printf("avl:%d ",queue.s2->data[loop]);
    }
    printf("\n");
}

int main()
{
    initQueue(); 
    enqueue(1);
    enqueue(2);
    dequeue();
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    //dequeue();
    display();

    return 0;
}