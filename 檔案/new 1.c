#include<stdio.h>
int main(){
int n,m;
scanf("%d%d",&n,&m);
if(n==m)
    printf("%d",300);
if(n!=m && n%10==m%10){
        if(n/10==n%10)
    printf("%d",100); else  printf("%d",0);
}
if(n!=m && n/10==m/10){
        if(n/10==n%10)
    printf("%d",100); else  printf("%d",0);
}

if(n!=m && n%10==m/10 && n/10==m%10) printf("%d",0);
if(n!=m && n%10==m/10 || n/10==m%10 && n%10!=m%10) printf("%d",-100);

if(n!=m&& n%10!=m/10 && n/10!=m%10 && n%10!=m%10)printf("%d",-200);

}
