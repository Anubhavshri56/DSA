#include<stdio.h>
int arr[32]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int pwr(int b,int e)
{
if(e==1) return b;
if(arr[e]!=0) return arr[e];
arr[e]=(e%2==0)?pwr(b,e/2)*pwr(b,e/2):pwr(b,e/2)*pwr(b,e/2)*b;
return arr[e];
}
int power(int b,int e)
{
if(e==0) return 1;
return pwr(b,e);
}
int main()
{
int x,y,m;
printf("Enter a number : ");
scanf("%d",&x);
printf("Enter another Number : ");
scanf("%d",&y);
m=power(x,y);
printf("%d\n",m);
return 0;
}
