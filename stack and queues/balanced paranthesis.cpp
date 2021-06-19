#include <bits/stdc++.h>
using namespace std;

bool balanced(string &str) {
    stack<char>st;
    char top;
    for(int i=0;i<str.length();i++){
        // if any opening bracket then push it 
        if(str[i]=='{' || str[i]=='(' || str[i]=='['){
            st.push(str[i]);
        } 
        // if any closing bracket then check it with most recent opening bracket in stack
        else if(str[i]=='}' || str[i]==')' || str[i]==']'){
            // means we have not found the opening bracket for the current closing bracket
            // return false
            // ){}[]()
            if(st.empty()){
                return false;
            }
            switch(str[i]){
                case '}':
                    top=st.top();
                    st.pop();
                    if(top!='{') return false;
                break;
    
                case ')':
                    top=st.top();
                    st.pop();
                    if(top!='(') return false;
                break;
                
                case ']':
                     top=st.top();
                    st.pop();
                    if(top!='[' ) return false;
                    
                break;
            }
        }
    }
    // to check whether at end elements are left or not
    // if elements are left means not balanced return false else return true
    return (st.empty());
}

int main() {
    string str = "{()}[]";
    if(balanced(str)){
        cout<<"balanced";
    } else{
            cout<<"not ";
    }
        return 0;
}