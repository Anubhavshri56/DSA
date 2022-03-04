#include<stdio.h>
#include<stdlib.h>
int findKthElement(int *arr,int ub,int k)
{
int swap,e,f;
while(1)
{
swap=0;
e=0;
while(e<k && arr[k]>arr[e]) e++;
if(e<k)
{
f=arr[e];
arr[e]=arr[k];
arr[k]=f;
continue;
}
e=ub;
while(e>k && arr[k]<arr[e]) e--;
if(e>k)
{
f=arr[e];
arr[e]=arr[k];
arr[k]=f;
continue;
}
return arr[k];
}

}
int main()
{
int *arr;
int req,e,k,g;
printf("Enter requirement : ");
scanf("%d",&req);
arr=(int *)malloc(sizeof(int)*req);
for(e=0;e<req;e++)
{
printf("enter a number : ");
scanf("%d",&arr[e]);
}
printf("Enter kth number : ");
scanf("%d",&k);
g=findKthElement(arr,req-1,k-1);
printf("%dth smallest element is %d",k,g);
return 0;
}