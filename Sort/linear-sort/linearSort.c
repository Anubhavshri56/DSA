#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void linearSort(void *ptr,int cs,int es,int (*k)(void *,void *))
{
int e,f,w;
void *a,*b,*c;
c=malloc(es);
for(e=0;e<=cs-2;e++)
{
for(f=e+1;f<=cs-1;f++)
{
a=ptr+(e*es);
b=ptr+(f*es);
w=k(a,b);
if(w>0)
{
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
}
}
}
int myComparator(void *left,void *right)
{
int *a,*b;
a=(int *)left;
b=(int *)right;
return *a-*b;
}
int main()
{
int y,req,*arr;
printf("Enter requirement : ");
scanf("%d",&req);
arr=(int *)malloc(sizeof(int)*req);
for(y=0;y<req;y++) scanf("%d",&arr[y]);
linearSort(arr,req,sizeof(int),myComparator);
for(y=0;y<req;y++) printf("%d ",arr[y]);
return 0;
}