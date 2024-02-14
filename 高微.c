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
	printf("��1�D(a):%.16lf\n",s1a);
	s1b=problem1(100);
	printf("��1�D(b):%.16lf\n",s1b);

	double s2a,s2b,e=exp(1);
	printf("Euler number is %.16lf\n",e);
	s2a=problem2(5);
	printf("��2�D(a):%.16lf\n",s2a);
	s2b=problem2(20);
	printf("��2�D(b):%.16lf\n",s2b);
	printf("��2�D(c):\n\t(a)�p�D�PEuler number���~�t��%.16lf\n",s2a-e);
	printf("\t(b)�p�D�PEuler number���~�t��%.16lf\n",s2b-e);

	double s3a,s3b;
	printf("pi is %.16lf\n",pi);
	s3a=problem3(20);
	printf("��3�D(a):%.16lf\n",s3a);
	s3b=problem3(10000);
	printf("��3�D(b):%.16lf\n",s3b);
	printf("��3�D(c):\n\t(a)�p�D�Ppi���~�t��%.16lf\n",s3a-pi);
	printf("\t(b)�p�D�Ppi���~�t��%.16lf\n",s3b-pi);

	double s4a,s4b;
	s4a=problem4(20);
	printf("��4�D(a):%.16lf\n",s4a);
	s4b=problem4(100);
	printf("��4�D(b):%.16lf\n",s4b);
	printf("��4�D(c):\n\t(a)�p�D�Ppi���~�t��%.16lf\n",s4a-pi);
	printf("\t(b)�p�D�Ppi���~�t��%.16lf\n",s4b-pi);

}
