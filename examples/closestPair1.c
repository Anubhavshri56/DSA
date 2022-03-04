#include<stdio.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int points[22][2]={{1,3},{1,6},{2,3},{2,7},{1,8},{3,5},{3,9},{4,8},{4,10},{5,7},{5,10},{6,6},{6,9},{7,4},{7,10},{8,3},{8,6},{9,4},{10,7},{10,10},{11,9},{11,11}};
int findPP(int **arr,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && arr[e][0]<=arr[lb][0]) e++;
while(arr[f][0]>arr[lb][0]) f--;
if(e<f)
{
g=arr[e][0];
arr[e][0]=arr[f][0];
arr[f][0]=g;
}
else
{
g=arr[lb][0];
arr[lb][0]=arr[f][0];
arr[f][0]=g;
}
}
return f;
}
void quickSort(int **arr,int lb,int ub)
{
if(ub<=lb) return;
int pp,e;
pp=findPP(arr,lb,ub);
quickSort(arr,lb,pp-1);
quickSort(arr,pp+1,ub);
}
int shortest(int lb,int size,int ub)
{

}
int main()
{
quickSort(points,0,21);
int closest1[2][2],closest2[2][2];
double distance1=0,distance2=0,tmpDis;
int e,f,diff1,diff2;
for(e=0;e<4;e++)
{
for(f=e+1;f<5;f++)
{
diff1=points[f][0]-points[e][0];
diff2=points[f][1]-points[e][1];
diff1*=diff1;
diff2*=diff2;
tmpDis=sqrt(diff1+diff2);
if(distance1==0)
{
distance1=tmpDis;
closest1[0][0]=points[e][0];
closest1[0][1]=points[e][1];
closest1[1][0]=points[f][0];
closest1[1][1]=points[f][1];
}
else if(tmpDis<distance1)
{
distance1=tmpDis;
closest1[0][0]=points[e][0];
closest1[0][1]=points[e][1];
closest1[1][0]=points[f][0];
closest1[1][1]=points[f][1];
}
}
}
for(e=0;e<4;e++)
{
for(f=e+1;f<5;f++)
{
diff1=points[f][0]-points[e][0];
diff2=points[f][1]-points[e][1];
diff1*=diff1;
diff2*=diff2;
tmpDis=sqrt(diff1+diff2);
if(distance2==0)
{
distance2=tmpDis;
closest2[0][0]=points[e][0];
closest2[0][1]=points[e][1];
closest2[1][0]=points[f][0];
closest2[1][1]=points[f][1];
}
else if(tmpDis<distance2)
{
distance2=tmpDis;
closest2[0][0]=points[e][0];
closest2[0][1]=points[e][1];
closest2[1][0]=points[f][0];
closest2[1][1]=points[f][1];
}
}
}
if(distance1<distance2) printf("The closest pairs are : (%d,%d) and (%d,%d)\n",closest1[0][0],closest1[0][1],closest1[1][0],closest1[1][1]);
else printf("The closest pairs are : (%d,%d) and (%d,%d)\n",closest2[0][0],closest2[0][1],closest2[1][0],closest2[1][1]);
return 0;
}