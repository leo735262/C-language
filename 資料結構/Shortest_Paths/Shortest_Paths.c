#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

#define Matrixsize 7
#define INT_MAX 10000000
int choose(int distance[],int n, bool found[]){
    int min,minpoint;
    min=INT_MAX;
    minpoint=-1;
    for(int i=0;i<n;i++){
        if(distance[i]<min && found[i]==false){
            min=distance[i];
            minpoint=i;
        }
    }
    return minpoint;

}

void shortestpath(int v,int cost[][Matrixsize],int dist[],int n,bool f[]){
    int u;

    for(int i=0;i<n;i++){//初始化
        f[i]=false;
        dist[i]=INT_MAX;
    }
    f[v]=true;
    dist[v]=0;

    for(int i=0;i<n-1;i++){
        u=choose(dist,n,f);
        f[u]=true;
        for(int w=0;w<n;w++){
            if(f[w]==false && cost[u][w]>'0'){
                if(dist[u]+(cost[u][w]-'0')<dist[w]){
                    dist[w]=dist[u]+(cost[u][w]-'0');
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("從頂點%d到頂點%d的最短距離為%d\n",v,i,dist[i]);
    }
}

int main(){
    char c[Matrixsize][Matrixsize]={'0'};
    char adjM[Matrixsize][Matrixsize]={'0'};
    int n=0,m=0;
    FILE *fp1=fopen("Matrix.txt","r");
    assert(fp1!=NULL);

    while((c[n][m]=fgetc(fp1))!=EOF){
        adjM[n][m]=c[n][m]-'0';
        printf("%d\n",c[n][m]);
        if(m==6){
            n++;
            m=0;
        }
    }

    int v,distance[Matrixsize],found[Matrixsize];
    printf("請輸入出發點：");
    scanf("%d",&v);
    shortestpath(v,c,distance,Matrixsize,found);
}
