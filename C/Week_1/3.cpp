/*
003:打印ASCII码
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输入一个除空格以外的可见字符（保证在函数scanf中可使用格式说明符%c读入），输出其ASCII码。

输入
一个除空格以外的可见字符。
输出
一个十进制整数，即该字符的ASCII码。
样例输入
A
样例输出
65
*/


#include <cstdio>

int main()
{
    char a;
    scanf("%c",&a);
    printf("%d",a);
    return 0;
}