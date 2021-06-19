#include <iostream>
#include<stack>
using namespace std;


void insertAtBottom(stack<int>&s1,int x){
    // push it at bottom when stack becomes empty at the base case
    if(s1.empty()){
        s1.push(x);
        return;
    }
    int data=s1.top();
    s1.pop();
    insertAtBottom(s1,x);
    s1.push(data)
}

void reverse(stack<int>&s1){
    // base case
    if(s1.empty()){
        return;
    }
    int x=s1.top();
    s1.pop();
    reverse(s1);
    insertAtBottom(s1,x);
}


int main() {
    stack<int>s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    reverse(s1);

    while(!s1.empty())
    {
        cout<<s1.top()<<endl;
                s1.pop();
    }

}
