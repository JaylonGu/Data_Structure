/* 
��дMyForeachģ�壬ʹ����Ҫ����� 
���ñ�д MyForeach����
 

���룺
 
��������

ÿ�����ݵ�һ������������ m �� n ,�������� 50

�ڶ�����m�������ո���ַ���
�������� n������


�����

��ÿ������
��һ��������������ַ�������һ��Ľ��
�ڶ�����������е�ÿ��������1�Ľ��


�������룺

3 4
Tom Mike Jack
1 2 3 4
1 2
Peking
100 200

���������

TomMikeJack
2,3,4,5,
Peking
101,201,

 

 
*/

 
#include <iostream>
#include <string>
using namespace std;
//your code starts here
template <class T1, class T2 >
void MyForeach( T1 s,T1 e, T2 op) 
{
	for(;s != e; ++s) {
		op(*s);
	}
}
//your code ends here
	void Print(string s)
	{
		cout << s;
	}
	void Inc(int & n)
	{
		++ n;
	}
	string array[100];
	int a[100];
	int main() {
		int m,n;
		while(cin >> m >> n) {
			for(int i = 0;i < m; ++i)
				cin >> array[i];
			for(int j = 0; j < n; ++j)
				cin >> a[j];
			MyForeach(array,array+m,Print);		 
			cout << endl;
			MyForeach(a,a+n,Inc);		 
			for(int i = 0;i < n; ++i)
				cout << a[i] << ",";
			cout << endl;
		}
		return 0;
	} 

