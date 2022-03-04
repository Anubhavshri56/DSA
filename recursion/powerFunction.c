#include<stdio.h>
int count=0;
int pwr(int b,int e)
{
count++;
int odd,num,m;
if(e==1) return b;
odd=0;
if(e%2!=0) odd=1;
e=e/2;
m=pwr(b,e);
num=m*m;
if(odd==1) num=num*b;
return num;
}
int powerFunction(int b,int e)
{
if(e==0) return 1;
return pwr(b,e);
}
int main()
{
int e=powerFunction(2,1);
printf("%d\n",e);
printf("%d Number of copies made\n",count);
return 0;
}
