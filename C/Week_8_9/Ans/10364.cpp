/*
程序填空，使得程序按要求输出

输入数据：
第一行是整数n (1<=n<=10)
第二行是 n个整数

输出数据：

先原序输出输入数据中的n个整数
然后再输出:
	
1,2,3,4,5,1,2,3,4,5,
123434567

输入样例：

10
15 25 35 45 55 65 75 85 95 105

输出样例：
15,25,35,45,55,65,75,85,95,105,
1,2,3,4,5,1,2,3,4,5,
123434567
167896789
 
*/
#include <iostream>
using namespace std;
void Memcpy( void * src, void * dest, int size)
{
//your code starts here
	
	char * csrc = (char * ) src;
	char * cdest = (char * ) dest;
	if( src == dest )
		return;
	if( cdest > csrc && cdest < csrc + size) {
		//从后往前拷贝 
		for(int i = size-1; i >= 0; -- i)
			cdest[i] = csrc[i];
	}
	else {
		//从前往后拷贝
		for(int i = 0;i < size; ++i)
			cdest[i] = csrc[i]; 
	}
	
//your code ends here	
}

void Print(int * p,int size)
{
	for(int i = 0;i < size; ++i)
		cout << p[i] << ",";
	cout << endl;
}

int main()
{
	int a[10];
	int n;
	cin >> n;
	for(int i = 0;i < n; ++i)
		cin >> a[i];
	int b[10] = {0};
	Memcpy(a,b,sizeof(a));
	Print(b,n);
	
	int c[10] = {1,2,3,4,5,6,7,8,9,10};
	Memcpy(c,c+5,5*sizeof(int)); //将c的前一半拷贝到后一半 
	Print(c,10);

	char s[10] = "123456789";
	Memcpy(s+2,s+4,5); //将s[2]开始的5个字符拷贝到s[4]开始的地方 
	cout << s << endl;
	
	char s1[10] = "123456789";
	Memcpy(s1+5,s1+1,4); //将s1[5]开始的4个字符拷贝到s1[1]开始的地方 
	cout << s1 << endl;
	
	return 0;
}
