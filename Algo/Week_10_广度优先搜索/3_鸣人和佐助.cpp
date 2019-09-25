/*
003:鸣人和佐助
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
佐助被大蛇丸诱骗走了，鸣人在多少时间内能追上他呢？

已知一张地图（以二维矩阵的形式表示）以及佐助和鸣人的位置。地图上的每个位置都可以走到，只不过有些位置上有大蛇丸的手下，需要先打败大蛇丸的手下才能到这些位置。鸣人有一定数量的查克拉，每一个单位的查克拉可以打败一个大蛇丸的手下。假设鸣人可以往上下左右四个方向移动，每移动一个距离需要花费1个单位时间，打败大蛇丸的手下不需要时间。如果鸣人查克拉消耗完了，则只可以走到没有大蛇丸手下的位置，不可以再移动到有大蛇丸手下的位置。佐助在此期间不移动，大蛇丸的手下也不移动。请问，鸣人要追上佐助最少需要花费多少时间？

输入
输入的第一行包含三个整数：M，N，T。代表M行N列的地图和鸣人初始的查克拉数量T。0 < M,N < 200，0 ≤ T < 10
后面是M行N列的地图，其中@代表鸣人，+代表佐助。*代表通路，#代表大蛇丸的手下。
输出
输出包含一个整数R，代表鸣人追上佐助最少需要花费的时间。如果鸣人无法追上佐助，则输出-1。
样例输入
样例输入1
4 4 1
#@##
**##
###+
****

样例输入2
4 4 2
#@##
**##
###+
****
样例输出
样例输出1
6

样例输出2
4
*/

#include <iostream>
#include <queue>
using namespace std;

char map[200][200];
int visited[200][200][9]{0};

int xc[4]={-1,0,0,1};
int yc[4]={0,-1,1,0};

struct place{
    int x,y;
    int time;
    int chakla;
    place(int a, int b, int c, int d):x(a),y(b),time(c),chakla(d){}
};

int main(){
    freopen("in.txt","r",stdin);
    int M,N,T;
    cin>>M>>N>>T;
    int x,y,time;
    for(int i=0;i<M;++i){
        for(int j=0;j<N;++j){
            cin>>map[i][j];
            if(map[i][j]=='@'){
                x=i;
                y=j;
            }
        }
    }

    for(int i=0;i<=T;++i)
        visited[x][y][i]=1;
    queue<place> q;
    q.emplace(x,y,0,T);
    while(!q.empty()){
        place tmp=q.front();
        x=tmp.x;
        y=tmp.y;
        time=tmp.time+1;
        int newx,newy;
        for(int i=0;i<4;++i){
            newx=x+xc[i];
            newy=y+yc[i];
            if(newx>=0 && newx<M && newy>=0 && newy<N && !visited[newx][newy][tmp.chakla]){
                if(map[newx][newy]=='*') {
                    q.emplace(newx,newy,time,tmp.chakla);
                    for(int i=0;i<=tmp.chakla;i++)
                        visited[newx][newy][i]=1;
                }else if(map[newx][newy]=='#'){
                    if(tmp.chakla>0){
                        q.emplace(newx,newy,time,tmp.chakla-1);
                        for(int i=0;i<=tmp.chakla;i++)
                            visited[newx][newy][i]=1;
                    }
                }else{
                    cout<<time<<endl;
                    return 0;
                }
            }
        }
        q.pop();
    }
    cout<<"-1"<<endl;

    return 0;
}
