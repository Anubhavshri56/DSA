#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
FILE *f;
int y;
char x[21];
strcpy(x,"filex.dat");
for(y=49;y<58;y++)
{
x[4]=y;
printf("%s\n",x);
f=fopen(&x[0],"wb");
}
fclose(f);
}