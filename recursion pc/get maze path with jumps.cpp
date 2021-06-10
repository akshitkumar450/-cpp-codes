#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePathsWithJumps(int sr, int sc, int dr, int dc) {
        
        if(sr==dr and sc==dc){
            vector<string>bres;
            bres.push_back("");
            return bres;
        }
        
        vector<string>res;
        
    // horizontal moves
    // we can move horizontal between the sc and dc (dc-sc)
    for(int hm=1;hm<=dc-sc;hm++){
        vector<string>hPaths=getMazePathsWithJumps(sr,sc+hm,dr,dc);
        for(string hpath:hPaths){
            res.push_back("h"+hm+hpath);
        }
    }
    // vertical moves
    for(int vm=1;vm<=dr-sr;vm++){
        vector<string>vPaths=getMazePathsWithJumps(sr+vm,sc,dr,dc);
        for(string vpath:vPaths){
            res.push_back("v"+vm+vpath);
        }
    }
    
    // diagonal moves
    // while moving diagnol both horizontal and vertcial moves increases
    for(int dm=1;dm<=dc-sc and dm<=dr-sr;dm++){
        vector<string>dPaths=getMazePathsWithJumps(sr+dm,sc+dm,dr,dc);
        for(string dpath:dPaths){
            res.push_back("d"+dm+dpath);
        }
    }
    
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
    vector<string> ans = getMazePathsWithJumps(0,0,n-1,m-1);
    display(ans);

    return 0;
}