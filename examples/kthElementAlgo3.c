#include<stdio.h>
#include<stdlib.h>
void createHeap(int *arr,int k)
{
int y,ri,ci,g;
y=1;
while(y<k)
{
ci=y;
while(ci>0)
{
ri=(ci-1)/2;
if(arr[ci]>arr[ri])
{
g=arr[ci];
arr[ci]=arr[ri];
arr[ri]=g;
}
else break;
}
y++;
}
}
int findKthElement(int *arr,int ub,int k)
{
int e,ri,lci,rci,swi,g,heapUb;
heapUb=k-1;
for(e=k;e<ub;e++)
{
if(arr[e]<arr[0])
{
g=arr[0];
arr[0]=arr[e];
arr[e]=g;
ri=0;
while(ri<heapUb)
{
lci=ri*2+1;
rci=lci+1;
if(lci>heapUb) break;
if(rci>heapUb) swi=lci;
else
{
if(arr[lci]>arr[rci]) swi=lci;
else swi=rci;
}
if(arr[swi]>arr[ri])
{
g=arr[swi];
arr[swi]=arr[ri];
arr[ri]=g;
ri=swi;
}
else break;
}
}
}
return arr[0];
}
int main()
{
int e,k,req,g;
int *arr;
printf("Enter requirement : ");
scanf("%d",&req);
arr=(int *)malloc(sizeof(int)*req);
for(e=0;e<req;e++)
{
printf("Enter a number : ");
scanf("%d",&arr[e]);
}
printf("Enter kth value : ");
scanf("%d",&k);
createHeap(arr,k);
g=findKthElement(arr,req,k);
printf("%dth smallest element is : %d",k,g);
return 0;
}