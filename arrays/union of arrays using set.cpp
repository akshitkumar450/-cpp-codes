#include <bits/stdc++.h>
using namespace std;

void getUnion(int a[],int n,int b[],int m) {
    set<int>s; // set contains distinct elements in set;
    for(int i=0;i<n;i++) {
        s.insert(a[i])
    }
    for(int i=0;i<m;i++) {
        s.insert(b[i])
    }
    cout<<" elements in union is "<<s.size()<<endl;
    for(auto it=s.begin();it!=s.end();it++) {
        cout<<*it;
    }
}

int main() {
   int a[9] = { 1, 2, 5, 6, 2, 3, 5, 7, 3 };
    int b[10] = { 2, 4, 5, 6, 8, 9, 4, 6, 5, 4 };
 
    getUnion(a, 9, b, 10);
}
