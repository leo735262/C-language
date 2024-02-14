#include<stdio.h>
#include<assert.h>
#include <string.h>
main()
{
    FILE *fp1=fopen("input1.txt","r");
    assert(fp1!=NULL);
    FILE *fp2=fopen("input2.txt","r");
    assert(fp2!=NULL);
    FILE *fp3=fopen("output.txt","w");
    assert(fp3!=NULL);

    int C;
    while((C=fgetc(fp1))!=EOF){
        if(C=='\n'){
            fputc(' ',fp3);
            while((C=fgetc(fp2))!='\n'){
                fputc(C,fp3);
            }
        }
        fputc(C,fp3);
    }


    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}
