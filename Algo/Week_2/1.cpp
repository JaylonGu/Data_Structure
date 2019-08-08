/*
001:全排列
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个由不同的小写字母组成的字符串，输出这个字符串的所有全排列。 我们假设对于小写字母有'a' < 'b' < ... < 'y' < 'z'，而且给定的字符串中的字母已经按照从小到大的顺序排列。

输入
输入只有一行，是一个由不同的小写字母组成的字符串，已知字符串的长度在1到6之间。
输出
输出这个字符串的所有排列方式，每行一个排列。要求字母序比较小的排列在前面。字母序如下定义：

已知S = s1s2...sk , T = t1t2...tk，则S < T 等价于，存在p (1 <= p <= k)，使得
s1 = t1, s2 = t2, ..., sp - 1 = tp - 1, sp < tp成立。
样例输入
abc
样例输出
abc
acb
bac
bca
cab
cba
*/

#include <iostream>
#include <cstring>
using namespace std;

char dest[7];
int length;

void Perm(char str[]){
    int l=strlen(str);

    if(l==1) {
        dest[length-1]=str[0];
        dest[length]=0;
        cout<<dest<<endl;
        return;
    }
    for(int i=0;i<l;i++){
        dest[length-l]=str[i];
        char tmp[7];
        strcpy(tmp,str);
        for(int j=i;j<l;j++){
            tmp[j]=tmp[j+1];
        }
        Perm(tmp);
    }
    return;
}

int main(){
    char src[7];
    cin>>src;
    length=strlen(src);
    Perm(src);

    return 0;
}