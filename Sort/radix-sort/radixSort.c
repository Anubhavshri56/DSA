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
int lar,dc,e,f,g,i,j,h;
Queue queue[10];
for(e=0;e<10;e++) initQueue(&queue[e]);
int arr[10];
for(e=0;e<10;e++)
{
printf("Enter a Number : ");
scanf("%d",&arr[e]);
}
for(lar=arr[0],e=1;e<10;e++) if(arr[e]>lar) lar=arr[e];
dc=1;
while(lar>9)
{
dc++;
lar=lar/10;
}
for(i=0,e=1,f=10;i<dc;i++)
{
for(g=0;g<10;g++)
{
j=(arr[g]%f)/e;
add(&queue[j],arr[g]);
}
for(g=0,h=0;g<10;g++)
{
while(!isQueueEmpty(&queue[g]))
{
arr[h]=top(&queue[g]);
removeFromQueue(&queue[g]);
h++;
}
}
e=e*10;
f=f*10;
}

for(e=0;e<10;e++) printf("%d\n",arr[e]);
return 0;
}