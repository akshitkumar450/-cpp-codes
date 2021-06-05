#include <bits/stdc++.h>
using namespace std;

#define M 4
#define N 5
// O(MN)
int findCommon(int mat[M][N]){
    unordered_map<int,int>mp;

    // increment the count of first element of each row
    for(int i=0;i<M;i++){
        mp[mat[i][0]]++;
        
        // starting from the second element of the current row
        // increment the count if current element is not equal to previous element
        for(int j=1;j<N;j++){
            if(mat[i][j]!=mat[i][j-1]) {
                mp[mat[i][j]]++;
            }
        }
    }
    
    // find the element having the count equal to rows
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second==M){
            return it->first;
        }
    }
    return -1;
}


int main() {
	  int mat[M][N] = {
        { 1, 2, 3, 4, 5 },
        { 2, 4, 5, 8, 10 },
        { 3, 5, 7, 9, 11 },
        { 1, 3, 5, 7, 9 },
    };
    int result = findCommon(mat);
     if (result == -1)
        cout << "No common element";
    else
        cout << "Common element is " << result;
 
	return 0;
}