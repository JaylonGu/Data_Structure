// д��������ȱʧ�Ĳ��֣�ʹ�ú�������ֵΪһ������,�����������iλ��n�����iλȡ��������λ��n��ͬ
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int bitManipulation3(int n, int i) {
//your code starts here
	return n ^ (~0 << (32 - i)) ;
//your code ends here
}

int main() {
	int t, n, i;
	cin >> t;
	while (t--) {
		cin >> n >> i;
		cout << bitManipulation3(n, i) << endl;
	}
	return 0;
}
