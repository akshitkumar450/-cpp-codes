#include <bits/stdc++.h>
using namespace std;

// 1.Push the first half elements of queue to stack.
// 2.Enqueue back the stack elements.
// 3.Dequeue the first half elements of the queue and enqueue them back.
// 4.Again push the first half elements into the stack.
// 5.Interleave the elements of queue and stack.

void interleave(queue<int>&q) {
    stack<int>s;

    int n=q.size()/2;
    for(int i=1;i<=n;i++) {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    for(int i=1;i<=n;i++) {
        q.push(q.front());
        q.pop();
    }

    for(int i=1;i<=n;i++) {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

void print(queue<int>&q) {
    while(!q.empty()){
    cout<<q.front()<<" ";
    q.pop();
    }
}

int main() {
    
    queue<int>q;
    for(int i=11;i<=20;i++)  q.push(i);
    interleave(q);
    print(q);
}   
