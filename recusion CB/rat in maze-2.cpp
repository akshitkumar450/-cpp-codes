#include<iostream>
using namespace std;

bool SolveMaze(char Maze[][10],int sol[][10],int m,int n,int i,int j,int &cnt) {
    if(i==m-1 and j==n-1){
        sol[i][j]=1;
        cnt++;
        // print apth
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<sol[i][j];
            } 
            cout<<endl;
        }
        cout<<endl;
        
        return true;
    }
    // for boundary cases
    if(i>m || j>n){
        return false;
    }
    // if a path is blocked return false
    if(Maze[i][j]=='X'){
        return false;
    }
    // if there is a path mark it as 1
    sol[i][j]=1;
    // call in right
    bool right=SolveMaze(Maze,sol,m,n,i,j+1,cnt);
    // call in down
    bool down=SolveMaze(Maze,sol,m,n,i+1,j,cnt);

    // backtracking
    // mark 0 while returning
    sol[i][j]=0;

    // if any of right or down path exists return true
    if(right ||  down){
        return true;
    }
    return false;
}

int main(){
    char Maze[10][10]={
        "0000",
        "00X0",
        "000X",
        "0X00"    
    };
    int m=4,n=4;
    int cnt=0;
    int sol[10][10]={0};
    bool ans=SolveMaze(Maze,sol,m,n,0,0,cnt);
    if(ans==false){
        cout<<"no path exists";
    }
    cout<<cnt;
}
