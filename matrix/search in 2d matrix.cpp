#include <iostream>
using namespace std;

bool search(int mat[4][4],int n,int m,int sum){
    if(n==0) return false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==sum){
                cout<<i<<" "<<j;
                return true;
            }
        }
    }
    return false;
}
//  GFG question approach
// array is sorted row wise and column wise
bool search2(int mat[4][4],int n,int m,int sum){
    if(n==0) return false;
    
    int i=0,j=m-1;
    while(i<n && j>=0){
        if(mat[i][j]==sum){
            cout<<i<<" " <<j;
            return true;
        } else if(mat[i][j]>sum){
            j--;
        } else i++;
    }
    return false;
}

// leetcode question approach
//  Integers in each row are sorted from left to right.
//    The first integer of each row is greater than the last integer of the previous row.

// using binary search
bool search3(int mat[4][4],int n,int m,int sum){
    if(n==0) return false;
    int low=0;
    int high=(n*m)-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(mat[mid/m][mid%m]==sum){
            cout<<mid/m<<" "<<mid%m;
            return true;
        } else if(mat[mid/m][mid%m]>sum){
            high=mid-1;
        } else{
            low=mid+1;
        }
    }
    return false;
}

int main() {
	    int mat[4][4] = { { 10, 20, 30, 40 },
                      { 15, 25, 35, 45 },
                      { 27, 29, 37, 48 },
                      { 32, 33, 39, 50 } };
        
        int n,m;
        cin>>n>>m;
        int sum;
        cin>>sum;
       if(search2(mat, n,m, sum)){
           cout<<"present";
       } else {
           cout<<"no";
       }
	return 0;
}