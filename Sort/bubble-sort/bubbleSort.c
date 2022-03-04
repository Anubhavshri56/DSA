#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void bubbleSort(void *ptr,int cs,int es,int (*p2f)(void *,void *))
{
int e,f,m,w;
void *a,*b,*c;
c=(void *)malloc(es);
m=cs-2;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
a=ptr+(f*es);
b=ptr+(e*es);
w=p2f(a,b);
if(w<0)
{
memcpy(c,a,es);
memcpy(a,b,es);
memcpy(b,c,es);
}
e++;
f++;
}
m--;
}
free(c);
}
struct student
{
int rollNumber;
char name[50];
};
int myComparator(void *left,void *right)
{
struct student *a,*b;
a=(struct student *)left;
b=(struct student *)right;
return strcmp(a->name,b->name);
}
int main()
{
int y,req;
struct student *s;
printf("Enter Requirement : ");
scanf("%d",&req);
fflush(stdin);
s=(struct student *)malloc(sizeof(struct student)*req);
for(y=0;y<req;y++)
{
printf("Enter rollNumber : ");
scanf("%d",&s[y].rollNumber);
fflush(stdin);
printf("Enter Name : ");
scanf("%s",&s[y].name);
fflush(stdin);
}
bubbleSort(s,req,sizeof(struct student),myComparator);
for(y=0;y<req;y++)
{
printf("%d %s\n",s[y].rollNumber,s[y].name);
}
free(s);
return 0;
}