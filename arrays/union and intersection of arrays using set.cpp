#include <bits/stdc++.h>
using namespace std;

void getUnion(int a[],int n,int b[],int m) {
    set<int>s; // set contains distinct elements in set;
    for(int i=0;i<n;i++) {
        s.insert(a[i]);
    }
    for(int i=0;i<m;i++) {
        s.insert(b[i]);
    }
    // cout<<" elements in union is "<<s.size()<<endl;
    for(auto it=s.begin();it!=s.end();it++) {
        cout<<*it<<" ";
    }
}

void intersection(int a[],int n,int b[],int m) {
     set<int>s; // set contains distinct elements in set;
    for(int i=0;i<n;i++) {
        s.insert(a[i]);
    }
    for(int i=0;i<m;i++) {
        if(s.find(b[i])!=s.end()){
            cout<<b[i]<<" ";
        }
    }
}
int main() {
   int a[9] = { 7, 1, 5, 2, 3, 6 };
    int b[10] =  { 3, 8, 6, 20, 7 };
 
    getUnion(a, 6, b, 5);
    cout<<endl;
    intersection(a,6,b,5);
}
