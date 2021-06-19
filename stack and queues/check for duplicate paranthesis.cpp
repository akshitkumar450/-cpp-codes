#include <iostream>
#include<stack>
using namespace std;

bool duplicatePara(string str){
    stack<char>st;
    for(int i=0;i<str.length();i++){
        // push every element other than )
        if(str[i]!=')'){
            st.push(str[i]);
        } else {
            // if we find the ) at top of stack means there is not expression between those brackets
            // means there is duplicate brackets
            if(st.top()=='(') return true;
            // else we have a expression betweem brackets 
            // pop till we find (
            while(st.top()!='('){
                st.pop();
            }
            // then pop (
            st.pop();
        }
    }
    return false;
}

int main() {
	cout<<duplicatePara("((a+b)+c)")<<endl;
	return 0;
}