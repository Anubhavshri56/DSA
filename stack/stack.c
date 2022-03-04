#include<stdio.h>
#include<stdlib.h>
typedef struct __stack_node
{
int num;
struct __stack_node *next;
}StackNode;
typedef struct __stack
{
StackNode *start;
}Stack;
void initStack(Stack *stack)
{
stack->start=NULL;
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
return;
}
node->next=stack->start;
stack->start=node;
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
int top(Stack *stack)
{
return stack->start->num;
}
int main()
{
Stack stack;
initStack(&stack);
int e;
push(&stack,10);
push(&stack,40);
push(&stack,43);
push(&stack,678);
push(&stack,0);
push(&stack,1);
push(&stack,1120);
printf("top %d\n",top(&stack));
while(!isStackEmpty(&stack))
{
printf("%d\n",pop(&stack));
}
return 0;
}