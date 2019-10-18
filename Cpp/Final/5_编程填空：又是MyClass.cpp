/*
005:编程填空：又是MyClass
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
补充下列代码，使得程序能够按要求输出

#include <iostream>
#include <cstring> 
#include <vector>
#include <cstdio> 
using namespace std;
// 在此处补充你的代码
int  a[40];
int main(int argc, char** argv) {
	int t;
	scanf("%d",&t);
	while ( t -- ) {
		int m;
		scanf("%d",&m);
		for (int i = 0;i < m; ++i) 
			scanf("%d",a+i);
		char s[100];
		scanf("%s",s);
		CMyClass<int> b(a, m);
		CMyClass<char> c(s, strlen(s));
		printf("%d %c\n", b[5], c[7]);
	}
	return 0;
}
输入
第一行是整数t表示数据组数
每组数据有两行
第一行开头是整数m，然后后面是m个整数(5 < m < 30)
第二行是一个没有空格的字符串，长度不超过50
输出
对每组数据 先输出m个整数中的第5个，然后输出字符串中的第7个字符。
"第i个"中的 i 是从0开始算的。
样例输入
1
6 1 3 5 5095 8 8
helloworld
样例输出
8 r
*/

#include <iostream>
#include <cstring> 
#include <vector>
#include <cstdio> 
using namespace std;
// 在此处补充你的代码
template<class T>
class CMyClass{
public:
T* ptr;
CMyClass(T* _ptr, int len){
    ptr=new T[len];
    memcpy(ptr,_ptr,len*sizeof(T));
}
~CMyClass(){
    delete [] ptr;
}
T operator [](int i){
    return ptr[i];
}
};

int  a[40];
int main(int argc, char** argv) {
	int t;
	scanf("%d",&t);
	while ( t -- ) {
		int m;
		scanf("%d",&m);
		for (int i = 0;i < m; ++i) 
			scanf("%d",a+i);
		char s[100];
		scanf("%s",s);
		CMyClass<int> b(a, m);
		CMyClass<char> c(s, strlen(s));
		printf("%d %c\n", b[5], c[7]);
	}
	return 0;
}