#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Guess(int x,int max,int min){
    int n;
    printf("�п�J�Ʀr�G");
    scanf("%d",&n);

    if(min>n || max<n){
        printf("��J���X�k�A�п�J���b%d ~ %d�����Ʀr�A",min, max);
        return Guess(x,max,min);
    }
    if(n==x) {
            printf("���߲q��A�׷��K�X��%d",x);
            printf("\n");

    }

    if(n>x) {
            printf("Range is %d ~ %d\n",min,n-1);
            return Guess(x,n-1,min);
            }

    if(n<x) {
            printf("Range is %d ~ %d\n",n+1,max);
            return Guess(x,max,n+1);
    }


}


int start(){
    printf("���C�����׷��K�X\n");
    printf("�п�J�Q�q 1~?�G");

    int min=1,max=1;
    scanf("%d",&max);
    srand(time(NULL));
    printf("Range is %d ~ %d\n",min,max);
    int x=rand()%(max-min+1)+min;// x is �H����//

    printf("�H�إ��H����x�A");

    Guess(x,max,min);
    re();


}

int re(){
    printf("\n��J 1 ���s�}�l�C��\n");
    printf("��J ��L �h�����C��\n");
    printf("��J�G");
    int r;
    scanf("%d",&r);
    printf("\n");
    if(r==1) return start();


}

int main(){
    start();



}

