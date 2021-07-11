#include <bits/stdc++.h>
using namespace std;

void substring(string &str){
    int n=str.length();
    for (int i = 0; i < n; i++) {
        for(int len=1;len<=n-i;len++){
            cout<<str.substr(i,len)<<endl;
        }
    }
}

int main() {
    string str="abc";
    substring(str);
	return 0;
}