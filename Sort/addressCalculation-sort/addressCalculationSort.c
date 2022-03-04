#include<stdio.h>
#include<stdlib.h>
typedef struct __node
{
int num;
struct __node *next;
}SLLNode;
typedef struct __sll
{
SLLNode *start;
}SLL;
void initSLL(SLL *sll)
{
sll->start=NULL;
}
int hash(int num,int dcOfLar)
{
int e;
if(num<0) num=num*(-1);
for(e=1;dcOfLar>1;e=e*10) dcOfLar--;
return num/e;
}
int findLargest(int *arr,int size)
{
int lar,e;
lar=arr[0];
for(e=1;e<size;e++) if(arr[e]>lar) lar=arr[e];
return lar;
}
int calculateDC(int num)
{
int e=1;
if(num<0) num=num*(-1);
for(;num>9;e++) num=num/10;
return e;
}
void addToBox(int num,SLL *sll)
{
SLLNode *node,*prev,*curr;
node=(SLLNode *)malloc(sizeof(SLLNode));
node->num=num;
node->next=NULL;
if(sll->start==NULL)
{
sll->start=node;
return;
}
curr=sll->start;
while(curr!=NULL && curr->num<node->num)
{
prev=curr;
curr=curr->next;
}
if(curr==sll->start)
{
node->next=sll->start;
sll->start=node;
}
else
{
node->next=curr;
prev->next=node;
}
}
void getFromBoxes(int *arr,SLL *sll)
{
SLLNode *node;
int e,f;
f=0;
for(e=0;e<10;e++)
{
while(sll[e].start!=NULL)
{
arr[f]=sll[e].start->num;
f++;
node=sll[e].start;
sll[e].start=sll[e].start->next;
free(node);
}
}
}
void addressCalculationSort(int *arr)
{
int poslar,neglar,posdc,negdc,key,e,negIndex,g,f;
SLL *sll;
sll=(SLL *)malloc(sizeof(SLL)*10);
for(e=0;e<10;e++) initSLL(&sll[e]);
negIndex=0;
for(e=0;e<10;e++)
{
if(arr[e]<0)
{
g=arr[negIndex];
arr[negIndex]=arr[e];
arr[e]=g;
arr[negIndex]*=(-1);
negIndex++;
}
}
if(negIndex!=0)
{
neglar=findLargest(arr,negIndex);
negdc=calculateDC(neglar);
}
poslar=findLargest(&arr[negIndex],10-negIndex);
posdc=calculateDC(poslar);
if(negIndex!=0)
{
for(e=0;e<negIndex;e++)
{
key=hash(arr[e],negdc);
addToBox(arr[e],&sll[key]);
}
getFromBoxes(arr,sll);
for(e=0,f=negIndex-1;e<f;e++,f--)
{
g=arr[e];
arr[e]=arr[f];
arr[f]=g;
arr[e]*=(-1);
arr[f]*=(-1);
}
if(e==f) arr[e]*=(-1);
}
for(e=negIndex;e<10;e++)
{
key=hash(arr[e],posdc);
addToBox(arr[e],&sll[key]);
}
getFromBoxes(&arr[negIndex],sll);
}
int main()
{
int arr[10],e;
for(e=0;e<10;e++)
{
printf("Enter a number : ");
scanf("%d",&arr[e]);
}
addressCalculationSort(arr);
for(e=0;e<10;e++) printf("%d\n",arr[e]);
return 0;
}