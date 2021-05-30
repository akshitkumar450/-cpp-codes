#include <bits/stdc++.h>
using namespace std;
int main() {
        int A[] = { 1, 4, 45, 6, 10, -8 };
    int sum = 16;
    int n = sizeof(A) / sizeof(A[0]);

    unordered_set<int> s;
    for(int i=0;i<n;i++) {
        int temp=sum-A[i];
        if(s.find(temp)!=s.end()){
            cout<<sum <<" ("<<A[i]<<" "<<temp<<")";
        } else s.insert(A[i]);
    }
}
