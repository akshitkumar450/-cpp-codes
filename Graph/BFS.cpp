#include <bits/stdc++.h>
using namespace std;

class graph{
    map<int,list<int> > mp;
public:
    void add(int x,int y) {
        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    void bfs(int src) {
        // for marking a node visited
        map<int,bool>visited;
        queue<int>q;

        // push the src node and mark it visited
        q.push(src);
        visited[src]=true;

        while(!q.empty()) {
            // take out the first node
            int top =q.front();
            q.pop();
            cout<<top<< " "; 
            for(auto it=mp[top].begin(); it!=mp[top].end() ; it++) {
                int ch=*it;
                if(!visited[ch]) {
                    q.push(ch);
                    visited[ch]=true;
                }
            }
        }
    }
};
int main() {
   graph g;
    g.add(0, 1); 
    g.add(0, 2); 
    g.add(1, 2); 
    g.add(2, 0); 
    g.add(2, 3); 
    g.add(3, 3); 
    g.bfs(2);

}
