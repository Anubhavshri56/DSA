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

typedef struct __stack_node
{
int num;
struct __stack_node *next;
}StackNode;
typedef struct __stack
{
StackNode *start;
StackNode *end;
}Stack;
void initStack(Stack *stack)
{
stack->start=NULL;
stack->end=NULL;
}
void push(Stack *stack,int num)
{
StackNode *node;
node=(StackNode *)malloc(sizeof(StackNode));
node->num=num;
node->next=NULL;
if(stack->start==NULL)
{
stack->start=node;
stack->end=node;
}
else
{
node->next=stack->start;
stack->start=node;
}
}
int pop(Stack *stack)
{
StackNode *node;
int num;
node=stack->start;
stack->start=stack->start->next;
num=node->num;
free(node);
return num;
}
int isStackEmpty(Stack *stack)
{
return stack->start==NULL;
}
int stackTop(Stack *stack)
{
return stack->start->num;
}

int main()
{
int posLar,negLar,dc,e,f,g,i,j,h,negIndex;
Queue queue[10];
for(e=0;e<10;e++) initQueue(&queue[e]);
Stack stack[10];
for(e=0;e<10;e++) initStack(&stack[e]);
int arr[10];
for(e=0;e<10;e++)
{
printf("Enter a Number : ");
scanf("%d",&arr[e]);
}
for(posLar=arr[0],e=1;e<10;e++) if(arr[e]>posLar) posLar=arr[e];
for(e=0,negIndex=0;e<10;e++)
{
if(arr[e]<0)
{
g=arr[e];
arr[e]=arr[negIndex];
arr[negIndex]=g;
arr[negIndex]=arr[negIndex]*(-1);
negIndex++;
}
}
for(negLar=arr[0],e=1;e<negIndex;e++) if(arr[e]>negLar) negLar=arr[e];
dc=1;
while(posLar>9)
{
dc++;
posLar=posLar/10;
}
for(i=0,e=1,f=10;i<dc;i++)
{
for(g=negIndex;g<10;g++)
{
j=(arr[g]%f)/e;
add(&queue[j],arr[g]);
}
for(g=0,h=negIndex;g<10;g++)
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
if(negIndex>0)
{
dc=1;
while(negLar>9)
{
dc++;
negLar=negLar/10;
}
for(i=0,e=1,f=10;i<dc;i++)
{
for(g=negIndex-1;g>=0;g--)
{
j=(arr[g]%f)/e;
push(&stack[j],arr[g]);
}
for(g=9,h=0;g>=0;g--)
{
while(!isStackEmpty(&stack[g]))
{
arr[h]=stackTop(&stack[g]);
pop(&stack[g]);
h++;
}
}
e=e*10;
f=f*10;
}
}
for(e=0;e<negIndex;e++) arr[e]=arr[e]*(-1);
for(e=0;e<10;e++) printf("%d\n",arr[e]);
return 0;
}