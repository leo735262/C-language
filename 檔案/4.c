#include<stdio.h>
int Square_star(int s)
{
scanf("%d",&s);
for(int i=0;i<s;i++){
    for(int j=0;j<s;j++)
        printf("*");
        printf("\n");}
return 0;
}
//以上是印出正方形//

int Triangle_follow(int f)
{
scanf("%d",&f);
for(int i=0;i<f;i++){
    for(int j=0;j<=i;j++)
        printf("*");
        printf("\n");}
return 0;
}
//以上是印出正三角形//

int Triangle_reverse(int r)
{
scanf("%d",&r);
for(int i=r;i>0;i--){
    for(int j=0;j<i;j++)
        printf("*");
        printf("\n");}
    return 0;
}
//以上是印出倒三角形//

int Triangle_plus(int p)
{
int t,o=1;
scanf("%d",&p);
t=p;
for(int i=1;i<=p/2+1;i++){
    {

    for(int k=0;k<t/2;k++)
    printf(" ");

    for(int k=0;k<o;k++)
    printf("*");

    for(int k=0;k<t/2;k++)
    printf(" ");
    t=t-2;
    o=o+2;
    printf("\n");
    }

}
return 0;
}
int Triangle_plus_reverse(int pr){
    int t1,o1=1;
scanf("%d",&pr);
t1=pr;
for(int i=1;i<=pr/2+1;i++){
    {

    for(int k=0;k<t1/2;k++)
    printf(" ");

    for(int k=0;k<o1;k++)
    printf("*");

    for(int k=0;k<t1/2;k++)
    printf(" ");
    t1=t1-2;
    o1=o1+2;
    printf("\n");
    }
}
return 0;
}



int Triangle_plus_asp(int p)
{
int t,o=1;
scanf("%d",&p);
t=p*2-1;
for(int i=1;i<=p;i++){
    {

    for(int k=0;k<t/2;k++)
    printf(" ");

    for(int k=0;k<o;k++)
    printf("*");

    for(int k=0;k<t/2;k++)
    printf(" ");
    t=t-2;
    o=o+2;
    //if(i==p)break;
    printf("\n");
    }


}
return 0;
}
//以上是印出倒三角形//

int Square_hole_1(int sh){
scanf("%d",&sh);
for(int i=0;i<sh;i++){
if(i==0||i==sh-1){
    for(int j=0;j<sh;j++)
    printf("*");
    printf("\n");
}
else{
    printf("*");
    for(int k=0;k<sh-2;k++)
        printf(" ");
    printf("*");
    printf("\n");
}

}

}

int Square_hole_2(int sh2){
scanf("%d",&sh2);
for(int i=0;i<sh2;i++){
if(i==0||i==1||i==sh2-2||i==sh2-1){
    for(int j=0;j<sh2;j++)
    printf("*");
    printf("\n");
}
else{
    printf("*");
    printf("*");
    for(int k=0;k<sh2-4;k++)
        printf(" ");
    printf("*");
    printf("*");
    printf("\n");
}

}

}
int main(void){
    int s,f,r,p,pr,sh,sh2;
   // Square_star(s);
    //Triangle_follow(f);
   // Triangle_reverse(r);
    Triangle_plus_asp(p);
  // Triangle_plus_reverse(pr);
  // Square_hole_1(sh);
 // Square_hole_2(sh2);

}

