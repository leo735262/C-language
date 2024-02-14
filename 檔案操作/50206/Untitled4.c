#include<stdio.h>
#include<assert.h>
main()
{
    FILE *fp1=fopen("input1.txt","r");
    assert(fp1!=NULL);
    FILE *fp2=fopen("input2.txt","r");
    assert(fp2!=NULL);
    FILE *fp3=fopen("output.txt","w");
    assert(fp3!=NULL);
    int c,C;
for(int i=0;i<100;i++)
    {
     if(i%2==0){
       c=fgetc(fp1);
       fputc(c,fp3);}

     if(i%2==1){
       C=fgetc(fp2);
       fputc(C,fp3);}
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}
