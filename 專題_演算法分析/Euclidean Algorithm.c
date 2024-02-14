
#include <stdio.h>

void t(int a,int b) {
    if( a == 0 || b == 0) {
        printf("Number can not be 0.\n");
        return;
    }
    while( a > 0 && b > 0 ) {

    if( a > b ){
        a = a % b;
        printf("a: %d\n",b);
    }
    else{
        b = b % a;
        printf("b: %d\n",b);
    }
}
    if( a == 0 )
        printf("程そ计 %d\n",b);
    else
        printf("程そ计 %d\n",a);
}
int main(void) {
    int a,b;

    printf("叫块a,b―程そ计:");
    scanf("%d %d",&a,&b);
    t(a,b);
    return 0;
}
