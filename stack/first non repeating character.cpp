#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeating(){
    queue<char>q;
    char data;
    cin>>data;
    // to store the frequency of the characters
    int freq[256]={0};
    
    while(data!='.'){
        q.push(data);
        freq[data]+=1;
        
        while(!q.empty()){
            // check the frequency of the front element in the queue 
            // if it has the frequency==1 then print it else pop it
            char first=q.front();
            if(freq[first]>1){
                q.pop();
            } else{
                cout<<first<<" ";
                break;
            }
        }
        // if you are here ,means you have break the loop and printed the character
        // or your queue is empty 
        if(q.empty()){
            cout<<"-1 ";
        }
        // enter data for next 
        cin>>data;
    }
}

int main() {
	firstNonRepeating();
	return 0;
}