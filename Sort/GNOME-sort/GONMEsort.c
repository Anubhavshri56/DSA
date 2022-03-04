#include<stdio.h>

void GNOMESort(int *arr)
{
int e,f,g;
e=0;
while(e<10)
{
if(e==0) e++;
if(arr[e]<arr[e-1])
{
g=arr[e];
arr[e]=arr[e-1];
arr[e-1]=g;
e--;
}
else e++;
}

}
int main()
{
int e,arr[10];
for(e=0;e<10;e++)
{
printf("Enter a number : ");
scanf("%d",&arr[e]);
}
GNOMESort(arr);
for(e=0;e<10;e++) printf("%d\n",arr[e]);
return 0;
}