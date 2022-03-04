#include<stdio.h>
int main()
{
int num,i;
FILE *f;
f=fopen("data.d","rb");
for(i=0;i<1250000;i++)
{
fread(&num,1,sizeof(int),f);
if(feof(f)) break;
printf("%d i %d\n",num,i);
}

return 0;
}