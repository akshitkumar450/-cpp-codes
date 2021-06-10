#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    
    // if in the last row and in last column 
    // return empty string means don't move
    if(sr==dr and sc==dc){
        vector<string>bres;
        bres.push_back("");
        return bres;
    }
    // storing horizontal paths
    vector<string>hPaths;
    // storing vertical paths
    vector<string>vPaths;
    
    vector<string>paths;
    
    // if src row is less than dest row ,means we can move horizontal
    if(sr<dr){
        vPaths=getMazePaths(sr+1,sc,dr,dc);
    } 
    // if src col is less than dest col ,means we can move vertical
    if(sc<dc){
         hPaths=getMazePaths(sr,sc+1,dr,dc);
    }
    
    // put h before horizontal paths
    for(int i=0;i<hPaths.size();i++){
        paths.push_back('h'+hPaths[i]);
    }

    // put v before vertical paths
    for(int i=0;i<vPaths.size();i++){
        paths.push_back('v'+vPaths[i]);
    }
    return paths;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}