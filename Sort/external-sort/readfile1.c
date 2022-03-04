#include<stdio.h>
int main()
{
int num,i;
FILE *f;
f=fopen("file10.dat","rb");
for(i=0;i<125000;i++)
{
fread(&num,1,sizeof(int),f);
printf("%d\n",num);
}

return 0;
}