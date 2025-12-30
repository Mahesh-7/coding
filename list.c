#include<stdio.h>
#include<stdlib.h>

//1->2->3
//1->2 or 2->3

typedef struct node
{
    int data;
    struct node * next;
}node_t;

node_t * head = NULL;

void insert(int data)
{
    node_t * newNode = malloc (sizeof(node_t));
    newNode ->data = data;
    newNode -> next = NULL;
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        node_t * temp = head;
        while( temp->next != NULL)
        {
            temp = temp -> next;
        }
        
        temp->next = newNode ;
    }

}

void delete()
{
    //1->2->3
    node_t * temp = head;
    node_t * prev = NULL;
    if( temp-> next == NULL)
    {
        head = NULL;
        free(temp);
    }
    else
    {
        while (temp-> next != NULL)
        {
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = NULL;
        free(temp);
    } 
}
void display()
{
    node_t * temp = head;
    while( temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    display();
    delete();
    display();
    return 0;
}