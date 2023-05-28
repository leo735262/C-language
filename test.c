#include<stdio.h>
#define pi 3.141592653589793238
int main(){
double sum=0,sum1=0;
long long int f;
for(int i=1;i<255;i++){
    f=i*i*i*i;
    sum+=(double)1/f;
}
printf("%.10lf\n",sum);
sum1=pi*pi*pi*pi/90.0;
printf("%.10lf\n",sum1);

}
