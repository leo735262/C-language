
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
        printf("�̤j���]�Ƭ� %d\n",b);
    else
        printf("�̤j���]�Ƭ� %d\n",a);
}
int main(void) {
    int a,b;

    printf("�п�Ja,b�D�̤j���]��:");
    scanf("%d %d",&a,&b);
    t(a,b);
    return 0;
}
