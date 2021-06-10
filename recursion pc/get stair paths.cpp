#include <bits/stdc++.h>
using namespace std;

vector<string> getPath(int n){
    // if n==0 means it on ground ,,only possible it to don't walk 
    // means add empty string
    if(n==0){
        vector<string>bres;
        bres.push_back("");
        return bres;
    } else if(n<0){ // sometimes n can be negative also 
        vector<string>bres;
        return bres;
    }
    // call for n-1 stairs
    vector<string>paths1=getPath(n-1);
    // call for n-2 stairs
    vector<string>paths2=getPath(n-2);
    // call for n-3 stairs
    vector<string>paths3=getPath(n-3);
    
    vector<string>mres;
    
    // put 1 before all the paths from paths1
    for(int i=0;i<paths1.size();i++){
        mres.push_back('1'+paths1[i]);
    }
    // put 2 before all the paths from paths2
    for(int i=0;i<paths2.size();i++){
        mres.push_back('2'+paths2[i]);
    }
    // put 3 before all the paths from 3
    for(int i=0;i<paths3.size();i++){
        mres.push_back('3'+paths3[i]);
    }
    
    // for(string path:paths1){
    //     mres.push_back('1'+path);
    // }
    // for(string path:paths2){
    //     mres.push_back('2'+path);
    // }
    // for(string path:paths3){
    //     mres.push_back('3'+path);
    // }
    return mres;
}

int main() {
    int n;
    cin>>n;
    vector<string>ans=getPath(n);
    cout<<"[";
    int i;
    for( i=0;i<ans.size()-1;i++){
        cout<<ans[i]<<", ";
    }
    cout<<ans[i];
    cout<<"]";
	return 0;
}