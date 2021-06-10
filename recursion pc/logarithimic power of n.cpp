#include<iostream>
using namespace std;

int powerLogarithmic(int x,int n){
    if(n==0) return 1;
    int pn2=powerLogarithmic(x,n/2);
    int pn=pn2*pn2;
    
    // if the number is odd
    if(n%2!=0){
        pn=x*pn;
    }
    return pn;
}

int main(){
    int x,n; cin>>x>>n;
    cout<<powerLogarithmic(x,n);
}