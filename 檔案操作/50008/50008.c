#include<stdio.h>
#include<assert.h>
#include <string.h>
main()
{
    FILE *fp1=fopen("blue.bmp","rb");
    assert(fp1!=NULL);
    FILE *fp2=fopen("green.bmp","rb");
    assert(fp2!=NULL);
    FILE *fp3=fopen("red.bmp","rb");
    assert(fp3!=NULL);
    FILE *F=fopen("pokemon.bmp","wb");
    assert(F!=NULL);

    unsigned char f1,f2,f3,s;

    for(int i=0;i<54;i++){
    fscanf(fp1,"%c",&f1);
    fprintf(F,"%c",f1);
    }

    fclose(F);

    F=fopen("pokemon.bmp","ab");

    fseek( F ,54,SEEK_SET);
    fseek(fp1,54,SEEK_SET);
    fseek(fp2,54,SEEK_SET);
    fseek(fp3,54,SEEK_SET);

    while((fscanf(fp1,"%c",&f1))!=EOF){
    fscanf(fp2,"%c",&f2);
    fscanf(fp3,"%c",&f3);
    s=f1+f2+f3;
    fprintf(F,"%c",s);}

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(F);
}
