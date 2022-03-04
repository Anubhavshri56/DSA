#include<stdio.h>
#include<stdlib.h>
int merge(int *arr,int lb1,int ub1,int lb2,int ub2)
{
int size1,size2,size3,lb3,ub3,i1,i2,i3,g,invCount;
int *tmp;
size1=ub1-lb1+1;
size2=ub2-lb2+1;
size3=size1+size2;
i1=lb1;
i2=lb2;
i3=0;
invCount=0;
tmp=(int *)malloc(sizeof(int)*size3);
while(i1<=ub1 && i2<=ub2)
{
if(arr[i1]<=arr[i2])
{
tmp[i3]=arr[i1];
i1++;
}
else
{
invCount+=ub1-i1+1;
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
i1=lb1;
i3=0;
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
return invCount;
}
int invCount(int *arr,int lb,int ub)
{
int mid,count=0;
if(lb>=ub) return 0;
mid=(lb+ub)/2;
count+=invCount(arr,lb,mid);
count+=invCount(arr,mid+1,ub);
count+=merge(arr,lb,mid,mid+1,ub);
return count;
}
int main()
{
int arr[10],e,inverCount,inv=0;
for(e=0;e<10;e++)
{
scanf("%d",&arr[e]);
}
printf("inversion count is %d",invCount(arr,0,9));
return 0;
}