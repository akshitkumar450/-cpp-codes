#include <iostream>
#include<map>
#include<queue>
#include<list>
#include<climits>
using namespace std;
class graph{
    //map to create adjency list.
         map<int,list<int> > mp;
    public:
        void AddEdge(int s ,int d) {
            mp[s].push_back(d);
            // mp[d].push_back(s);
        }

          
        void dfshelp(int src,map<int , bool> &visited, list<int>&ordering) {
            visited[src]=true;
            for(auto it=mp[src].begin();it!=mp[src].end();it++) {
                int child=*it;
                if(visited[child]==false)
                    dfshelp(child,visited,ordering);
            }
            ordering.push_front(src);
            return;
        }

        void dfs(int src) {
            // array to mark the visited nodes
            map<int,bool> visited;
            // to store the ordering of the node
            list<int>ordering;
            // the the array false at starting
            for(auto it=mp.begin();it!=mp.end();it++)  {
                int node=it->first;
                visited[node]=false;
            }
            // iterative over the nodes which are not visited
            for(auto it=mp.begin();it!=mp.end();it++){
                int node=it->first;
                if(visited[node]==false){
                    dfshelp(node,visited,ordering);
                }
            }

            // print the sorted nodes
            for(auto it=ordering.begin();it!=ordering.end();it++){
                cout<<*it<<" ";
            }
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
