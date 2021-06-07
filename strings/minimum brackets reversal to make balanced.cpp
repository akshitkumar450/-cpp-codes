#include <bits/stdc++.h>
using namespace std;

int countMinReversals(string &expr){
    int n=expr.length();
    // length should be even 
    if(n%2!=0){
        return -1;
    }
    stack<char>st;
    // remove balanced balanced patterm from the unbalanced pattern
    for(int i=0;i<n;i++){
        if(expr[i]=='}' and !st.empty()){
            if(st.top()=='{'){
                st.pop();
            } else {
                st.push(expr[i]);
            }
        } else{
            st.push(expr[i]);
        }
    }
        // after this loop stack will contain only non balanced part
    int reduced_len=st.size();
    int cnt=0;
    while(!st.empty() and st.top()=='{'){
        st.pop();
        cnt++;
    }
    return(reduced_len/2)+(cnt%2);
}
    
    
    
    

int main() {
string expr = "}}{{";
   cout << countMinReversals(expr);
	return 0;
}