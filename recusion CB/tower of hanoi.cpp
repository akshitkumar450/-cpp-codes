#include <iostream>
using namespace std;

void toh(int n,int src,int dest,int help ){
    if(n==0) return;
    
    toh(n-1,src,help,dest);
    cout<<"moving "<<n<<" from "<<src<<" to "<<dest<<endl;
    toh(n-1,help,dest,src);
}


int main() {
	int n,n1,n2,n3;
	cin>>n>>n1>>n2>>n3;
	toh(n,n1,n2,n3);
	return 0;
}