/*
002:A Knight's Journey
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Background
The knight is getting bored of seeing the same black and white squares again and again and has decided to make a journey
around the world. Whenever a knight moves, it is two squares in one direction and one square perpendicular to this. The world of a knight is the chessboard he is living on. Our knight lives on a chessboard that has a smaller area than a regular 8 * 8 board, but it is still rectangular. Can you help this adventurous knight to make travel plans?

<img src=http://media.openjudge.cn/images/g1490/2488_1.jpg align=right>

Problem
Find a path such that the knight visits every square once. The knight can start and end on any square of the board.
输入
The input begins with a positive integer n in the first line. The following lines contain n test cases. Each test case consists of a single line with two positive integers p and q, such that 1 <= p * q <= 26. This represents a p * q chessboard, where p describes how many different square numbers 1, . . . , p exist, q describes how many different square letters exist. These are the first q letters of the Latin alphabet: A, . . .
输出
The output for every scenario begins with a line containing "Scenario #i:", where i is the number of the scenario starting at 1. Then print a single line containing the lexicographically first path that visits all squares of the chessboard with knight moves followed by an empty line. The path should be given on a single line by concatenating the names of the visited squares. Each square name consists of a capital letter followed by a number.
If no such path exist, you should output impossible on a single line.
样例输入
3
1 1
2 3
4 3
样例输出
Scenario #1:
A1

Scenario #2:
impossible

Scenario #3:
A1B3C1A2B4C2A3B1C3A4B2C4
来源
TUD Programming Contest 2005, Darmstadt, Germany
*/

#include <iostream>
#include <cstring>
using namespace std;

bool flag,visited[26][26];
short p,q,path[26*26][2];

void DFS(short x, short y, short count){
    path[count][0]=x;
    path[count][1]=y;
    if(count==p*q-1){
        flag=true;
        return;
    }
    if(y-2>=0){
        if(x-1>=0 && !visited[x-1][y-2]) {
            visited[x-1][y-2]=true;
            DFS(x-1,y-2,count+1);
            visited[x-1][y-2]=false;
        }
        if(x+1<p && !flag && !visited[x+1][y-2]) {
            visited[x+1][y-2]=true;
            DFS(x+1,y-2,count+1);
            visited[x+1][y-2]=false;
        }
    }
    if(y-1>=0 && !flag){
        if(x-2>=0 && !visited[x-2][y-1]) {
            visited[x-2][y-1]=true;
            DFS(x-2,y-1,count+1);
            visited[x-2][y-1]=false;
        }
        if(x+2<p && !flag && !visited[x+2][y-1]) {
            visited[x+2][y-1]=true;
            DFS(x+2,y-1,count+1);
            visited[x+2][y-1]=false;
        }
    }
    if(y+1<q && !flag){
        if(x-2>=0 && !visited[x-2][y+1]) {
            visited[x-2][y+1]=true;
            DFS(x-2,y+1,count+1);
            visited[x-2][y+1]=false;
        }
        if(x+2<p && !flag && !visited[x+2][y+1]) {
            visited[x+2][y+1]=true;
            DFS(x+2,y+1,count+1);
            visited[x+2][y+1]=false;
        }
    }
    if(y+2<q && !flag){
        if(x-1>=0 && !visited[x-1][y+2]) {
            visited[x-1][y+2]=true;
            DFS(x-1,y+2,count+1);
            visited[x-1][y+2]=false;
        }
        if(x+1<p && !flag && !visited[x+1][y+2]) {
            visited[x+1][y+2]=true;
            DFS(x+1,y+2,count+1);
            visited[x+1][y+2]=false;
        }
    }
    return;
}

int main(){
    // freopen("in.txt","r",stdin);
    short n;
    cin>>n;
    for(int i=1;i<=n;++i){
        memset(visited,0,sizeof(visited));
        flag=false;
        cin>>p>>q;
        cout<<"Scenario #"<<i<<":"<<endl;
        visited[0][0]=true;
        DFS(0,0,0);
        if(flag){
            for(int i=0;i<q*p;i++)
                cout<<(char)(path[i][1]+'A')<<path[i][0]+1;
        }else{
            cout<<"impossible";
        }
        cout<<endl;
        if(i!=n) cout<<endl;
    }
    return 0;
}