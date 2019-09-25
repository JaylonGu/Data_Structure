/*
004:你真的搞清楚为啥 while(cin >> n) 能成立了吗？
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
读入两个整数，输出两个整数 ，直到碰到-1

#include <iostream>
using namespace std;
class MyCin
{
// 在此处补充你的代码
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) 
        cout  << n1 << " " << n2 << endl;
    return 0;
}
输入
多组数据，每组一行，是两个整数
输出
对每组数据，原样输出 
当碰到输入中出现-1 时，程序结束 
输入中保证会有 -1
样例输入
12 44
344 555
-1
2 3
样例输出
12 44
344 555
*/

#include <iostream>
using namespace std;
class MyCin
{
// 在此处补充你的代码
    bool status;
public:
    MyCin():status(true){}
    MyCin & operator>>(int &n){
        cin>>n;
        if(n==-1){
            status=false;
        }
        return *this;
    }
    operator bool(){    // 类型转换运算符的重载
        return status;
    }
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) 
        cout  << n1 << " " << n2 << endl;
    return 0;
}