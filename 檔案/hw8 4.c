#include <stdio.h>
int main(){

int n;
while(scanf("%d",&n)!=EOF){
printf("f:");
    int last[n+1],k;
    k=n;

    for(int i=0;i<=n;i++)
        last[i]=i;

        if(n==1) printf("%d\n",last[1]);
        else {
            for(int j=0,i;j<k-1;j++,i=2){

        for(int i=2;i<=n;i++)
         last[i-1]=last[i];
         last[n]=last[1];
         n--;
         for(int i=2;i<=n+1;i++)
         last[i-1]=last[i];
            }
            if(n==1)printf("%d\n",last[1]);}
            printf("-------------------------\n");
        }

return 0;
}
