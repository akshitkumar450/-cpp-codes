#include <iostream>
#include<list>
#include<map>
#include<queue>
using namespace std;

class graph {
    map<int,list<int> > mp;
public:
    void add(int x,int y) {
        mp[x].push_back(y);
    }

    void topological() {
        //create a array of indegree
        map<int,int> indegree;
        for(auto it=mp.begin();it!=mp.end();it++) {   
            int node=it->first;
            // at starting indegree of every node should be 0
            indegree[node]=0;
        }

        // now traverse the graph and increase the indegree of evey node
        for(auto it=mp.begin();it!=mp.end();it++) {
             int node=it->first;
            for(auto it=mp[node].begin();it!=mp[node].end();it++) {
               int ch=*it;
               indegree[ch]++;
            }
        }        
        //bfs
        queue<int> q;
        // find a node whose indegree is 0 and push it to queue
        for(auto it=indegree.begin();it!=indegree.end();it++) {   
            int node=it->first;
            if(indegree[node]==0)
                q.push(node);
        }
        
        while(!q.empty()) {
            int t=q.front();
            cout<<t<<",";
            q.pop();
            // find the adjacent node and reduce their indegree and 
            // if any node's indegree become 0 push it
            for(auto it=mp[t].begin();it!=mp[t].end();it++) {   
                int chch=*it;
                indegree[chch]--;
                if(indegree[chch]==0)
                    q.push(chch);
            }
        }
    }

};

int main() {
    graph g;
    g.add(0,2);
    g.add(1,2);
    g.add(1,4);
    g.add(2,3);
    g.add(2,5);
    g.add(4,5);
    g.add(3,5);
    g.topological();
}
