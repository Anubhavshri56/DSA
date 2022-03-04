#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
FILE *file;
int num;
file=fopen("data.d","wb");
srand(time(0));
for(int i=0;i<125000000;i++)
{
num=rand();
fwrite((void *)&num,1,sizeof(int),file);
}
fclose(file);
}