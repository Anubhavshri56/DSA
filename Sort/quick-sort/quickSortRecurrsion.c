#include<stdio.h>
#include<stdlib.h>
int findPP(int *arr,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && arr[e]<=arr[lb]) e++;
while(arr[f]>arr[lb]) f--;
if(e<f)
{
g=arr[e];
arr[e]=arr[f];
arr[f]=g;
}
else
{
g=arr[lb];
arr[lb]=arr[f];
arr[f]=g;
}
}
return f;
}
void quickSort(int *arr,int lb,int ub)
{
if(ub<=lb) return;
int pp,e;
pp=findPP(arr,lb,ub);
quickSort(arr,lb,pp-1);
quickSort(arr,pp+1,ub);
}
int main()
{
int arr[10],e;
for(e=0;e<10;e++) scanf("%d",&arr[e]);
quickSort(arr,0,9);
printf("---------------------------------\n");
for(e=0;e<10;e++) printf("%d\n",arr[e]);
return 0;
}