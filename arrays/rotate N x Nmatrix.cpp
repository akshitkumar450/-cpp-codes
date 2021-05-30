#include <iostream>
#include <algorithm>
using namespace std;

void rotate(int arr[][100],int m) {
    // reverse each row
      for(int i=0;i<m;i++) {
       int startCol=0;
       int endCol=m-1;
       while(startCol<endCol) {
           swap(arr[i][startCol],arr[i][endCol]);
           startCol++;
           endCol--;
       }
    }

      //    take transpose
      for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            if(i<j) //to upper triangle only
            swap(arr[i][j],arr[j][i]);
        }
    }
}

void rotateSTL(int arr[][100],int m) {
    // reverse each row
      for(int i=0;i<m;i++) {
       reverse(arr[i],arr[i]+m);
      }
    //    take transpose
      for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            if(i<j) //to upper triangle only
            swap(arr[i][j],arr[j][i]);
        }
    }
    
}
int main() {
    int arr[100][100];
    int m; //sqaure matrix
    cin>>m;
    int val=1;
    for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            // cin>>arr[i][j];
            arr[i][j]=val;
            val++;
        }
    }

    rotate(arr,m);
    // rotateSTL(arr,m);

      for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}
