#include<stdio.h>
#include<string.h>
#include<assert.h>
int main(){
FILE *ifptr=fopen("input.txt","r");
assert(ifptr!=NULL);
FILE *ofptr=fopen("output.txt","w");
assert(ofptr!=NULL);

int k=0,t=1;
char A[999];
fscanf(ifptr,"%d",&k);

while(fgets(A,999,ifptr)!=NULL){
    switch (A[k+1]){

    case '|':
        for(int i=0;i<k;i++){
            if((A[i]=='1')||(A[k+i+3]=='1'))
            A[i]='1';
            else A[i]='0';
        }
        A[k]='\n';A[k+1]='\0';
        fputs(A,ofptr);
    break;

    case '&':
        for(int i=0;i<k;i++){
            if((A[i]=='1')&&(A[k+i+3]=='1'))
            A[i]='1';
            else A[i]='0';
        }
        A[k]='\n';A[k+1]='\0';
        fputs(A,ofptr);
    break;

    case '^':
        for(int i=0;i<k;i++){
            if(((A[i]=='1')&&(A[k+i+3]=='0'))||((A[i]=='0')&&(A[k+i+3]=='1')))A[i]='1';
            else A[i]='0';

        }
        A[k]='\n';A[k+1]='\0';
        fputs(A,ofptr);
        break;
    }
}
    fclose(ifptr);
    fclose(ofptr);
}
