#include<stdio.h>
#include<stdlib.h>
typedef struct __queue_node
{
int num;
struct __queue_node *next;
}QueueNode;
typedef struct __queue
{
QueueNode *start;
QueueNode *end;
}Queue;
void initQueue(Queue *queue)
{
queue->start=NULL;
queue->end=NULL;
}
void add(Queue *queue,int num)
{
QueueNode *node;
node=(QueueNode *)malloc(sizeof(QueueNode));
node->num=num;
node->next=NULL;
if(queue->start==NULL)
{
queue->start=node;
queue->end=node;
}
else
{
queue->end->next=node;
queue->end=node;
}
}
int removeFromQueue(Queue *queue)
{
QueueNode *node;
int num;
node=queue->start;
queue->start=queue->start->next;
num=node->num;
free(node);
return num;
}
int isQueueEmpty(Queue *queue)
{
return queue->start==NULL;
}
int top(Queue *queue)
{
return queue->start->num;
}
int main()
{
Queue queue;
initQueue(&queue);
add(&queue,78);
add(&queue,7812);
add(&queue,7348);
add(&queue,178);
add(&queue,781);
add(&queue,7128);
add(&queue,7);
printf("Top %d\n",top(&queue));
while(!isQueueEmpty(&queue)) printf("%d\n",removeFromQueue(&queue));
return 0;
}