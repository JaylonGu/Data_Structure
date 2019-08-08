/*
002:求最大公约数问题
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定两个正整数，求它们的最大公约数。

输入
输入一行，包含两个正整数(<1,000,000,000)。
输出
输出一个正整数，即这两个正整数的最大公约数。
样例输入
6 9
样例输出
3
提示
求最大公约数可以使用辗转相除法：
假设a > b > 0，那么a和b的最大公约数等于b和a%b的最大公约数，然后把b和a%b作为新一轮的输入。
由于这个过程会一直递减，直到a%b等于0的时候，b的值就是所要求的最大公约数。
比如：
9和6的最大公约数等于6和9%6=3的最大公约数。
由于6%3==0，所以最大公约数为3。
*/

#include <iostream>
using namespace std;

int GCD(int m, int n){
    if(m<n){
        int tmp=n;
        n=m;
        m=tmp;
    }
    if(m%n==0) return n;
    else return GCD(n,m%n);
}

int main(){
    int m,n;
    cin>>m>>n;
    cout<<GCD(m,n);
    return 0;
}