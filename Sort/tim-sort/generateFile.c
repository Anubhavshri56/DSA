#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
FILE *f;
int i,num;
f=fopen("data.dat","wb");
srand(time(0));
for(i=0;i<5000;i++)
{
num=rand();
fwrite(&num,1,sizeof(int),f);
}
fclose(f);
return 0;
}