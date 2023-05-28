#include<stdio.h>
#include<assert.h>
main()
{
    int n,t=0,b[1000];
    while(scanf("%d",&n)!=EOF){
        assert(n<=9999);assert(n>=0);
        b[t]=n;
        t++;
    }


}
