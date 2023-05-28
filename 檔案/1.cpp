#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cout << "n:";
    cin >> n;
    int arr[2][n],s[n]={0},t=0,c[2][n]={0},k=0;
    
    cout << "Peter\n";
    
    for(int i=0; i<n; i++) {
        cout << "Input:";
        cin >> arr[0][i];
    }
    
    cout << "Tom\n";
    for(int i=0; i<n; i++) {
        cout << "Input:";
        cin >> arr[1][i];
    }
    
    cout << "Peter:";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if (arr[0][i] == arr[1][j]) {
             s[t]=arr[0][i];
             t++;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if (arr[0][i] == s[j]) {
                arr[0][i]=-1;
            }
        }
    }
    for(int i=0;i<n;i++)
       if(arr[0][i]!=-1){
       	c[0][k]=arr[0][i];
       	k++;
	   }
	   for(int i=0;i<k-1;i++)
           cout<<c[0][i]<< " ";
           cout<<c[0][k-1];
           cout<<endl;
           k=0;
    cout << "Tom:";
        for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if (arr[1][i] == s[j]) {
                arr[1][i]=-1;
            }
        }
    }
    for(int i=0;i<n;i++)
       if(arr[1][i]!=-1){
       	c[1][k]=arr[1][i];
       	k++;
	   }
	   for(int i=0;i<k-1;i++)
           cout<<c[1][i]<< " ";
           cout<<c[1][k-1];
           
    
    
    return 0;
}
