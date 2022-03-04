#include<stdio.h>

void cocktailShakerSort(int *arr,int lb,int ub)
{
int e,f,g,h,swapCount,i;
e=lb;
f=ub;
while(e<f)
{
g=e;
swapCount=0;
while(g<f)
{
if(arr[g]>arr[g+1])
{
i=arr[g];
arr[g]=arr[g+1];
arr[g+1]=i;
swapCount=1;
}
g++;
}
if(swapCount==0) break;
swapCount=0;
f--;
h=f;
while(h>e)
{
if(arr[h]<arr[h-1])
{
i=arr[h];
arr[h]=arr[h-1];
arr[h-1]=i;
swapCount=1;
}
h--;
}
if(swapCount==0) break;
e++;
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
cocktailShakerSort(arr,0,9);
for(e=0;e<10;e++) printf("%d\n",arr[e]);

}