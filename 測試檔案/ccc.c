#include<stdio.h>
main(){
	int a,b,j,min,max;
	printf("Input:" );
		scanf("%d",&a);
		max=a;
		min=a;
	do{
		printf("Input:" );
		scanf("%d",&b);
		if(max<b) max=b;
		if(min>b) min=b;

	} while ( a!=0&&b!=0 ) ;
	printf("Max:%d\nMin:%d\n",max,min);
}
