#include <iostream>
using namespace std;

int ladder(int n,int k){
    // if we are on the ground level
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    int ans=0;
    for(int i=1;i<=k;i++){
        ans=ans+ladder(n-i,k);
    }
    return ans;
}

int main() {
    //  n->ladders
    // k->steps 
	int n,k;
	cin>>n>>k;
	cout<<ladder(n,k);
	return 0;
}