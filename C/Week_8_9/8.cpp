/*
008:指针练习：指向指针的指针
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
程序填空使得输出指定结果

#include <iostream>
using namespace std;
int main()
{
	int x,y,z;
	x = 10;
	y = 20;
	z = 30;
	
	int * a[3]  = { &x, &y,&z};
	for(
// 在此处补充你的代码
p < a + 3; ++p) 
			cout<< * (*p) << endl;
	return 0;
	
}
输入
无
输出
10
20
30
样例输入
无
样例输出
10
20
30
*/

#include <iostream>
using namespace std;
int main()
{
	int x,y,z;
	x = 10;
	y = 20;
	z = 30;
	
	int * a[3]  = { &x, &y,&z};
	for(
// 在此处补充你的代码
    int** p=a;
p < a + 3; ++p) 
			cout<< * (*p) << endl;
	return 0;
	
}