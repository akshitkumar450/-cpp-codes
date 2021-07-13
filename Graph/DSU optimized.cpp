#include <iostream>
#include<list>
using namespace std;

class Graph{
    int v;
    list<pair<int,int>>l;
public:
    Graph(int v){
        this->v=v;
    }
    // storing graph as edge list
    void addEdge(int s,int d){
        l.push_back(make_pair(s,d));
    }

    int find_set(int x,int parent[]){
        // if parent of any node is -1 then it the parent only
        if(parent[x]==-1){
            return x;
        } 
        // path compression step
        return parent[x]= find_set(parent[x],parent);
    }
    
    void union_set(int x,int y,int parent[],int rank[]){
        int s1=find_set(x,parent);
        int s2=find_set(y,parent);
        
        // rank based merging
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            } else{
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }
    }
    
    bool cycle(){
        int *parent=new int[v];
        int *rank=new int[v];
        // at start parent of every node is -1
        for(int i=0;i<v;i++){
            parent[i]=-1;
            rank[i]=1;
        }
        
        for(auto it=l.begin();it!=l.end();it++){
            int first=it->first;
            int second=it->second;
            
            int s1=find_set(first,parent);
            int s2=find_set(second,parent);
            if(s1!=s2){
                union_set(s1,s2,parent,rank);
            } else{
                // cout<<"same parent"<<s1 <<" "<<s2<<endl;
                return true;
            }
        }
        delete [] parent;
        return false;
    }
};

int main() {
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,0);
	cout<<g.cycle()<<endl;
	return 0;
}