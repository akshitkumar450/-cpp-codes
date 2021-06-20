#include <iostream>
#include <stack>
using namespace std;

int precedence(char ch){
    if(ch=='+') return 1;
    else if(ch=='-') return 1;
    else if(ch=='*') return 2;
    else if(ch=='/') return 2;
}

void infix(string str){
    stack<string>prefix;
    stack<string>postfix;
    stack<char>oprtors;

    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(ch=='('){
            // if the ( then push in operators stack
            oprtors.push(ch);
        } else if((ch>='a' and ch<='z') or 
                  (ch>='A' and ch<='Z') or 
                  (ch>='0' and ch<='9')) {
            // if any digit push in operands stack
             prefix.push(ch+"");
             postfix.push(ch+"");
        } else if(ch==')'){
            //  if ) pop till we find ( and solve the expression

            while(oprtors.top()!='('){
                char op=oprtors.top(); oprtors.pop();
                string post2=postfix.top(); postfix.pop();
                string post1=postfix.top(); postfix.pop();
                string anspost=post1+post2+op;
                postfix.push(anspost);
 
                string pre2=prefix.top(); prefix.pop();
                string pre1=prefix.top(); prefix.pop();
                string anspre=op+pre1+pre2;
                prefix.push(anspre);
            }
            // after processing expression pop the (
            oprtors.pop();
            // pop with precedence
            // pop untill you find operator with lower precedence operator
        } else if(ch=='+' || ch=='-' || ch=='*' ||  ch=='/' ){
            while(!oprtors.empty() && oprtors.top()!='(' 
            // if my precedence is smaller than in stack pop it
                        && precedence(ch)<=precedence(oprtors.top())) {
                                char op=oprtors.top(); oprtors.pop();
                                string post2=postfix.top(); postfix.pop();
                                string post1=postfix.top(); postfix.pop();
                                string anspost=post1+post2+op;
                                postfix.push(anspost);

                                string pre2=prefix.top(); prefix.pop();
                                string pre1=prefix.top(); prefix.pop();
                                string anspre=op+pre1+pre2;
                                prefix.push(anspre);
                    }
                    // push itself to operators
                    oprtors.push(ch);
        }
    }
    // at last if elements are there 
    // at end operators stack should be empty
    while(!oprtors.empty)
           char op=oprtors.top(); oprtors.pop();
            string post2=postfix.top(); postfix.pop();
            string post1=postfix.top(); postfix.pop();
            string anspost=post1+post2+op;
            postfix.push(anspost);

            string pre2=prefix.top(); prefix.pop();
            string pre1=prefix.top(); prefix.pop();
            string anspre=op+pre1+pre2;
            prefix.push(anspre);
    }
    // at end answer will be at top of operands stack
    cout<<prefix.top()<<endl;
    cout<<postfix.top()<<endl;
}




int main() {
   infix(" (2+4) * (4+6)");

   
}
