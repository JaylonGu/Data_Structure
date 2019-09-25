/*
002:Radar Installation
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Assume the coasting is an infinite straight line. Land is in one side of coasting, sea in the other. Each small island is a point locating in the sea side. And any radar installation, locating on the coasting, can only cover d distance, so an island in the sea can be covered by a radius installation, if the distance between them is at most d.

We use Cartesian coordinate system, defining the coasting is the x-axis. The sea side is above x-axis, and the land side below. Given the position of each island in the sea, and given the distance of the coverage of the radar installation, your task is to write a program to find the minimal number of radar installations to cover all the islands. Note that the position of an island is represented by its x-y coordinates.

Figure A Sample Input of Radar Installations
输入
The input consists of several test cases. The first line of each case contains two integers n (1<=n<=1000) and d, where n is the number of islands in the sea and d is the distance of coverage of the radar installation. This is followed by n lines each containing two integers representing the coordinate of the position of each island. Then a blank line follows to separate the cases.

The input is terminated by a line containing pair of zeros
输出
For each test case output one line consisting of the test case number followed by the minimal number of radar installations needed. "-1" installation means no solution for that case.
样例输入
3 2
1 2
-3 1
2 1

1 2
0 2

0 0
样例输出
Case 1: 2
Case 2: 1
来源
Beijing 2002
*/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct range{
    double l,r;
    bool operator<(range is){
        return l<is.l;
    }
};

range island[1000];

int main(){
    freopen("in.txt","r",stdin);
    int n,d;
    cin>>n>>d;
    int Case=0;
    while(n || d){
        Case++;
        int x,y,flag=0;
        for(int i=0;i<n;++i){
            cin>>x>>y;
            double dx;
            if(d>=y){
                dx=sqrt(d*d-y*y);
                island[i].l=x-dx;
                island[i].r=x+dx;
            }
            else
                flag=1;
        }
        int count=0;
        cout<<"Case "<<Case<<": ";
        if(flag) cout<<"-1"<<endl;
        else{
            sort(island,island+n);
            int firstNoCovered=0;
            for(int i=1;i<n;++i){
                for(int j=firstNoCovered;j<i;j++){
                    if(island[j].r<island[i].l){
                        firstNoCovered=i;
                        count++;
                        break;
                    }
                }
            }
            count++;
            cout<<count<<endl;
        }
        cin>>n>>d;
    }
    return 0;
}