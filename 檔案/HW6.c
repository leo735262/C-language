#include<stdio.h>
#include <math.h>
#include<assert.h>
#define m 1000000
int main(){
FILE *fp1=fopen("output.txt","w");
    assert(fp1!=NULL);
double sum=0;
const double pi=3.14159265;
int n=100;
    fprintf(fp1,"%c%c%c%c%c%c\n",'n',' ','a','r','e','a');

for(int j=3;j>0;j--,n=n*10,sum=0){
    for(int i=1;i<=n;i++)
        sum=sum+((pi/2)/n)*sin(i*((pi/2)/n));
          fprintf(fp1,"%d%c%lf\n",n,' ',sum);
}
for(int i=1;i<=m;i++)
        sum=sum+((pi/2)/m)*sin(i*((pi/2)/m));
          fprintf(fp1,"%d%c%lf\n",m,' ',sum);


fclose(fp1);
}
