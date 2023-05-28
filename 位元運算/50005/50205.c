#include<stdio.h>
int main(){
unsigned long long int k,n,i;
while(scanf("%llu %d",&k,&i)!=EOF){
    unsigned long long int C=(n<<i)-1;
    C=k&C;
    k=k>>i;
    C=C<<(64-i);
    k=k|C;
    printf("%llu\n",k);
}
}
