#include<stdio.h>
float *Optimal_BST(float p[],float q[],int n){
    float e[7][6]={0};
    float w[7][6]={0};
    int root[6][6]={0};
    float t=0;
    float re[2]={0};
    int j=0;

    for(int i=0;i<=n+1;i++){
        e[i][i-1]=q[i];
        w[i][i-1]=q[i];
    }

    for(int l=1;l<=n;l++){
        for(int i=1;l<=n-l+1;i++){
            j=i+l-1;
            e[i][j]=1000000;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            for(int r=i;i<=j;r++){
                t=e[i][r-1]+e[r+1][j]+w[i][j];
                if(t<e[i][j]){
                    e[i][j]=t;
                    root[i][j]=r;
                }
            }
        }
    }

    re[0]=e[1][n];
    re[1]=root[1][n];

    for(int i=0;i<7;i++){
        for(int k=0;k<6;k++){
            printf("%f",e[i][k]);
        }
    }

    return re;
}

int main(){
    float p[6]={0,0.15,0.1,0.05,0.1,0.2};
    float q[6]={0.05,0.1,0.05,0.05,0.05,0.1};
    int n=5;
    float *re;
     re=Optimal_BST(p,q,n);
     printf("%f",*re);
}
