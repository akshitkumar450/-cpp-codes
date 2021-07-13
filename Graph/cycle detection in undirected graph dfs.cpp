#include<bits/stdc++.h> 
using namespace std; 

class Graph{
    map<int,list<int>>mp;
    
    public:
        void addEdge(int x,int y){
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
    
    bool DFSHelp(int src,map<int,bool> &visited,int parent){
        // mark the src node as visited
        visited[src]=true;
        // and then check for it adjacent nodes
        for(auto it=mp[src].begin();it!=mp[src].end();it++){
            int child=*it;
            // if the child node is not visited and visit it
            if(visited[child]==false){
                bool cycleFound=DFSHelp(child,visited,src);
                if(cycleFound==true){
                    return true;
                }
                // if the node is not called by the parent node then there is a cycle
            } else if(child!=parent){
                return true;
            }
        }
        // else not containing cycle
        return false;
    }
    
    bool DFS(){
        // visited array
        map<int,bool> visited;
        for(auto it=mp.begin();it!=mp.end();it++){
            // mark all nodes as not visited in beginning
            int node=it->first;
            visited[node]=false;
        }
        // parent of the src node is -1
      return DFSHelp(0,visited,-1);
    }
};

int main() 
{ 
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,2);

	if(g.DFS())
	    cout<<"Cycle found";
	else
	    cout<<"No cycle found";

	return 0; 
} 
