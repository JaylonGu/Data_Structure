/*
003:好怪异的返回值
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
填空，使得程序输出指定结果

#include <iostream>
using namespace std;
// 在此处补充你的代码
getElement(int * a, int i)
{
	return a[i];
}
int main()
{
	int a[] = {1,2,3};
	getElement(a,1) = 10;
	cout << a[1] ;
	return 0;
}
输入
无
输出
10
样例输入
无
样例输出
10
*/

#include <iostream>
using namespace std;

int& getElement(int * a, int i)
{
	return a[i];
}
int main()
{
	int a[] = {1,2,3};
	getElement(a,1) = 10;
	cout << a[1] ;
	return 0;
}