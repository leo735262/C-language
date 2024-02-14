#include<stdio.h>
int main(){

int N,M,passwordnumber;

scanf("%d%d",&N,&M);
char password[N][M+1];

for(int i=0;i<N;i++){
    scanf("%s",&password[i]);
}

scanf("%d",&passwordnumber);

char key='a'+passwordnumber;
for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
            if(password[i][j]==key&&password[i][j+1]==NULL){
            printf("%s",password[i]);
    }

}
