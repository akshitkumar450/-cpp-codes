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
        //assume its a bidirectional
        void AddEdge(int s ,int d)  {
            mp[s].push_back(d);
            mp[d].push_back(s);
        }

        void bfs(int src)  {
            cout<<"BFS: ";
            // maintained an array to mark the visited nodes .
            map<int,bool> isvisted;
            queue<int> q;
            q.push(src);
            isvisted[src]=true;
            while(!q.empty()) {
                int t=q.front();
                q.pop();
                cout<<t<<",";
                for(auto it=mp[t].begin();it!=mp[t].end();it++)
                {
                    int c=*it;
                    if(isvisted[c]==false)
                    {
                        q.push(c);
                        isvisted[c]=true;                    
                    }
                }
            }
        }


        // similar to BFS
        void bfsSP(int src) {
            // cout<<"SP:";
            // create a distacne array ,first is node and second is distance
            map<int,int> distance;
            queue<int> q;
            // distance of src node is 0 and for every other node is int_max
            for(auto it=mp.begin();it!=mp.end();it++)  {
                int node=it->first;
                distance[node]=INT_MAX;
            }
            // push the src node and mark its distance 0
            q.push(src);
            distance[src]=0;
            while(!q.empty()) {
                int top=q.front();
                q.pop();
                for(auto it=mp[top].begin();it!=mp[top].end();it++) {
                    int ch=*it;
                    //means we are visitng the node for the first time
                    if(distance[ch]==INT_MAX) {
                        q.push(ch); // push it to queue
                        // calc.  its distance 
                        distance[ch]=distance[top]+1;                        
                    }
                }
            }

            //print the nodes with distance
            for(auto it=mp.begin();it!=mp.end();it++) {
                int node=it->first;
                int dis=distance[node];
                cout<<"node "<<node<<" has a distance of "<<dis<<endl;
            }

        }
};

int main() {
   graph g;
    g.AddEdge(0,1);
    g.AddEdge(0,3);
    // g.AddEdge(0,2);
    g.AddEdge(2,3);
    g.AddEdge(3,4);
    g.AddEdge(4,5);
    // g.AddEdge(3,6);
    // g.AddEdge(2,6);
    // g.AddEdge(4,5);
    // g.AddEdge(5,7);
    // g.AddEdge(6,7);
    
    g.bfs(0);
    cout<<endl;
    g.bfsSP(0);
}
