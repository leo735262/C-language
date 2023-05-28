#include<stdio.h>
#include<assert.h>

int tribon(int i){
    if(i==0)
        return 0;
    if(i==1||i==2)
        return 1;
    return(tribon(i-1)+tribon(i-2)+tribon(i-3));
}

main(){
    int n;
    while(scanf("%d",&n)!=EOF){
    assert(n>=0); assert(n<=30);
    printf("%d\n",tribon(n));

    }
}
