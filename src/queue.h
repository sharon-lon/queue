#ifndef QUEUE_H
#define QUEUE_H

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

queue_t* InitQueue(queue_t* queue,int node_size,int queue_length);  
  
int QueueIsEmpty(queue_t* queue);  
  
int QueueIsFull(queue_t* queue);  
  
int ClearQueue(queue_t* queue);
 
int Enqueue(queue_t* queue,void * node);
  
void* Dequeue(queue_t*queue); 
 


#endif


