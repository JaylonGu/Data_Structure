
/*
3) �Լ���дһ���ܶ��κ����͵�������������mysort����ģ�棬��������ʹ��:
	
4 8 10 11 123
123 11 10 8 4
1.400000 1.200000 1.800000 3.100000 3.200000 2.100000


��ʾ:
1> an �� an + NUM ��������Ȼ��һ���ģ����� int *
2> mysort���õڶ���������ȥ��һ������������֪��Ҫ�����Ԫ���м���
3> mysort(an,an+NUM,Greater1) �ᵼ�� Greater1��mysort�ڲ������ã������Ƚ�Ԫ�ش�С����˻���һ�º���ָ����÷�


	
*/
#include <iostream>
using namespace std;

bool Greater2(int n1,int n2) 
{
	return n1 > n2;
}
bool Greater1(int n1,int n2) 
{
	return n1 < n2;
}
bool Greater3(double d1,double d2)
{
	return d1 < d2;
}

template <class T1,class T2>
void mysort(
//your code starts here
 T1 * start , T1 * end, T2 myless )
{
	int size = end - start;
	for( int i = size -1;i >= 0 ; --i ) {
		for( int j = 0; j < i ; ++j ) {
			if(  myless( start[j+1],start[j] )) {
				T1 tmp = start[j];
				start[j] = start[j+1];
				start[j+1] = tmp; 
			}
		}
	}
}
/*��2 ��
template<class T>
void Swap( T & a, T & b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template <class T1,class T2>
void mysort( T1  start , T1  end, T2 myless )
{
	int size = end - start;
	for( int i = size -1;i >= 0 ; --i ) {
		for( int j = 0; j < i ; ++j ) {
			if(  myless( * ( start + j+1), * (start+j) )) {
				Swap(* ( start + j+1), * (start+j) );
			}
		}
	}
}
�� 3 
template <class T1,class T2>
void mysort( T1  start , T1  end, T2 myless )
{
	int size = end - start;
	for( int i = size -1;i >= 0 ; --i ) {
		for( int j = 0; j < i ; ++j ) {
			if(  myless( * ( start + j+1), * (start+j) )) {
				auto tmp = * ( start+j);
				* ( start +j ) = * ( start + j+1);
				* ( start + j+1)  = tmp; 
			}
		}
	}
}

*/

//your code ends here

#define NUM 5
int main()
{
    int an[NUM] = { 8,123,11,10,4 };
    mysort(an,an+NUM,Greater1); //��С�������� 
    for( int i = 0;i < NUM; i ++ )
       cout << an[i] << ",";
    mysort(an,an+NUM,Greater2); //�Ӵ�С���� 
    cout << endl;
    for( int i = 0;i < NUM; i ++ )
        cout << an[i] << ","; 
    cout << endl;
    double d[6] = { 1.4,1.8,3.2,1.2,3.1,2.1};
    mysort(d+1,d+5,Greater3); //��������±�1���±�4��С�������� 
    for( int i = 0;i < 6; i ++ )
         cout << d[i] << ","; 
	return 0;
}

