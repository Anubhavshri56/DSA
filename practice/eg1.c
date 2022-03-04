#include<stdio.h>
#include<stdlib.h>
int main()
{
int req,e,f,m,g,si;
int *arr,*lbStk1,*ubStk1,*lbStk2,*ubStk2,*tmp;
int top1,top2,lb,ub,mid,i1,i2,i3;
printf("enter req : ");
scanf("%d",&req);
arr=(int *)malloc(sizeof(int)*req);
lbStk1=(int *)malloc(sizeof(int)*req);
ubStk1=(int *)malloc(sizeof(int)*req);
lbStk2=(int *)malloc(sizeof(int)*req);
ubStk2=(int *)malloc(sizeof(int)*req);
tmp=(int *)malloc(sizeof(int)*req);
for(e=0;e<req;e++)
{
printf("enter a number : ");
scanf("%d",&arr[e]);
}
top1=req;
top2=req;
lb=0;
ub=req-1;
top1--;
lbStk1[top1]=lb;
ubStk1[top1]=ub;
while(top1!=req)
{
lb=lbStk1[top1];
ub=ubStk1[top1];
top1++;
top2--;
lbStk[top2]=lb;
ubStk[top2]=ub;
mid=(lb+ub)/2;
if(lb<mid)
{
top1--;
lbStk1[top1]=lb;
ubStk1[top1]=mid;
}
if(ub>mid+1)
{
top1--;
lbStk1[top1]=mid+1;
ubStk1[top1]=ub;
}
}




for(e=0;e<req;e++) printf("%d\n",arr[e]);
return 0;
}