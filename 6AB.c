#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char x[6];
char nn[6];

char Ran(int d){
    srand(time(NULL));
    int min=1,max=1,number;
    for(int i=1;i<d;i++)
        min=min*10;
    for(int i=0;i<d;i++)
        max=max*10;
    max--;
    printf("Range is %d ~ %d\n",min,max);
    number=rand()%(max-min+1)+min;

    //sprintf(x, "%d", number);
    int k=1;
    for(int i=0;i<6;i++,k=k*10){
        if(i==0) x[i]=(number/100000*k);
            else x[i]=(number/100000*k)-x[i-1]*k/10;
    }
printf("%s",x);
    return x;

}

char assert(int d){
    int n;
    scanf("%d",&n);

    int min=1,max=1;
    for(int i=1;i<d;i++)
        min=min*10;
    for(int i=0;i<d;i++)
        max=max*10;
    max--;
    // min=100000 max=999999 //

    //sprintf(nn, "%d", n);

    if(min>n || max<n){
        printf("輸入不合法，請輸入%d位數：",d);
        return assert(d);
    }
    else return nn;

}

int Guess(int n){
//for(int i=0;i<6;i++)
    //r(int j=0;j<6;j++)
    //printf("%s\n%s\n",nn[i],x[i]);

}


int main(){
    printf("此遊戲為猜6位數字AABB\n");
    //scanf("%d",&d);
    Ran(6);
    printf("已建立隨機數x，請猜數字：");
    assert(6);
    Guess(nn);
    printf("%d",x);




}
