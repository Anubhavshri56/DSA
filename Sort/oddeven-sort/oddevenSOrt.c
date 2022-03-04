#include<stdio.h>
void oddEvenSort(int *arr,int size)
{
int even,odd,g,swapCount;
while(1)
{
swapCount=0;
odd=2;
while(odd<size)
{
if(arr[odd]<arr[odd-1])
{
g=arr[odd];
arr[odd]=arr[odd-1];
arr[odd-1]=g;
swapCount++;
}
odd+=2;
}
even=1;
while(even<size)
{
if(arr[even]<arr[even-1])
{
g=arr[even];
arr[even]=arr[even-1];
arr[even-1]=g;
swapCount++;
}
even+=2;
}
if(swapCount==0) break;
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
oddEvenSort(arr,10);
for(e=0;e<10;e++) printf("%d\n",arr[e]);
return 0;
}