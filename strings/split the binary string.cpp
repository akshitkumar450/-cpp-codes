#include <bits/stdc++.h>
using namespace std;

int countSubstring(string &str){
    // maintain counts for 1 and 0
    // if the counts of 1 and 0 become equal and increment the count
    int c1=0,c0=0;
    int cnt=0;
    
    for(int i=0;i<str.length();i++){
        if(str[i]=='0'){
            c0++;
        } else if(str[i]=='1'){
            c1++;
        }
        if(c0==c1){
            cnt++;
        }
    }
    // split is not possible
    if(cnt==0){
        return -1;
    } 
    else 
    return cnt;
}

int main() {
	string str="000";
	cout<<countSubstring(str);
	return 0;
}