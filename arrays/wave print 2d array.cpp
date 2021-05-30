#include <iostream>
using namespace std;
int main() {
      int arr[100][100]={0};
    int m,n;
    cin>>m>>n;
    int val=1;
     for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            arr[i][j]=val;
            val++;
            // cin>>arr[i][j];
        }
    }

    for(int col=0;col<n;col++) {
        if(col%2==0) {
            // even col  top to bottom
            for(int row=0;row<m;row++) {
                cout<<arr[row][col]<<" ";
            }
        }
        else {
            // odd col bottom top top
            for(int row=m-1;row>=0;row--){
                cout<<arr[row][col]<<" ";
            }
        }
    } 


}
