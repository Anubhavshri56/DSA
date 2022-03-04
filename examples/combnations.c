#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void _printAllCombination(char *seed,char *set,int setSize,int maxLength)
{
int seedLength,i;
char *str;
if(maxLength==0)
{
printf("%s\n",seed);
return;
}
seedLength=strlen(seed);
str=(char *)malloc(sizeof(char)*seedLength+2);
strcpy(str,seed);
for(i=0;i<maxLength;i++)
{
str[seedLength]=set[i];
str[seedLength+1]='\0';
_printAllCombination(seed,set,setSize,maxLength);
}
}
void printAllCombination(char *set,int setSize,int maxLength)
{
_printAllCombination("",set,setSize,maxLength);
}
int main()
{
char set[10]={'0','1','2','3','4','6','7','8','9'};
printAllCombination(set,10,3);
return 0;
}