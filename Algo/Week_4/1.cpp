/*
001:Aggressive cows
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ want to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
输入
* Line 1: Two space-separated integers: N and C

* Lines 2..N+1: Line i+1 contains an integer stall location, xi
输出
* Line 1: One integer: the largest minimum distance
样例输入
5 3
1
2
8
4
9
样例输出
3
提示
OUTPUT DETAILS:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.

Huge input data,scanf is recommended.
来源
USACO 2005 February Gold
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int N,C;
    scanf("%d %d",&N,&C);

    int* stall=new int[N];
    for(int i=0;i<N;++i) scanf("%d",&stall[i]);
    sort(stall,stall+N);

    int L=1,R=1000000000/C;
    int mid, D=1;

    while(L<=R){
        mid=L+(R-L)/2;
        int last=0,current;
        for(int i=1;i<C;++i){
            current=last+1;
            while(current<N && stall[current]-stall[last]<mid) current++;
            if(current==N) break;
            last=current;
        }

        if(current==N) R=mid-1;
        else {
            D=mid;
            L=mid+1;
        }
    }

    printf("%d",D);

    return 0;
}