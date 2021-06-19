#include <iostream>
#include <stack>
using namespace std;

int precedence(char ch){
    if(ch=='+') return 1;
    else if(ch=='-') return 1;
    else if(ch=='*') return 2;
    else if(ch=='/') return 2;
}

int operation(int v1,int v2,char ch){
    if(ch=='+') return v1+v2;
    else if(ch=='-') return v1-v2;
    else if(ch=='*') return v1*v2;
    else if(ch=='/') return v1/v2;
}

int infix(string str){
    stack<int>oprnds;
    stack<char>oprtors;

    for(int i=0;i<str.length();i++){
        if(str[i]=='('){
            // if the ( then push in operators stack
            oprtors.push(str[i]);
        } else if(isdigit(str[i])){
            // if any digit push in operands stack
             oprnds.push(str[i]-'0');
        } else if(str[i]==')'){
            //  if ) pop till we find ( and solve the expression

            while(oprtors.top()!='('){
                int val2=oprnds.top(); oprnds.pop();
                int val1=oprnds.top(); oprnds.pop();
                char ch=oprtors.top(); oprtors.pop();

                int ans=operation(val1,val2,ch);
                // after solving push it back to operands
                oprnds.push(ans);
            }
            // after processing expression pop the (
            oprtors.pop();
            // pop with precedence
            // pop untill you find operator with lower precedence operator
        } else if(str[i]=='+' || str[i]=='-' || str[i]=='*' ||  str[i]=='/' ){
            while(!oprtors.empty() && oprtors.top()!='(' 
                        && precedence(str[i])<=precedence(oprtors.top())) {
                             int val2=oprnds.top(); oprnds.pop();
                            int val1=oprnds.top(); oprnds.pop();
                            char ch=oprtors.top(); oprtors.pop();

                            int ans=operation(val1,val2,ch);
                            oprnds.push(ans);
                    }
                    // push itself to operators
                    oprtors.push(str[i]);
        }
    }
    // at last if elements are there 
    // at end operators stack should be empty
    while(!oprtors.empty()){
         int val2=oprnds.top(); oprnds.pop();
        int val1=oprnds.top(); oprnds.pop();
        char ch=oprtors.top(); oprtors.pop();

        int ans=operation(val1,val2,ch);
        // after solving push it back to operands
        oprnds.push(ans);
    }
    // at end answer will be at top of operands stack
    return oprnds.top();
}




int main() {
   cout<< infix(" (2+4) * (4+6)");

   
}
