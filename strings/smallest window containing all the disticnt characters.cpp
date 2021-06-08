#include <bits/stdc++.h>
using namespace std;

int smallestDistinct(string str){
    set<char>st; // tl get the unique characters
    for(int i=0;i<str.length();i++){
        st.insert(str[i]);
    }
    // to keep the count of the distinct element
    unordered_map<char,int>mp;
    int n=st.size(); // number of distinct elements
    int i=0;int j=1;
    int cnt=0; // to keep the window size
    mp[str[i]]++;
    cnt++;
    int ans=INT_MAX;
    while(i<=j and j<str.length()){
        if(cnt<n){  // expand the window from right
            if(mp[str[j]]==0) cnt++; // if new char comes ,increment the cnt
            mp[str[j]]++; // increment frequency whether it comes for first time or a existing char 
            j++;
        } else if(cnt==n){ // shrink the window from left
            ans=min(ans,j-i); // find the minimum window length
            if(mp[str[i]]==1) cnt--;
            mp[str[i]]--;
            i++;
        }
    }
    while(cnt==n){  // shrink the window from left
         ans=min(ans,j-i);
            if(mp[str[i]]==1) cnt--;
            mp[str[i]]--;
            i++;
    }
    return ans;
}

int main() {
    string str = "aabcbcdbca";
    cout<<smallestDistinct(str);
	return 0;
}