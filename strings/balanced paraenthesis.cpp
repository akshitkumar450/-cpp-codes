#include <bits/stdc++.h>
using namespace std;
bool validPara(string &str){
    stack<char>st;
    char top;
    for(int i=0;i<str.length();i++){
        if(str[i]=='{' || str[i]=='(' || str[i]=='['){
            st.push(str[i]);
        } 
        else if(str[i]=='}' || str[i]==')' || str[i]==']'){
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
    // to check whether at end elements are present or not
    return (st.empty());
}

int main() {
 string str = "{()}[]";
 if(validPara(str)){
     cout<<"balanced";
    
 }
 else{
        cout<<"not ";
    }
 
	return 0;
}