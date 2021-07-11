#include<iostream>
// #include<unordered_map>
#include<map>
#include<list>
#include<cstring>
using namespace std;

class graph{
    // unordered_map<string,list<pair<string,int> > > mp;
    map<string,list<pair<string,int> > > mp;

    public:
      void add(string s,string d, bool isbi,int wt)
      {
          mp[s].push_back(make_pair(d,wt));
          if(isbi)
           mp[d].push_back(make_pair(s,wt));
      }
   
      void print()
      {
            for(auto it=mp.begin();it!=mp.end();it++)
            {
                    //  string city=it->first;
                     list<pair<string ,int> > nbrs =it->second;
                     cout<<it->first<<"->";
                for(auto it=nbrs.begin();it!=nbrs.end();it++)
                {
                    cout<<it->first<<" "<<it->second<<",";
                }
                cout<<endl;
            }
      }
};
int main()
{
    graph g;
    g.add("a","b",true,20);
    g.add("a","c",true,40);
    g.add("a","d",false,50);
    g.add("d","b",true,30);
    g.add("c","d",true,60);
    g.print();

}