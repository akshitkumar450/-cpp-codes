#include <bits/stdc++.h>
using namespace std;

#define M 4
#define N 5
// same as finding the common element in row wise sorted matrix
// O(mnlogn)

// basic approach
int commonelement(int mat[4][5]){
    // sort matrix row wise 
    for(int i=0;i<4;i++){
        sort(mat[i],mat[i]+5);
    }
    
    unordered_map<int,int> mp;
    for(int i=0;i<4;i++){
        mp[mat[i][0]]++;
        
        for(int j=1;j<5;j++){
            if(mat[i][j]!=mat[i][j-1]){
                mp[mat[i][j]]++;
            }
        }
    }
    
      for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second==M){
            return it->first;
        }
    }
    return -1;  
}
// O(mn)

void printCommonElements(int mat[M][N]){
    unordered_map<int,int> mp;
    // put element of the first row and value as 1
    for(int j=0;j<N;j++){
        mp[mat[0][j]]=1;
    }
    // traverse the matrix from second row and first col
    for(int i=1;i<M;i++){
        for(int j=0;j<N;j++){
            // if the current element is present in the map and not duplicating in the row
            if(mp[mat[i][j]]==i){
                mp[mat[i][j]]=i+1;
                //if it is the last row
                if(i==M-1 && mp[mat[i][j]]==M){
                    cout<<mat[i][j]<<" ";
                }
            }
        }
    }
}



int main() {

int mat[4][5] = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {5, 0, 2, 7, 9},
            };
    cout<<commonelement(mat);
}