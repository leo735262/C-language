#include<stdio.h>
#include<stdint.h>
#include <stdlib.h>
#define D 1000000007
#define K 500900139
#define pi 1005

long long int f(long long int p[pi][pi],int n,int k){

    if (p[n][k]!=0) return p[n][k];

    if (k==0) return p[n][k] =1;

    if (n<k) return p[n][k] =0;

    return p[n][k] =(f(p,n-1,k) +f(p,n-1,k-1)*k)%D;
}

int main()
{
    long long int p[pi][pi]={0};
    int n,k;
    while (scanf("%d%d",&n,&k) !=EOF)
    {
    printf("%lld\n", f(p, n, k));
    }
}

/*#include <stdio.h>
#include <stdlib.h>
#define N 1000

long long int PNK(long long int P[1001][1001], int n, int k)
{
    if (P[n][k]!=0)
        return P[n][k];
    if (k==0)
        return P[n][k] = 1;
    if (n < k)
        return P[n][k] = 0;
    return P[n][k] =(PNK(P, n-1, k) +PNK(P, n-1, k-1)*k)%1000000007;
}
int main()
{
    long long int P[1001][1001]={};
    int n, k;
    while (scanf("%d%d", &n, &k) !=EOF)
    {
    printf("%lld\n", PNK(P, n, k));
    }
    return 0;
}*/
