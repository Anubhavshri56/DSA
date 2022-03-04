#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define bool int
#define true 1
#define True 1
#define TRUE 1
#define false 0
#define False 0
#define FALSE 0
typedef struct __stack_node
{
void *ptr;
struct __stack_node *next;
}StackNode;
typedef struct __stack
{
StackNode *top;
int elementSize;
int size;
}Stack;
void init(Stack *stack,int elementSize)
{
stack->top=NULL;
stack->size=0;
stack->elementSize=elementSize;
}
void push(Stack *stack,void *ptr,bool *success)
{
StackNode *node;
if(success) *success=false;
node=(StackNode *)malloc(sizeof(StackNode));
if(node==NULL) return;
if(ptr!=NULL)
{
node->ptr=(void *)malloc(sizeof(stack->elementSize));
if(node->ptr==NULL)
{
free(node);
return;
}
memcpy(node->ptr,(const void *)ptr,stack->elementSize);
}
else node->ptr=ptr;
node->next=stack->top;
stack->top=node;
stack->size++;
if(success) *success=true;
}
void * pop(Stack *stack,bool *success)
{
StackNode *node;
void *ptr;
if(success) *success=false;
if(stack==NULL) return NULL;
if(stack->top==NULL) return NULL;
//????? stack->top->ptr==NULL condition pending
node=stack->top;
stack->top=stack->top->next;
stack->size--;
ptr=node->ptr;
free(node);
if(success) *success=true;
return ptr;
}
int isEmpty(Stack *stack)
{
if(stack==NULL) return 1;
if(stack->top==NULL) return 1;
return 0;
}
void merge(int *arr,int lb1,int ub1,int lb2,int ub2)
{
int size1,size2,size3,i1,i2,i3;
int *tmp;
size1=ub1-lb1+1;
size2=ub2-lb2+1;
size3=size1+size2;
tmp=(int *)malloc(sizeof(int)*size3);
i1=lb1;
i2=lb2;
i3=0;
while(i1<=ub1 && i2<=ub2)
{
if(arr[i1]<arr[i2])
{
tmp[i3]=arr[i1];
i1++;
}
else
{
tmp[i3]=arr[i2];
i2++;
}
i3++;
}
while(i1<=ub1)
{
tmp[i3]=arr[i1];
i1++;
i3++;
}
while(i2<=ub2)
{
tmp[i3]=arr[i2];
i2++;
i3++;
}
i3=0;
i1=lb1;
while(i1<=ub1)
{
arr[i1]=tmp[i3];
i1++;
i3++;
}
i2=lb2;
while(i2<=ub2)
{
arr[i2]=tmp[i3];
i2++;
i3++;
}
free(tmp);
}
void mergeSort(int *arr,int lowerBound,int upperBound)
{
struct LBUB
{
int lb,ub;
};
int mid,a,b,succ;
struct LBUB lbub1,*lbub2;
Stack stack1,stack2;
init(&stack1,sizeof(struct LBUB));
init(&stack2,sizeof(struct LBUB));
lbub1.lb=lowerBound;
lbub1.ub=upperBound;
push(&stack1,&lbub1,&succ);
while(!isEmpty(&stack1))
{
lbub2=(struct LBUB *)pop(&stack1,&succ);
push(&stack2,lbub2,&succ);
a=lbub2->lb;
b=lbub2->ub;
mid=(a+b)/2;
if(a<mid)
{
lbub1.lb=a;
lbub1.ub=mid;
push(&stack1,&lbub1,&succ);
}
if(b>mid+1)
{
lbub1.lb=mid+1;
lbub1.ub=b;
push(&stack1,&lbub1,&succ);
}
}
while(!isEmpty(&stack2))
{
lbub2=(struct LBUB *)pop(&stack2,&succ);
a=lbub2->lb;
b=lbub2->ub;
mid=(a+b)/2;
merge(arr,a,mid,mid+1,b);
}
}
int main()
{
int req,e,lb,ub;
int *arr;
printf("Enter your Requirement : ");
scanf("%d",&req);
arr=(int *)malloc(sizeof(int)*req);
for(e=0;e<req;e++)
{
printf("Enter a number : ");
scanf("%d",&arr[e]);
}
lb=0;
ub=req-1;
mergeSort(arr,lb,ub);
for(e=0;e<req;e++) printf("%d\n",arr[e]);
return 0;
}