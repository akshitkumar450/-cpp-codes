#include<iostream>
using namespace std;

int power(int x,int n){
   if(n==0) return 1;
   int pnm1=power(x,n-1);
   int pn=x*pnm1;
   return pn;

}


int main(){
    int n,x; cin>>x>>n;
    cout<<power(x,n);
}
