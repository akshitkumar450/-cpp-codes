#include<iostream>
using namespace std;

// Input2 -> 3
// Output3 -> 3 2 1 1 1 2 1 1 1 2 3 2 1 1 1 2 1 1 1 2 3

void pzz(int n){
    if(n==0) return;
    cout<<n<<" ";
    pzz(n-1);
    cout<<n<<" ";
    pzz(n-1);
    cout<<n<<" ";
    
}

int main(){
    int n; cin>>n;
    pzz(n);
}
