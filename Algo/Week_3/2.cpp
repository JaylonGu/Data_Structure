/*
002:简单的整数划分问题
查看 提交 统计 提问
总时间限制: 100ms 内存限制: 65536kB
描述
将正整数n 表示成一系列正整数之和，n=n1+n2+…+nk, 其中n1>=n2>=…>=nk>=1 ，k>=1 。
正整数n 的这种表示称为正整数n 的划分。正整数n 的不同的划分个数称为正整数n 的划分数。

输入
标准的输入包含若干组测试数据。每组测试数据是一个整数N(0 < N <= 50)。
输出
对于每组测试数据，输出N的划分数。
样例输入
5
样例输出
7
提示
5, 4+1, 3+2, 3+1+1, 2+2+1, 2+1+1+1, 1+1+1+1+1
*/

#include <iostream>
using namespace std;

int split(int n, int m){    // 数n的划分中，最大的数不超过m
    if(n==1 || m==1) return 1;
    if(n==m) {
        return 1+split(n,m-1);
    }
    if(n<m) return split(n,n);
    if(n>m) return split(n-m,m)+split(n,m-1);
    
}

int main(){
    int N;
    while(cin>>N)
        cout<<split(N,N)<<endl;
    
    return 0;
}