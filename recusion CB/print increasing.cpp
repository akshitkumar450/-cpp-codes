#include<iostream>
using namespace std;

void printIncreasing(int n){
    if(n==1){
       cout<<n<<endl;
        return;
    } 
    printIncreasing(n-1);
    cout<<n<<endl;
    return;
    
}


int main(){
    int n; cin>>n;
    printIncreasing(n);
}
