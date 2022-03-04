#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void _printAllDistCombination(char *seed,char *set,int setSize,int maxLength)
{
int seedLength,i,f,found;
char *str;
if(maxLength==0)
{
printf("%s\n",seed);
return;
}
seedLength=strlen(seed);
str=(char *)malloc(sizeof(char)*(seedLength+2));
strcpy(str,seed);
for(i=0;i<setSize;)
{
found=0;
for(f=0;f<seedLength;f++)
{
if(str[f]==set[i])
{
i++;
found=1;
break;
}
}
if(found==0)
{
str[seedLength]=set[i];
str[seedLength+1]='\0';
_printAllDistCombination(str,set,setSize,maxLength-1);}
free(str);

}
}
void printAllDistCombinations(char *set,int setSize,int maxLength)
{
_printAllDistCombination("",set,setSize,maxLength);
}
int main()
{
char set[26];
int setLength;
printf("Enter a string : ");
scanf("%s",set);
setLength=strlen(set);
printAllDistCombinations(set,setLength,3);
return 0;
}