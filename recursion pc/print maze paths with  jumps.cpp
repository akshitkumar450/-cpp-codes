#include<iostream>
#include<cstring>
using namespace std;

    void printMazePaths(int sr, int sc, int dr, int dc, string psf) {        
        if(sr==dr and sc==dc){
            cout<<psf<<endl;
            return;
        }
        for(int hm=1;hm<=dc-sc;hm++){
            printMazePaths(sr,sc+hm,dr,dc,psf+ "h"+to_string(hm));
        }
        for(int vm=1;vm<=dr-sr;vm++){
            printMazePaths(sr+vm,sc,dr,dc,psf+ "v" +to_string(vm));
        }
        for(int dm=1;dm<=dc-sc and dm<=dr-sr;dm++){
            printMazePaths(sr+dm,sc+dm,dr,dc,psf+ "d" +to_string(dm));
        }
        
    }

int main() {
        int n ;
        int m ;cin>>n>>m;
        printMazePaths(0, 0, n - 1, m - 1, "");
    }