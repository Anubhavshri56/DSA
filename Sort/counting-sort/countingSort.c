#include<stdio.h>
#include<stdlib.h>
int main()
{
int arr[10],lar,e,f;
int *tmp;
for(e=0;e<10;e++)
{
printf("Enter a Number : ");
scanf("%d",&arr[e]);
}
for(e=1,lar=arr[0];e<10;e++) if(arr[e]>lar) lar=arr[e];
tmp=(int *)malloc(sizeof(int)*(lar+1));
for(e=0;e<lar;e++) tmp[e]=0;
for(e=0;e<10;e++) tmp[arr[e]]++;
for(e=0,f=0;e<lar+1;e++)
{
if(tmp[e]!=0)
{
while(tmp[e]!=0)
{
arr[f]=e;
tmp[e]--;
f++;
}
}
}

for(e=0;e<10;e++) printf("%d\n",arr[e]);
return 0;
}