#include <bits/stdc++.h>
using namespace std;

int main() {

int mat[4][5] = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9},
            };
    for(int i=0;i<4;i++){
        sort(mat[i],mat[i]+5);
    }
    
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}