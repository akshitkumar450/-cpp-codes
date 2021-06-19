#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverse(queue<int>&s1){
     if(s1.empty()){
        return ;
    }
    int val=s1.front();
    s1.pop();
    reverse(s1);
    s1.push(val);
}

int main() {
    queue<int>s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    reverse(s1);

    while(!s1.empty())
    {
        cout<<s1.front()<<" ";
        s1.pop();
    }

}
