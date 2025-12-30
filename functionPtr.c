#include <stdio.h>

typedef void (*TaskFunction_t)(void *);

void xTaskCreate( TaskFunction_t TaskFunction , void * parameter)
{
	TaskFunction(parameter);
}

void task1(void * parameter)
{
	printf("hello world %s\r\n",(char*)parameter);
}

int main()
{
	xTaskCreate(task1,"execute task1\r\n");
	return 0;
}
