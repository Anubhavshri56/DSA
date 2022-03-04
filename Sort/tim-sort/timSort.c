#include<stdio.h>
void populateDS()
{
int **arr,size,non,rows,col,num;
FILE *f;
f=fopen("data.dat","rb");
fseek(f,0,SEEK_END);
size=ftell(f);
non=size/4;
rows=non/64;
rows++;
arr=(int **)malloc(sizeof(int *)*rows);
fseek(f,0,SEEK_SET);
for(int e=0;e<rows;e++) arr[e]=(int *)malloc(sizeof(int)*64);
for(int e=0;e<rows;e++)
{
for(int f=0;f<64;f++)
{
fread(&num,1,sizeof(int),f);
if(feof(f)) break;
arr[e][f]=num;
}
if(feof(f)) break;
}

}
int main()
{
int **arr;
arr=populateDS();


return 0;
}