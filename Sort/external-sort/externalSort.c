#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int findPP(int *arr,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && arr[e]<=arr[lb]) e++;
while(arr[f]>arr[lb]) f--;
if(e<f)
{
g=arr[e];
arr[e]=arr[f];
arr[f]=g;
}
else
{
g=arr[lb];
arr[lb]=arr[f];
arr[f]=g;
}
}
return f;
}
void quickSort(int *arr,int lb,int ub)
{
if(ub<=lb) return;
int pp,e;
pp=findPP(arr,lb,ub);
quickSort(arr,lb,pp-1);
quickSort(arr,pp+1,ub);
}
void sortFile()
{
int size,non,i,e,num;
int *arr;
char name[21];
FILE *file,*file1;
file=fopen("data.d","rb");
if(file==NULL) return;
fseek(file,0,SEEK_END);
size=ftell(file);
size=size/10;
non=size/4;
arr=(int *)malloc(sizeof(int)*non);
fseek(file,0,SEEK_SET);
for(i=1;i<=10;i++)
{
for(e=0;ftell(file)<(size*i);e++)
{
fread(&num,1,sizeof(int),file);
arr[e]=num;
}
quickSort(arr,0,non-1);
if(i==10)
{
strcpy(name,"filexy.dat");
name[4]=49;
name[5]=48;
}
else
{
strcpy(name,"filex.dat");
name[4]=i+48;
}
file1=fopen(name,"wb");
for(e=0;ftell(file1)<size;e++)
{
fwrite(&arr[e],1,sizeof(int),file1);
}
fclose(file1);
}
fclose(file);
}
void mergeFile()
{
FILE *dataFile,*file[10];
char name[21];
int num,i,e,tmpNum,f;
dataFile=fopen("data.d","wb");
for(i=1;i<=10;i++)
{
if(i==10)
{
strcpy(name,"filexy.dat");
name[4]=49;
name[5]=48;
}
else
{
strcpy(name,"filex.dat");
name[4]=i+48;
}
file[i-1]=fopen(name,"rb");
}
f=0;
while(1)
{
for(i=0;i<10;i++)
{
fread(&num,1,sizeof(int),file[i]);
if(feof(file[i])) continue;
else
{
e=i;
break;
}
}
if(i>=10) break;
for(i=0;i<10;i++)
{
if(i==e) continue;
fread(&tmpNum,1,sizeof(int),file[i]);
if(feof(file[i])) continue;
if(tmpNum<num)
{
num=tmpNum;
fseek(file[e],-sizeof(int),SEEK_CUR);
e=i;
}
else
{
fseek(file[i],-sizeof(int),SEEK_CUR);
}
}
fwrite(&num,1,sizeof(int),dataFile);
f++;
}
for(i=0;i<10;i++) fclose(file[i]);
fclose(dataFile);
}
int main()
{
sortFile();
mergeFile();
return 0;
}