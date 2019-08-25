/*
08:单词倒排
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
编写程序，读入一行英文(只包含字母和空格，单词间以单个空格分隔)，将所有单词的顺序倒排并输出，依然以单个空格分隔。

输入
输入为一个字符串（字符串长度至多为100）。
输出
输出为按要求排序后的字符串。
样例输入
I am a student
样例输出
student a am I
*/

#include <iostream>
using namespace std;

struct mystring{
    char c[100];
};

int main(){
    struct mystring s[100];
    int i=0;
    while(cin>>s[i++].c);
    while(--i){
        cout<<s[i].c<<" ";
    }
    cout<<s[i].c;

    return 0;
}
