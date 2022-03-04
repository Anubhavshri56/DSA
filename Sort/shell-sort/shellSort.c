#include<stdio.h>
#include<stdlib.h>
int main()
{
int diffFactor,e,f,g,y,num;
int arr[10];
for(e=0;e<10;e++)
{
printf("Enter a number : ");
scanf("%d",&arr[e]);
}
diffFactor=10/2;
while(diffFactor>0)
{
y=diffFactor;
while(y<10)
{
for(e=y-diffFactor,num=arr[y];e>=0 && num<arr[e];e=e-diffFactor) arr[e+diffFactor]=arr[e];
arr[e+diffFactor]=num;
y=y+diffFactor;
}
diffFactor=diffFactor/2;
}
for(e=0;e<10;e++) printf("%d\n",arr[e]);
return 0;
}