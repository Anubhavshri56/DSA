#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _stack_node
{
void *data;
struct _stack_node *next;
}StackNode;
typedef struct _stack
{
StackNode *top;
int size;
int elementSize;
}Stack;
void initStack(Stack *stack,int elementSize)
{
stack->top=NULL;
stack->size=0;
stack->elementSize=elementSize;
}
void push(Stack *stack,const void *data)
{
StackNode *node;
node=(StackNode *)malloc(sizeof(StackNode));
node->data=(void *)malloc(stack->elementSize);
node->next=stack->top;
stack->top=node;
memcpy(node->data,data,stack->elementSize);
stack->size++;
}
void pop(Stack *stack,void *data)
{
StackNode *node;
node=stack->top;
stack->top=stack->top->next;
memcpy(data,(const void *)node->data,stack->elementSize);
free(node->data);
free(node);
stack->size--;
}
int isEmpty(Stack *stack)
{
return stack->size==0;
}
int findPartitionPoint(void *ptr,int lb,int ub,int es,int (*p2f)(void *,void *))
{
int e,f;
void *g;
g=(void *)malloc(es);
e=lb;
f=ub;
while(e<f)
{
while(e<ub && p2f(ptr+(e*es),ptr+(lb*es))<=0) e++;
while(p2f(ptr+(f*es),ptr+(lb*es))>0) f--;
if(e<f)
{
memcpy(g,(const void *)ptr+(e*es),es);
memcpy(ptr+(e*es),(const void *)ptr+(f*es),es);
memcpy(ptr+(f*es),(const void *)g,es);
}
else
{
memcpy(g,(const void *)ptr+(f*es),es);
memcpy(ptr+(f*es),(const void *)ptr+(lb*es),es);
memcpy(ptr+(lb*es),(const void *)g,es);
}
}
free(g);
return f;
}
void quickSort(void *ptr,int lowerBound,int upperBound,int es,int (*p2f)(void *,void *))
{
struct LBUB
{
int lb,ub;
};
struct LBUB lbub;
Stack stack;
int pp,lb,ub;
initStack(&stack,sizeof(struct LBUB));
lbub.lb=lowerBound;
lbub.ub=upperBound;
push(&stack,&lbub);
while(!isEmpty(&stack))
{
pop(&stack,&lbub);
pp=findPartitionPoint(ptr,lbub.lb,lbub.ub,es,p2f);
ub=lbub.ub;
lb=lbub.lb;
if(pp+1<ub)
{
lbub.ub=ub;
lbub.lb=pp+1;
push(&stack,&lbub);
}
if(pp-1>lb)
{
lbub.ub=pp-1;
lbub.lb=lb;
push(&stack,&lbub);
}
}
}
int myComparator(void *left,void *right)
{
return (*((int *)left))-(*((int *)right));
}
int main()
{
int req,e,lb,ub;
int *arr;
printf("Enter requiremnet : ");
scanf("%d",&req);
arr=(int *)malloc(sizeof(int)*req);
for(e=0;e<req;e++)
{
printf("Enter a number : ");
scanf("%d",&arr[e]);
}
lb=0;
ub=req-1;
quickSort(arr,lb,ub,sizeof(int),myComparator);
for(e=0;e<req;e++) printf("%d\n",arr[e]);
return 0;
}