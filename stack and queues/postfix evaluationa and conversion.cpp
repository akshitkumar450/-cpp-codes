#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int operation(int v1,int v2,char ch){
    if(ch=='+') return v1+v2;
    else if(ch=='-') return v1-v2;
    else if(ch=='*') return v1*v2;
    else if(ch=='/') return v1/v2;
}

void postfix(string str){
    stack<string>prefix;
    stack<string>infix;
    stack<int>value;
    for (int i = 0; i < str.length(); i++) {
        char ch=str[i];
        if(ch=='+' || ch=='-' || ch=='*' ||  ch=='/'){
            string pre2=prefix.top();
                prefix.top();
            string pre1=prefix.top();
                 prefix.top();
            string anspre=ch+pre1+pre2;
            prefix.push(anspre);
            
            string in2=infix.top();
                infix.pop();
            string in1=infix.top();
                infix.pop();
            string ansin="("+in1+ch+in2+")";
            infix.push(ansin);
            
            int val2=value.top();  value.pop();
            int val1=value.top();  value.pop();
            int ansv=operation(val1,val2,ch);
            value.push(ansv);         
        } else {
            prefix.push(ch+"");
            infix.push(ch+"");
            value.push(ch-'0');
        }
    }
    
    cout<<prefix.top()<<endl;
    cout<<infix.top()<<endl;
    cout<<value.top()<<endl;
    
}


int main() {
   postfix("264*8/+3-");


   
}
