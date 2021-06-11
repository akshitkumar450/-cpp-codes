#include <iostream>
using namespace std;

void printBrackets(char out[],int n,int idx,int open,int close){
    // if we have reached end i.e 2n size of array
    if(idx==2*n){
        out[idx]='\0';
        cout<<out<<endl;
        return;
    }
    // for putting (  bracket
    if(open<n){
        out[idx]='(';
        printBrackets(out,n,idx+1,open+1,close);
    }
    // for putting ) bracket
    if(close<open){
        out[idx]=')';
        printBrackets(out,n,idx+1,open,close+1);
    }
    return;
}

int main() {
    char out[100];
    int n;
    cin>>n;
    printBrackets(out,n,0,0,0);
	return 0;
}