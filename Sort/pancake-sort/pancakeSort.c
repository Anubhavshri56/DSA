#include <stdio.h>
int main()
{
int arr[10],e,f,g,lar,rev;
for(e=0;e<10;e++) scanf("%d",&arr[e]);
for(g=10;g>0;g--)
{
lar=arr[0];
f=0;
for(e=1;e<g;e++)
{
if(lar<arr[e])
{
f=e;
lar=arr[e];
}
}
if(f==g-1) continue;
for(e=0;e<f;e++,f--)
{
rev=arr[e];
arr[e]=arr[f];
arr[f]=rev;
}
f=g-1;
for(e=0;e<f;e++,f--)
{
rev=arr[e];
arr[e]=arr[f];
arr[f]=rev;
}
}
for(e=0;e<10;e++) printf("%d\n",arr[e]);
return 0;
}