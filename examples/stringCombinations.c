#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void _printAllCombinations(char *set,int start,int end)
{
int e;
char f;
if(start==end)
{
printf("%s\n",set);
return;
}
for(e=start;e<=end;e++)
{
f=set[e];
set[e]=set[start];
set[start]=f;
_printAllCombinations(set,start+1,end);
f=set[e];
set[e]=set[start];
set[start]=f;
}
}
void printAllCombinations(char *set)
{
int end,start;
start=0;
end=strlen(set)-1;
_printAllCombinations(set,start,end);
}
int main()
{
char set[20];
printf("enter a string : ");
scanf("%s",set);
printAllCombinations(set);
return 0;
}