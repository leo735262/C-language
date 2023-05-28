#include<stdio.h>
int main(){
int L,W,H,D;
scanf("%d%d%d%d",&L,&W,&H,&D);
int body,f,i;
body=H*W*L-(L-2*D)*(W-2*D)*(H-D);
f=W*L*2+(W+L)*2*H+((L-2*D)+(W-2*D))*2*(H-D);
i=(H-D)*(W-2*D)*(L-2*D);

printf("%d\n",body);
printf("%d\n",f);
printf("%d\n",i);
}
