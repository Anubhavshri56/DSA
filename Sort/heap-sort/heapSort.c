#include<stdio.h>
#include<stdlib.h>
int main()
{
int req,ci,ri,lci,rci,swi,y,lb,ub,e,f,g;
int *arr;
printf("Enter requirement : ");
scanf("%d",&req);
arr=(int *)malloc(sizeof(int)*req);
for(e=0;e<req;e++)
{
printf("Enter a number : ");
scanf("%d",&arr[e]);
}
//converting to max heap
lb=0;
ub=req-1;
y=lb+1;
while(y<=ub)
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
ci=ri;
}
else break;
}
y++;
}
//heapSort
while(ub>0)
{
g=arr[ub];
arr[ub]=arr[0];
arr[0]=g;
ub--;
ri=0;
while(ri<ub)
{
lci=ri*2+1;
rci=lci+1;
if(lci>ub) break;
if(rci>ub) swi=lci;
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
for(e=0;e<req;e++) printf("%d\n",arr[e]);
return 0;
}