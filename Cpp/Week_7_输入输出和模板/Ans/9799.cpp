/*
������������������������� ,ֱ������-1

����

�������ݣ�ÿ��һ�У�����������

���

��ÿ�����ݣ�ԭ����� 
�����������г���-1 ʱ��������� 
�����б�֤���� -1 


��������

12 44
344 555
-1
2 3

������� 

12 44
344 555


*/
#include <iostream>
using namespace std;
class MyCin
{
	//your code starts here
    bool valid;    
    public:
        MyCin():valid(true) { }
        operator bool( ) { //��������ǿ��ת������� bool
            return valid; 
        }
        MyCin & operator >> (int & n)
        {
            cin >> n;
            if( n == -1 )
            	valid = false;
            
            return * this;
        }
//your code ends here        
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) 
        cout  << n1 << " " << n2 << endl;
    return 0;
}

