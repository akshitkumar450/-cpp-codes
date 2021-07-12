#include <iostream>
#include<map>
#include<queue>
#include<list>
#include<climits>
using namespace std;
class graph{
    //mpa to create adjency list.
         map<int,list<int> > mp;
    public:
        //assume its a bidirectional
        void AddEdge(int s ,int d) {
            mp[s].push_back(d);
            mp[d].push_back(s);
        }

        void dfshelp(int src,map<int,bool>&isvisted){
            cout<<src<<",";
            isvisted[src]=true;
            // now visit all nodes of src
            for(auto it=mp[src].begin();it!=mp[src].end();it++) {
                int child=*it;
                if(isvisted[child]==false)
                dfshelp(child,isvisted);
            }
        }

        void dfs(int src)  {
            // array to mark the visited nodes
            // first is for node and second is for true/false for visited
            map<int,bool> isvisted;
            // mark every node as false at starting
            for(auto it=mp.begin();it!=mp.end();it++)  {
                int node=it->first;
                isvisted[node]=false;
            }
            dfshelp(src,isvisted);
        }
};

int main() {
    graph g;
    g.AddEdge(0,1);
    g.AddEdge(1,2);
    g.AddEdge(2,3);
    g.AddEdge(3,4);
    g.AddEdge(4,5);
    g.AddEdge(3,0);
    g.AddEdge(3,6);
    g.AddEdge(2,6);
    g.AddEdge(4,5);
    g.AddEdge(5,7);
    g.AddEdge(6,7);
    g.dfs(0);
}
