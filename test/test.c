#include<stdio.h>  
#include <stdlib.h>  
#include <string.h>
#include "queue.h"

#define maxN  10 //FIFO size  


const char tab[] = "hello world!";

#define ARRAY_SIZE(a)	sizeof(a)/sizeof(a[0])

int main(int argc,char* argv[])  
{

	int x = 0;
	int ret = 0;
	
	queue_t* queue = NULL;
	queue = (queue_t*)malloc(sizeof(queue_t));
	if (NULL == queue)
		return -1;
	
    InitQueue(queue,4,maxN);  
	
	int i = 0;
	printf("enqueue:\n");
    for (i = 0; i <= 5; i++)  
    {  
		x = i+11;
        ret = Enqueue(queue,(void*)&x);  
		if (ret == -1)
		{
			printf("queue is full\n");
			break;
		}
		printf("%d ",x);
    }  
	
	void*iptr;
	printf("\ndequeue:\n");  
    for (i = 0; i < 2; i++)  
    {  
		iptr = Dequeue(queue);
		if (NULL == iptr)
		{
			break;
		}
        printf("%d ",*(int*)iptr);  
    }  
	printf("\nenqueue again:\n");
	for (i = 0; i <= 5; i++)  
    {  
		x = i+20;
        ret = Enqueue(queue,(void*)&x);  
		if (ret == -1)
			{
			printf("queue is full\n");
			break;
		}
		printf("%d ",x);
    }  
	printf("\ndequeue again:\n");  
	for (i = 0; i < 20; i++)  
    {  
		iptr = Dequeue(queue);
		if (NULL == iptr)
		{	
			break;
		}
		
        printf("%d ",*(int*)iptr);  
    }  

	

	ClearQueue(queue);
	 
    InitQueue(queue,1,100);  
	printf("\n\nClearQueue and init again,chang data type from int to char.you can use struct or union\n"); 
	printf("inqueue:\n");  
    for (i = 0; i < ARRAY_SIZE(tab); i++)  
    {  
        Enqueue(queue,(void*)&tab[i]);  
		printf("%c", tab[i]);
    }  
    printf("\ndequeue:\n");  

    for (i = 0; i < ARRAY_SIZE(tab)+7; i++)  
    {  
		iptr = Dequeue(queue);
		if (NULL == iptr)
			break;
		
        printf("%c", *(char*)iptr);  
    }  
	printf("\n");

    return 0;  
}  
