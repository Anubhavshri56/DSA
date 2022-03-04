#include<stdio.h>
int binarySearch(int *arr,int num,int si,int ei)
{
int mid;
while(si<=ei)
{
mid=(si+ei)/2;
if(num==arr[mid]) return mid;
else if(num>arr[mid]) si=mid+1;
else ei=mid-1;
}
return si;
}
void binaryInsertionSort(int *arr,int size)
{
int lb,ub,si,ei,num,f,g,index;
lb=0;
ub=0;
while(ub<size-1)
{
si=lb;
ei=ub;
num=arr[ub+1];
index=binarySearch(arr,num,si,ei);
f=ub+1;
while(f>index)
{
g=arr[f];
arr[f]=arr[f-1];
arr[f-1]=g;
f--;
}
arr[index]=num;
ub++;
}
}

int main()
{
int e,arr[10];
for(e=0;e<10;e++)
{
printf("Enter a number : ");
scanf("%d",&arr[e]);
}
binaryInsertionSort(arr,10);
for(e=0;e<10;e++) printf("%d\n",arr[e]);

}