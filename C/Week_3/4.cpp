/*
004:苹果和虫子2
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
你买了一箱n个苹果，很不幸的是买完时箱子里混进了一条虫子。虫子每x小时能吃掉一个苹果，假设虫子在吃完一个苹果之前不会吃另一个，那么经过y小时你还有多少个完整的苹果？

输入
输入仅一行，包括n，x和y（均为整数）。
输出
输出也仅一行，剩下的苹果个数
样例输入
10 4 9
样例输出
7
提示
注意：是要求完整的苹果数。
*/

#include <iostream>
using namespace std;

int main(){
    int n,x,y;
    cin>>n>>x>>y; 
    for(;y>0;y-=x,--n);
    cout<<(n>0?n:0);
    return 0;
}