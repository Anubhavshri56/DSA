#include<stdio.h>
#include<math.h>
int main()
{
int points[10][2]={{10,2},{7,19},{-18,-19},{32,4},{97,3},{-56,6},{6,-56},{-10,-10},{0,0},{9,9}};
int closest[2][2];
double distance=0,tmpDis;
int e,f,diff1,diff2;
long sqr1,sqr2;
for(e=0;e<9;e++)
{
for(f=e+1;f<10;f++)
{
diff1=points[f][0]-points[e][0];
diff2=points[f][1]-points[e][1];
diff1*=diff1;
diff2*=diff2;
tmpDis=sqrt(diff1+diff2);
if(distance==0)
{
distance=tmpDis;
closest[0][0]=points[e][0];
closest[0][1]=points[e][1];
closest[1][0]=points[f][0];
closest[1][1]=points[f][1];
}
else if(tmpDis<distance)
{
distance=tmpDis;
closest[0][0]=points[e][0];
closest[0][1]=points[e][1];
closest[1][0]=points[f][0];
closest[1][1]=points[f][1];
}
}
}
printf("The closest pairs are : (%d,%d) and (%d,%d)\n",closest[0][0],closest[0][1],closest[1][0],closest[1][1]);
return 0;
}