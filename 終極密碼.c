#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Guess(int x,int max,int min){
    int n;
    printf("請輸入數字：");
    scanf("%d",&n);

    if(min>n || max<n){
        printf("輸入不合法，請輸入落在%d ~ %d中的數字，",min, max);
        return Guess(x,max,min);
    }
    if(n==x) {
            printf("恭喜猜對，終極密碼為%d",x);
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
    printf("此遊戲為終極密碼\n");
    printf("請輸入想猜 1~?：");

    int min=1,max=1;
    scanf("%d",&max);
    srand(time(NULL));
    printf("Range is %d ~ %d\n",min,max);
    int x=rand()%(max-min+1)+min;// x is 隨機數//

    printf("以建立隨機數x，");

    Guess(x,max,min);
    re();


}

int re(){
    printf("\n輸入 1 重新開始遊戲\n");
    printf("輸入 其他 則結束遊戲\n");
    printf("輸入：");
    int r;
    scanf("%d",&r);
    printf("\n");
    if(r==1) return start();


}

int main(){
    start();



}

