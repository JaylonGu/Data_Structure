/*
������գ���Ҫ�����


����
��һ��������t����ʾ��t������
ÿ������һ�У����������������ַ������ַ����ǲ����ո��

�����

��ÿ�����ݣ�������� 
�ڵ�һ�������һ����
�ڶ���ԭ��������������

�������� 
2
79 90 20 hello me
12 34 19 take up

���������

79
79 90 20 hello me
12
12 34 19 take up

��ʾ��


C++��׼ģ��� istream_iteratorģ��ʹ��˵����

�乹�캯��ִ�й����оͻ�Ҫ�����룬Ȼ��ÿ��ִ��++�����ȡ�������е���һ����Ŀ��ִ�� * �򷵻��ϴδ��������ж�ȡ����Ŀ�����磬�����������ʱ���ͻ�ȴ��û��������ݣ��������ݺ����Ż������
#include <iostream>
#include <iterator>
using namespace std;
int main()  { 
	 istream_iterator<int> inputInt(cin);
	 return 0;  
}

�����������ʱ��������� 12   34  �����������ǣ� 12,12
#include <iostream>
#include <iterator>
using namespace std;
int main()  
{ 
	 istream_iterator<int> inputInt(cin);
	 cout << * inputInt << "," << * inputInt << endl;
	 return 0;  
}

�����������ʱ��������� 12   34   56�����������ǣ� 12,56
#include <iostream>
#include <iterator>
using namespace std;
int main()  
{ 
	 istream_iterator<int> inputInt(cin);
	 cout << * inputInt << "," ;
	 inputInt ++;
	 inputInt ++;
	 cout << * inputInt;
	 return 0;  
}
 

*/


#include <iostream>
#include <string>

using namespace std;
template <class T>
class CMyistream_iterator
{
//your code starts here	
	istream &  r;
	T v;
	public:
		T operator *() {
			return v;	
		}
		CMyistream_iterator( istream & rr):r(rr) {
			r >> v ;
		}
		void operator ++ (int) {
			 r >> v ;
		}
//your code ends here		
};



int main()  
{ 
	int t;
	cin >> t;
	while( t -- ) {
		 CMyistream_iterator<int> inputInt(cin);
		 int n1,n2,n3;
		 n1 = * inputInt; //���� n1
		 int tmp = * inputInt;
		 cout << tmp << endl;
		 inputInt ++;   
		 n2 = * inputInt; //���� n2
		 inputInt ++;
		 n3 = * inputInt; //���� n3
		 cout << n1 << " " << n2<< " " << n3 << " ";
		 CMyistream_iterator<string> inputStr(cin);
		 string s1,s2;
		 s1 = * inputStr;
		 inputStr ++;
		 s2 = * inputStr;
		 cout << s1 << " " << s2 << endl;
	}
	 return 0;  
}

