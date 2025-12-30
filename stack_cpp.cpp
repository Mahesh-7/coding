#include<iostream>
using namespace std;

typedef struct 
{
    int top;
    int data[5];
}stack_st;

stack_st stack;

void push(int data)
{
    if(stack.top==4)
    {
        cout<<"stack is full\n";
    }
    else{
        stack.top++;
        stack.data[stack.top]=data;
    }
}
void pop()
{
    if(stack.top==-1)
    {
        cout<<"stack is empty\n";
    }
    else{
        stack.top--;
    }
}
void display()
{
    for(int i=0;i<=stack.top;i++)
    {
        cout<<stack.data[i]<<endl;
    }
}

int main()
{

    stack.top=-1;
    pop();
    push(1);
    push(2);
    push(3);
    push(3);
    push(3);
    push(1);
    push(2);
    display();
    return 0;
}