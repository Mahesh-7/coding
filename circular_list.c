#include<stdio.h>
#include<stdlib.h>
//1->2->3
//1<-2<-3
//1->2 or 2->3
//1<-2 or 2<-3
typedef struct node
{
    int data;
    struct node * prev;
    struct node * next;
}node_t;

node_t * head = NULL;

void insert_back(int data)
{
    node_t * newNode = malloc (sizeof(node_t));
    newNode ->data = data;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    if(head == NULL)
    {
        head = newNode;
        newNode -> prev = head;
        newNode -> next = head;
        
    }
    else
    {
        node_t * last = head->prev;
        last->next = newNode ;
        newNode -> prev = last;
        newNode -> next = head;
        head ->prev = newNode;
        
    }
}

void delete_back()
{
    //1->2->3
    
    if(head == NULL) return;

    if( head-> next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node_t *last = head -> prev;
        node_t *secondLast = last->prev;
        secondLast->next = head;
        head -> prev = secondLast;
        free(last);
    } 
}
void display_fwd()
{
    node_t * temp = head;
    if(temp == NULL) return;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }while( temp != head);
    printf("\n");
}

void insert_front(int data)
{
    node_t * newNode = malloc (sizeof(node_t));
    newNode ->data = data;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    if(head == NULL)
    {
        head = newNode;
        newNode -> prev = head;
        newNode -> next = head;
        
    }
    else
    {
        // //   3 (head) <- 2 <- 1
        // node_t * last = head ->prev;
        // last->next = newNode ;
        // newNode -> prev = last;
        // newNode -> next = head;
        // head ->prev = newNode;

        // head = newNode;

        node_t * first = head; // 2 (head) <- 1
        node_t * last = head -> prev;
        first -> prev = newNode;

        newNode -> next = first;
        newNode -> prev = last;

        head = newNode;
        
    }
}

void delete_front()
{
   //   3 (head) <- 2 <- 1
    
    if(head == NULL) return;

    if( head-> next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node_t * first = head;
        node_t *second = head->next;
        node_t *last = head->prev;

        second->prev = last;
        last -> next = second;

        head = second;

        free(first);


    } 
}
void display_rev()
{
    node_t * temp = head;
    if(temp == NULL) return;
    do
    {
        temp = temp->prev;
        printf("%d ", temp->data);
    }while( temp != head);
    printf("\n");
}


int main()
{
    ///Forward
    // insert_back(1);
    // insert_back(2);
    // insert_back(3);
    // display_fwd();
    // delete_back();
    // display_fwd();


    /// Reverse
    insert_front(1);
    insert_front(2);
    insert_front(3);
    display_rev();
    delete_front();
    display_rev();
    return 0;
}