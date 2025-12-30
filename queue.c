#include <stdio.h>
typedef struct queue_st
{
	int data;
	struct queue_st * ptr;
}queue_t;
