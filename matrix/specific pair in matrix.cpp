#include <bits/stdc++.h>
using namespace std;

#define N 5

int findMaxValue(int mat[N][N]){
    int maxValue=INT_MIN;
    // make a new matrix of same size
    int matArr[N][N];
    
    // initialize the last value as same as in mat
    matArr[N-1][N-1]=mat[N-1][N-1];
    
    // preprocess the last row
    int maxv=mat[N-1][N-1];
    for(int j=N-2;j>=0;j--){
        if(mat[N-1][j]>maxv){
            maxv=mat[N-1][j];
        }
        matArr[N-1][j]=maxv;
    }
    
    // preprocess the last col
    maxv=mat[N-1][N-1];
    for(int i=N-2;i>=0;i--){
        if(mat[i][N-1]>maxv){
            maxv=mat[i][N-1];
        }
        matArr[i][N-1]=maxv;
    }
    
    // preprocess rest of the matrix
    for(int i=N-2;i>=0;i--){
        for(int j=N-2;j>=0;j--){
            if(matArr[i+1][j+1]-mat[i][j]>maxValue){
                maxValue=matArr[i+1][j+1]-mat[i][j];
            }
            // set the value
            matArr[i][j]=max(mat[i][j],max(matArr[i+1][j],matArr[i][j+1]));
        }
    }
    return maxValue;
}


int main() {
	  int mat[N][N] = {
                      { 1, 2, -1, -4, -20 },
                      { -8, -3, 4, 2, 1 },
                      { 3, 8, 6, 1, 3 },
                      { -4, -1, 1, 7, -6 },
                      { 0, -4, 10, -5, 1 }
                    };
    cout << "Maximum Value is "
         << findMaxValue(mat);
	return 0;
}