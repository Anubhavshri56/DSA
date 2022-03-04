#include<stdio.h>
#include<stdlib.h>
void merge(int *arr,int lb1,int ub1,int lb2,int ub2)
{
int size1,size2,size3,i1,i2,i3;
int *tmp;
size1=ub1-lb1+1;
size2=ub2-lb2+1;
size3=size1+size2;
tmp=(int *)malloc(sizeof(int)*size3);
i1=lb1;
i2=lb2;
i3=0;
while(i1<=ub1 && i2<=ub2)
{
if(arr[i1]<arr[i2])
{
tmp[i3]=arr[i1];
i1++;
}
else
{
tmp[i3]=arr[i2];
i2++;
}
i3++;
}
while(i1<=ub1)
{
tmp[i3]=arr[i1];
i1++;
i3++;
}
while(i2<=ub2)
{
tmp[i3]=arr[i2];
i2++;
i3++;
}
i3=0;
i1=lb1;
while(i1<=ub1)
{
arr[i1]=tmp[i3];
i1++;
i3++;
}
i2=lb2;
while(i2<=ub2)
{
arr[i2]=tmp[i3];
i2++;
i3++;
}
free(tmp);
}
void mergeSort(int *arr,int lb,int ub)
{
int mid;
if(lb>ub) return;
mid=(lb+ub)/2;
if(lb<mid) mergeSort(arr,lb,mid);
if(mid+1<ub) mergeSort(arr,mid+1,ub);
merge(arr,lb,mid,mid+1,ub);
}
int main()
{
int req,e,lb,ub;
int *arr;
printf("Enter your Requirement : ");
scanf("%d",&req);
arr=(int *)malloc(sizeof(int)*req);
for(e=0;e<req;e++)
{
printf("Enter a number : ");
scanf("%d",&arr[e]);
}
lb=0;
ub=req-1;
mergeSort(arr,lb,ub);
for(e=0;e<req;e++) printf("%d\n",arr[e]);
return 0;
}

