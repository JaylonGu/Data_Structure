
/*
��дģ�� PrintArray,ʹ�ó����������ǣ�

TomJackMaryJohn
10


���ñ�дSumArray���� 

*/ 


#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(
//your code starts here
T * begin, T * end) {
	T tmp = * begin;
	++ begin;
	for(;  begin != end ; ++ begin)
		tmp += * begin;
	return tmp;
//your code ends here	
}
int main() {
	string array[4] = { "Tom","Jack","Mary","John"};
	cout << SumArray(array,array+4) << endl;
	int a[4] = { 1, 2, 3, 4};  //��ʾ��1+2+3+4 = 10
	cout << SumArray(a,a+4) << endl;
	return 0;
} 

