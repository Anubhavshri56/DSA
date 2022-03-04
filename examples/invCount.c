#include<stdio.h>
#include<stdlib.h>
int main()
{
int arr[10];
int e,f,invCount;
for(e=0;e<10;e++)
{
printf("Enter a number : ");
scanf("%d",&arr[e]);
}
for(e=0,invCount=0;e<9;e++) for(f=e+1;f<10;f++) if(arr[e]>arr[f]) invCount++;
printf("%d\n",invCount);
return 0;
}