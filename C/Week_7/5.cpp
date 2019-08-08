/*
005:密码翻译
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
在情报传递过程中，为了防止情报被截获，往往需要对情报用一定的方式加密，简单的加密算法虽然不足以完全避免情报被破译，但仍然能防止情报被轻易的识别。我们给出一种最简的的加密方法，对给定的一个字符串，把其中从a-y，A-Y的字母用其后继字母替代，把z和Z用a和A替代，其他非字母字符不变，则可得到一个简单的加密字符串。

输入
输入一行，包含一个字符串，长度小于80个字符。
输出
输出每行字符串的加密字符串。
样例输入
Hello! How are you!
样例输出
Ifmmp! Ipx bsf zpv!
*/

#include <iostream>
using namespace std;

int main(){
    char c[80];
    cin.getline(c,80);
    int i=0;
    while(c[i]){
        if((c[i]>='a' && c[i]<='y') || (c[i]>='A' && c[i]<='Y')) c[i]++;
        else if(c[i]=='z') c[i]='a';
        else if(c[i]=='Z') c[i]='A';
        i++;
    }
    cout<<c;
    return 0;
}
