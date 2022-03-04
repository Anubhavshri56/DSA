#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insertionSort(void *ptr,int cs,int es,int (*p2f)(void *,void *))
{
int e,f,w;
void *c;
c=(void *)malloc(es);
e=1;
while(e<=cs-1)
{
memcpy(c,(const void *)(ptr+(e*es)),es);
f=e-1;
while(f>=0 && p2f(ptr+(f*es),c)>0)
{
memcpy(ptr+(f+1)*es,(const void *)(ptr+(f*es)),es);
f--;
}
memcpy(ptr+(f+1)*es,(const void *)c,es);
e++;
}
free(c);
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
insertionSort(arr,req,sizeof(int),myComparator);
for(y=0;y<req;y++) printf("%d\n",arr[y]);
return 0;
}