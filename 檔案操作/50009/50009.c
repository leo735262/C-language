#include<stdio.h>
#include<assert.h>
#include <string.h>
main()
{
    FILE *ifp=fopen("input.bmp","rb");
    assert(ifp!=NULL);
    FILE *ofp=fopen("output.bmp","wb");
    assert(ofp!=NULL);

    int t;
    char s[50];
    char *p[]={"LEFTRIGHT","UPDOWN","ROTATE90","ROTATE180","ROTATE270"};
    fscanf(stdin,"%s",&s);
    for(int i=0;i<5;i++){
        if(strcmp(s,p[i])==0)
            t=i;
     }

    char c;
    for(int i=0;i<54;i++){
        fscanf(ifp,"%c",&c);
        fprintf(ofp,"%c",c);
   }

    char d[475][1900];
    for(int i=0;i<475;i++){
        for(int j=0;j<1900;j++)
             fscanf(ifp,"%c",&d[i][j]);
    }
    char sp[475][1900];

     switch(t){

        case 0:
        for(int i=0;i<475;i++){
            for(int j=0,k=1896;j<1900;j+=4,k-=4){
                for(int w=0;w<4;w++)
                  sp[i][j+w]=d[i][k+w];
            }
        }
       for(int i=0;i<475;i++){
           for(int j=0;j<1900;j++)
             fprintf(ofp,"%c",sp[i][j]);
       }
       break;

       case 1:
       for(int i=0,j=474;i<475;i++,j--){
            for(int k=0;k<1900;k++)
              sp[i][k]=d[j][k];
       }
       for(int i=0;i<475;i++){
        for(int j=0;j<1900;j++)
             fprintf(ofp,"%c",sp[i][j]);

        }
       break;

       case 2:
       for(int i=0;i<475;i++){
           for(int j=0;j<1900;j++)
            sp[i][j]=d[j/4][1896+j%4-4*i];
       }
       for(int i=0;i<475;i++){
           for(int j=0;j<1900;j++)
             fprintf(ofp,"%c",sp[i][j]);
       }
       break;

       case 3:
       for(int i=0;i<475;i++){
           for(int j=0;j<475;j++){
               for(int k=0;k<4;k++)
                sp[i][j*4+k]=d[474-i][1896-j*4+k];
            }
       }
       for(int i=0;i<475;i++){
           for(int j=0;j<1900;j++)
             fprintf(ofp,"%c",sp[i][j]);
       }
       break;

       case 4:
       for(int i=0;i<475;i++){
            for(int k=0;k<1900;k++)
              sp[i][k]=d[474-(k/4)][k%4+i*4];
       }
       for(int i=0;i<475;i++){
           for(int j=0;j<1900;j++)
             fprintf(ofp,"%c",sp[i][j]);

        }
        break;
     }
    fclose(ifp);
    fclose(ofp);
}
