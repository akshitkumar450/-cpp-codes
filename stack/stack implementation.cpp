#include<iostream>
using namespace std;

class Stack{
private:
    int max;
    int top;
    int *arr;
    
public: 
    Stack(int maxSize){
        max=maxSize;
        top=-1;
        arr=new int[maxSize];
    }
    void push(int data){
        if(top==max-1){
            cout<<"overflow"<<endl;
            return;
        }
        top++;
        arr[top]=data;
    }
    void pop(){
        if(top==-1){
            cout<<"stack is empty";
            return;
        }
        top--;
    }
    int getTop(){
        return arr[top];
    }
    int size(){
        return top+1;
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        } else {
            return false;
        }
    }
};

int main(){
    Stack s(5);
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    cout<<s.getTop()<<endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.getTop()<<endl;
}
