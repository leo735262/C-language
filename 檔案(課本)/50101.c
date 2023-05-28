#include <stdio.h>
#include<ctype.h>
int main()
{
    char c;
    while (scanf("%c",&c)!=EOF)
    {
        if(isupper(c))
            c=tolower(c);
        else
            c=toupper(c);

        printf("%c",c);
    }
}

 /*   FILE *fp;
    fp=fopen("text.txt", "w");
    char s[10250];
    while (fgets(s, 1025, stdin)!=NULL)
    {
        for (int i=0; i<1025; i++)
        {
            if(isupper(s[i]))
                s[i]=tolower(s[i]);
            else
                s[i]=toupper(s[i]);
        }
        fputs(s, fp);
    }
    fclose(fp);
    return 0;*/
