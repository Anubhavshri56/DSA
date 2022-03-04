#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printAllCombinations(char *arr,int s,int e)
{
int i,k;
char g;
if(s==e)
{
printf("%s\n",arr);
return;
}
for(i=s;i<=e;i++)
{
for(k=0;k<i;k++) if(arr[k]==arr[i]) break;
if(k<i) continue;
g=arr[i];
arr[i]=arr[s];
arr[s]=g;
printAllCombinations(arr,s+1,e);
g=arr[i];
arr[i]=arr[s];
arr[s]=g;
}


}

int main()
{
char arr[21];
int len;
printf("Enter a string : ");
scanf("%s",arr);
len=strlen(arr);
printAllCombinations(arr,0,len-1);
return 0;
}