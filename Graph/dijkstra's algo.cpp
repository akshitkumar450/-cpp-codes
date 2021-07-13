#include<iostream>
#include<list>
#include<queue>
#include<climits>
using namespace std;

class compare{
public:
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        if (a.second<b.second) return true; else return false;
    }
};
class WGraphs{
    list<pair<int,int>> *arr;
    int V;
public:
    WGraphs(int s=5){
        V=s;
        arr= new list<pair<int,int>>[V];
    }
    void AddEdge (int s, int d, int dist, bool isBiDir=true){
        arr[s].push_back(make_pair(d,dist));
        if (isBiDir) arr[d].push_back(make_pair(s,dist));
    }

    int Dijkstra(int s, int d){
        int Distance[V];
        for (int i=0;i<V;i++) Distance[i]=INT_MAX;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
                // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > > pq;

        Distance[s]=0;
        pq.push(make_pair(s,0));
        while (!pq.empty()){
            pair<int,int> f=pq.top();
            pq.pop();
            if (f.second>Distance[f.first]) continue;
            for (auto it=arr[f.first].begin();it!=arr[f.first].end();it++){
                pair<int,int> ch=*it;
                int disttillch=Distance[f.first]+ch.second;
                if (disttillch<Distance[ch.first]){
                    Distance[ch.first]=disttillch;
                    pq.push(make_pair(ch.first,disttillch));
                }
            }
        }
        for (int i=0;i<V;i++) cout<<i<<"-"<<Distance[i]<<endl;
        return Distance[d];
    }
};

int main(){
    WGraphs g(7);
    g.AddEdge(0,1,20);
    g.AddEdge(0,3,18);
    g.AddEdge(0,2,20);
    g.AddEdge(1,4,15);
    g.AddEdge(3,4,14);
    g.AddEdge(3,5,15);
    g.AddEdge(2,5,12);
    g.AddEdge(4,6,9);
    g.AddEdge(5,6,8);
    cout<<g.Dijkstra(0,8);
}
