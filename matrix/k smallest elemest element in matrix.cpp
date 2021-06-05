#include <bits/stdc++.h>
using namespace std;

// min heap solution
int kthSmallest(int mat[][4],int n ,int k){
    priority_queue<int, vector<int> ,greater<int> >pq;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pq.push(mat[i][j]);
        }
    }
    for(int i=1;i<k;i++){
        int top=pq.top();
        pq.pop();
    }
    // cout<<pq.top();
    return pq.top();
    
}
// min heap
    int kthSmallest(vector<vector<int>>& mat, int k) {
    priority_queue<int, vector<int> ,greater<int> >pq;
        int n=mat.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pq.push(mat[i][j]);
        }
    }
    for(int i=1;i<k;i++){
        int top=pq.top();
        pq.pop();
    }
    // cout<<pq.top();
    return pq.top();


    }
// max heap solution
  int kthSmallest(vector<vector<int>>& matrix, int k) {
        // vector<int> values;
        priority_queue<int> pq;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix.size(); j++) {
                pq.push(matrix[i][j]);
            }
        }
        
        while(pq.size() != k) {
            int q = pq.top();
            pq.pop();
        }
        
        return pq.top();
    }
int main() {
	int mat[4][4] = {
        { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 25, 29, 37, 48 },
        { 32, 33, 39, 50 },
    };
    cout << "7th smallest element is "
         << kthSmallest(mat, 4, 7);
	return 0;
}