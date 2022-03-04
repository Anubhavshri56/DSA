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
g=arr[f];
arr[f]=arr[lb];
arr[lb]=g;
}
}
return f;
}
void quickSort(int *arr,int lb,int ub)
{
if(ub<=lb) return;
int pp=findPP(arr,lb,ub);
quickSort(arr,lb,pp-1);
quickSort(arr,pp+1,ub);
}
int main()
{
int n,k,e,f;
int *arr;
printf("Enter size of array : ");
scanf("%d",&n);
arr=(int *)malloc(sizeof(int)*n);
for(e=0;e<n;e++)
{
printf("Enter a number : ");
scanf("%d",&arr[e]);
}
printf("Enter which number of smallest number you want : ");
scanf("%d",&k);
quickSort(arr,0,n-1);
printf("%dth smallest element int the array is : %d",k,arr[k-1]);
}