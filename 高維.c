#include<stdio.h>
#include<math.h>
#define pi 3.141592653589793238
double problem1(int n){
    double sum=0;
	for(int i=1;i<=n;i++)
    	sum+=(double)1/pow(i,4);
    return sum;

}

double problem2(int n){
    long long int f=1;
    double sum=1;
	for(int i=1;i<=n;i++){
        f*=i;
    	sum+=(double)1/f;
	}
    return sum;

}

double problem3(int n){
    double sum=0;
	for(int i=0;i<=n;i++){
    	sum+=(double)4/(2*i+1)*pow(-1,i);
	}
    return sum;

}

double problem4(int n){
    double sum=3.0;
    int f;
	for(int i=1;i<=n;i++){
        f=2*i*(2*i+1)*(2*i+2)*pow(-1,i+1);
    	sum+=(double)4/f;
	}
    return sum;

}

int main(){
    double s1a,s1b;
	s1a=problem1(10);
	printf("第1題(a):%.16lf\n",s1a);
	s1b=problem1(100);
	printf("第1題(b):%.16lf\n",s1b);

	double s2a,s2b,e=exp(1);
	printf("Euler number is %.16lf\n",e);
	s2a=problem2(5);
	printf("第2題(a):%.16lf\n",s2a);
	s2b=problem2(20);
	printf("第2題(b):%.16lf\n",s2b);
	printf("第2題(c):\n\t(a)小題與Euler number的誤差為%.16lf\n",s2a-e);
	printf("\t(b)小題與Euler number的誤差為%.16lf\n",s2b-e);

	double s3a,s3b;
	printf("pi is %.16lf\n",pi);
	s3a=problem3(20);
	printf("第3題(a):%.16lf\n",s3a);
	s3b=problem3(10000);
	printf("第3題(b):%.16lf\n",s3b);
	printf("第3題(c):\n\t(a)小題與pi的誤差為%.16lf\n",s3a-pi);
	printf("\t(b)小題與pi的誤差為%.16lf\n",s3b-pi);

	double s4a,s4b;
	s4a=problem4(20);
	printf("第4題(a):%.16lf\n",s4a);
	s4b=problem4(100);
	printf("第4題(b):%.16lf\n",s4b);
	printf("第4題(c):\n\t(a)小題與pi的誤差為%.16lf\n",s4a-pi);
	printf("\t(b)小題與pi的誤差為%.16lf\n",s4b-pi);

}
