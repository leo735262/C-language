#include<stdio.h>
main(void)
{
int T,N,A[64][64],B[64][64];
scanf("%d%d",&T,&N);

for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
    scanf("%d",A[i][j]);

for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
    scanf("%d",B[i][j]);

return 0
}
