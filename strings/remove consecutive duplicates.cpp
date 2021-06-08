#include <bits/stdc++.h>
using namespace std;
string removeConsecutiveCharacter(string S)
    {
        // code here.
        stack<char>st;
        int n=S.length();
        for(int i=0;i<n;i++){
            if(st.empty()==true){
                st.push(S[i]);
            } 
            // if the top of the stack is not equal to the curent element then push it to stack 
            // else just ignore that element
            else if (st.top()!=S[i]){
                    st.push(S[i]);
                }
            }
        
        
        string temp="";
        while(st.empty()==false){
            char top=st.top();
            st.pop();
            temp+=top;
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
int main() {
	string S="aabb";
	cout<<removeConsecutiveCharacter(S);
	return 0;
}