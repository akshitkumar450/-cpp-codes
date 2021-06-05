#include <bits/stdc++.h>
using namespace std;

void print(int mat[3][3], int n ,int m ){
    int temp[n*m]; // create a temp array
    int k=0;
    //  copy all elements of matrix to temp array
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp[k++]=mat[i][j];
        }
    }
    
    // sort it
    sort(temp,temp+k);
    k=0;
    // copy back all the elements back to matrix
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mat[i][j]=temp[k++];
        }
    }
    
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
}


 vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
         vector<int>v;
         int n=Mat.size();
         int m=Mat.size();
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v.push_back(Mat[i][j]);
        }
    }
    
    sort(v.begin(),v.end());
    k=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            Mat[i][j]=v[k++];
        }
    }
    return Mat;
    }
int main() {
     int n,m;
    cin>>n>>m;
	  int mat[3][3] = { { 5, 4, 7 },
                            { 1, 3, 8 },
                            { 2, 9, 6 } };
   
    print(mat,n,m);
	return 0;
}