#include<stdio.h>
void quicksort(int A[],int p, int r){//快速排序法//

    if(p<r){

        int q=partition(A,p,r);
        //------------------------------
        printf("partition:%d",A[q]);

        printf("\n=>sort:");
        for(int i=0;i<p/2;i++)
            printf("\t  ");
        for(int i=p;i<=r;i++){
            if(i<r){
                printf("%d->",A[i]);
            }
            else printf("%d",A[i]);
        }
        printf("\n");

        //-------------------------------

        quicksort(A,p,q-1);

        quicksort(A,q+1,r);

    }

}

int partition(int A[],int p, int r){
    printf("(start:%d,end:%d)",p,r);
    int x=A[r];
    int i=p-1;
    int box;//exchang//

    for(int j=p; j<r; j++){
        if(A[j]<=x){
            i++;

            box=A[i];//exchange A[i] with A[j](把小於partition的數往又擺)//
            A[i]=A[j];
            A[j]=box;
        }
    }

    box=A[i+1];//exchange A[i+1] with A[r](把partition放在正確的位子)//
    A[i+1]=A[r];
    A[r]=box;

    return i+1;

}
void main(){
    //printf("請輸入想排序多少數字：");
    int n=8;
    //scanf("%d",&n);

    int A[]={2,8,7,1,3,5,6,4};
    //printf("\n請輸入想排序的數組：");

    /*for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }*/
    //------------------------------
    //A[0]=2; A[1]=8; A[2]=7; A[3]=1; A[4]=3; A[5]=5; A[6]=6; A[7]=4;

    printf("原：");
    for(int i=0;i<n;i++){
           //A[i]=10-i;
           if(i<n-1){
            printf("%d=>",A[i]);
           }
           else printf("%d",A[i]);
    }
    printf("\n");
    //------------------------------

    quicksort(A,0,n-1);

    for(int i=0;i<n;i++){
        printf("%d,",A[i]);
    }

}
