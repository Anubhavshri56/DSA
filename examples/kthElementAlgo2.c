#include<stdio.h>
#include<stdlib.h>
void createMinHeap(int *arr,int req)
{
int y,ci,ri,g;
y=1;
while(y<req)
{
ci=y;
while(ci>0)
{
ri=(ci-1)/2;
if(arr[ri]>arr[ci])
{
g=arr[ci];
arr[ci]=arr[ri];
arr[ri]=g;
ci=ri;
}
else break;
}
y++;
}
}
int findKthElement(int *arr,int k,int req)
{
int y,swi,ri,lci,rci,g;
y=req;
while(k>0)
{
g=arr[0];
arr[0]=arr[y];
arr[y]=g;
k--;
y--;
ri=0;
while(ri<y)
{
lci=ri*2+1;
rci=lci+1;
if(lci>y) break;
if(rci>y) swi=lci;
else
{
if(arr[lci]>arr[rci]) swi=rci;
else swi=lci;
}
if(arr[swi]<arr[ri])
{
g=arr[swi];
arr[swi]=arr[ri];
arr[ri]=g;
ri=swi;
}
else break;
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
createMinHeap(arr,req);
g=findKthElement(arr,k-1,req-1);
printf("%dth smallest element is : %d",k,g);
return 0;
}