#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int num;
struct node *next;
}SLLNode;
typedef struct sllNode
{
SLLNode *start;
}SLL;
void initSLL(SLL *sll)
{
sll->start=NULL;
}
void add(SLL *sll,int num)
{
SLLNode *node;
node=(SLLNode *)malloc(sizeof(SLLNode));
node->num=num;
node->next=NULL;
if(sll->start==NULL)
{
sll->start=node;
return;
}
node->next=sll->start;
sll->start=node;
}
int removeFromSLL(SLL *sll)
{
int num;
SLLNode *node;
if(sll->start==NULL) return 0;
node=sll->start;
num=node->num;
sll->start=sll->start->next;
free(node);
return num;
}
void pigeonHoleSort(int *arr,int size)
{
int lar,sma,e,f,g,index;
SLL *sll;
lar=arr[0];
sma=arr[0];
for(e=1;e<10;e++)
{
if(arr[e]>lar) lar=arr[e];
if(arr[e]<sma) sma=arr[e];
}
f=lar-sma+1;
sll=(SLL *)malloc(sizeof(SLL)*f);
for(e=0;e<f;e++) initSLL(&sll[e]);
for(e=0;e<size;e++)
{
index=arr[e]-sma;
add(&sll[index],arr[e]);
}
g=0;
for(e=0;e<f;e++)
{
while(sll[e].start!=NULL)
{
arr[g]=removeFromSLL(&sll[e]);
g++;
}
}

}
int main()
{
int arr[10],e;
for(e=0;e<10;e++)
{
printf("Enter a number : ");
scanf("%d",&arr[e]);
}
pigeonHoleSort(arr,10);
for(e=0;e<10;e++) printf("%d\n",arr[e]);
return 0;
}