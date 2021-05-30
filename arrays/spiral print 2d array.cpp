#include <iostream>
using namespace std;


void spiralPrint(int arr[][100],int m,int n) {
     int startRow=0;
     int startCol=0;
     int endRow=m-1;
     int endCol=n-1;

     while(startRow<=endRow && startCol <=endCol) {
        //  first row
        for(int i=startCol;i<=endCol;i++) {
            cout<<arr[startRow][i]<<" ";
        }
        startRow++;
        
        // end col
        for(int i=startRow;i<=endRow;i++) {
            cout<<arr[i][endCol]<<" ";
        }
        endCol--;
        
        // end row
        if(startRow<endRow) {
            for(int i=endCol;i>=startCol;i--) {
            cout<<arr[endRow][i]<<" ";
        }
         endRow--;
        }
     
        //first col
        if(startCol<endCol){
            for(int i=endRow;i>=startRow;i--) {
            cout<<arr[i][startCol]<<" ";
        }
        startCol++;
        }
        
     }
}

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
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    } 

    spiralPrint(arr,m,n);


}
