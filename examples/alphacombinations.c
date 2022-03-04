#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
str=(char *)malloc(sizeof(char)*(seedLength+2));
strcpy(str,seed);
for(i=0;i<setSize;i++)
{
str[seedLength]=set[i];
str[seedLength+1]='\0';
_printAllCombination(str,set,setSize,maxLength-1);
}
free(str);
}
void printAllCombination(char *set,int setSize,int maxLength)
{
_printAllCombination("",set,setSize,maxLength);
}
int main()
{
char set[26];
int setLength;
printf("Enter a string : ");
scanf("%s",set);
setLength=strlen(set);
printAllCombination(set,setLength,5);
return 0;
}