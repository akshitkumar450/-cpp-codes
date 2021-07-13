#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class DSU {
    int*parent;
    int*rank;
    public:
        DSU(int n){
           parent=new int[n];
           rank=new int[n];
           for (int i = 0; i < n; i++) {
               parent[i]=-1;
               rank[i]=1;
           }
        }
        int find(int x){
            if(parent[x]==-1){
                return x;
            }
            return parent[x]=find(parent[x]);
        }
        
        void unionSet(int x,int y){
            int s1=find(x);
            int s2=find(y);
            if(s1!=s2){
                if(rank[s1]<rank[s2]){
                    parent[s1]=s2;
                    rank[s2]+=rank[s1];
                }   else{
                    parent[s2]=s1;
                    rank[s1]+=rank[s2];
                }
            }
        }
};

class Graph{
    int v;
    // storing graph as edgeList
    vector<vector<int>>edgeList;

  public:
    Graph(int v){
        this->v=v;
    }

    void add(int x,int y,int w){
        edgeList.push_back({w,x,y});
    }
    
    int kruskal_MST(){
        DSU s(v);
        // sort the edges on basis of weight
        sort(edgeList.begin(),edgeList.end());
        int ans=0;
        
        for(auto edge:edgeList){
            int wt=edge[0];
            int x=edge[1];
            int y=edge[2];
            // add the edge in MST if it does not containe a cycle
            if(s.find(x)!=s.find(y)){
                s.unionSet(x,y);
                ans+=wt;
            }
        }
        return ans;
    }
};

int main() {
    // int node,edges;
    // cin>>node>>edges;
    // Graph g(node);
    // for(int i=0;i<edges;i++){
    //     int x,y,w;
    //     cin>>x>>y>>w
    //     g.add(x-1,y-1,w);
    // }
	Graph g(4);
	g.add(0,1,1);
	g.add(1,3,3);
	g.add(3,2,4);
	g.add(2,0,2);
	g.add(0,3,2);
	g.add(1,2,2);
	cout<<g.kruskal_MST();
	return 0;
}