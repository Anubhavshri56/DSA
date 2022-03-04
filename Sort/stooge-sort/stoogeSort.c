#include<stdio.h>
void stoogeSort(int *arr,int lb,int ub)
{
int size,g,f;
size=ub-lb+1;
if(arr[ub]<arr[lb])
{
g=arr[lb];
arr[lb]=arr[ub];
arr[ub]=g;
}
if(size==2) return;
f=size/3;
size=size-f;
stoogeSort(arr,lb,lb+size-1);
stoogeSort(arr,lb+f,ub);
stoogeSort(arr,lb,lb+size-1);
}

int main()
{
int e,arr[10];
for(e=0;e<10;e++)
{
printf("Enter a number : ");
scanf("%d",&arr[e]);
}
stoogeSort(arr,0,9);
for(e=0;e<10;e++) printf("%d\n",arr[e]);
return 0;
}