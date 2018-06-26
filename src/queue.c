//Copyright (c) 2018 Sharon Lon <sharon_lon@163.com>

#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>


#define FALSE	0
#define TRUE	(!FALSE)

typedef struct __queue
{
	int node_size;
	void* queue_head;
	int head;
	int tail;
	int queue_size;
}queue_t;

queue_t* InitQueue(queue_t* queue,int node_size,int queue_length)  
{  
	if ((NULL == queue) || (0 == node_size) || (0 == queue_length))
		return NULL;
	
	void* queue_head = NULL;
	queue_head = (void*)malloc(node_size * (queue_length+1));  
	if (NULL == queue_head)
	{
		return NULL;
	}
	
	queue->queue_size = (queue_length+1)*node_size;
	queue->queue_head = queue_head;
	queue->head = queue->queue_size;
	queue->tail = 0;
	queue->node_size = node_size;
		
	return queue;
}  
  

int QueueIsEmpty(queue_t* queue)  
{  
	if (NULL == queue)
		return FALSE;

    return (queue->head % queue->queue_size) == queue->tail;  
}  

int QueueIsFull(queue_t* queue)  
{  
	if (NULL == queue)
		return FALSE;

    return (queue->tail + queue->node_size)%(queue->queue_size) == queue->head % (queue->queue_size);  
}  

int ClearQueue(queue_t* queue)  
{  
	if ((NULL == queue) || (queue->queue_head))
		return FALSE;
	free(queue->queue_head);
	queue->queue_head = NULL;

    return TRUE;  
} 

int Enqueue(queue_t* queue,void * node)  
{  
	if ((NULL == queue) || (NULL == node))
		return FALSE;

    if (QueueIsFull(queue))  
    {  
        return FALSE;  
    }  

	memcpy(queue->queue_head+queue->tail,node,queue->node_size);
	queue->tail += queue->node_size;	
    queue->tail %= queue->queue_size;  
	return TRUE;
}  

void* Dequeue(queue_t*queue)  
{  	
	if (NULL == queue)
		return FALSE;
	
    if (QueueIsEmpty(queue))  
    {  
        return NULL;  
    }  
	
	void * ptr = NULL;
    queue->head %= queue->queue_size;  
	ptr = queue->queue_head+queue->head;
	queue->head += queue->node_size;

	return ptr;
}  

