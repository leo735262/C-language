#include <iostream>
#include <cstdlib>
using namespace std;
int main(){

int n,n1;

cout<<"Test1\n";
cout<<"N:";
cin>>n;
cout<<"Test2\n";
cout<<"N:";
cin>>n1;
cout<<"Result1:";

    int last[n+1],k;
    k=n;

    for(int i=0;i<=n;i++)
        last[i]=i;

        if(n==1) cout<<last[1];
        else {
            for(int j=0,i;j<k-1;j++,i=2){

        for(int i=2;i<=n;i++)
         last[i-1]=last[i];
         last[n]=last[1];
         n--;
         for(int i=2;i<=n+1;i++)
         last[i-1]=last[i];
            }
            if(n==1)cout<<last[1];}

cout<<"\nResult2:";

    int last1[n1+1],k1;
    k1=n1;

    for(int i=0;i<=n1;i++)
        last1[i]=i;

        if(n1==1) cout<<last1[1];
        else {
            for(int j=0,i;j<k1-1;j++,i=2){

        for(int i=2;i<=n1;i++)
         last1[i-1]=last1[i];
         last1[n1]=last1[1];
         n1--;
         for(int i=2;i<=n1+1;i++)
         last1[i-1]=last1[i];
            }
            if(n1==1)cout<<last1[1];}

return 0;
}
