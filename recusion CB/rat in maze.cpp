#include<iostream>
using namespace std;
#define M 4
#define N 5

void PrintMaze(char Maze[M][N]){
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            cout<<Maze[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

void SolveMaze(char Maze[M][N], int rPos, int cPos, int &cnt){
    Maze[rPos][cPos]='Y';
    if (rPos==M-1 && cPos==N-1){
        cnt++;
        PrintMaze(Maze);
        Maze[rPos][cPos]='.';
        return;
    }

    ///right Move
    if (cPos+1<=N-1 && Maze[rPos][cPos+1]!='X')
        SolveMaze(Maze,rPos, cPos+1,cnt);
    ///Down Move
    if (rPos+1<=M-1 && Maze[rPos+1][cPos]!='X')
        SolveMaze(Maze,rPos+1, cPos,cnt);
    Maze[rPos][cPos]='.';
}

int main(){
    char Maze[M][N]={{'.','.','X','.','.'},
                    {'.','.','.','.','.'},
                    {'.','X','.','X','.'},
                    {'.','.','.','.','.'}};
    int cnt=0;
    SolveMaze(Maze,0,0,cnt);
    cout<<cnt<<endl;
}

/*
void SolveMaze(char Maze[M][N], int rPos, int cPos, int &cnt){
    if (rPos==M-1 && cPos==N-1){
        cnt++;
        return;
    }

    ///right Move
    if (cPos+1<=N-1 && Maze[rPos][cPos+1]!='X')
        SolveMaze(Maze,rPos, cPos+1,cnt);
    ///Down Move
    if (rPos+1<=M-1 && Maze[rPos+1][cPos]!='X')
        SolveMaze(Maze,rPos+1, cPos,cnt);

}
*/
