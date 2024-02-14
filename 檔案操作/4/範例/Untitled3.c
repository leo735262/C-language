#include<stdio.h>
#include<assert.h>
main(void)
{
FILE *fp1=fopen("file1","w");
assert(fp1!=NULL);
for(int i=0;i<10;i++)
    fputc('1',fp1);
fclose(fp1);

FILE *fp2=fopen("file2","w");
assert(fp2!=NULL);
for(int i=0;i<20;i++)
    fputc('2',fp2);
fclose(fp2);
//1.2¿é¤J§¹¤F//

fp1=fopen("file1","r");
assert(fp1!=NULL);
fp2=fopen("file2","w");
assert(fp2!=NULL);
//open 1 2//

int c;
while((c=fgetc(fp1))!=EOF)
    fputc(c,fp2);
fclose(fp1);
fclose(fp2);

fp2=fopen("file2","r");
assert(fp2!=NULL);
while((c=fgetc(fp2))!=EOF)
    fputc(c,stdout);
fclose(fp2);
return 0;
}
