/*������գ�ʹ������������������:


(Tom,80),(Tom,70),(Jone,90),(Jack,70),(Alice,100),
(Tom,78),(Tom,78),(Jone,90),(Jack,70),(Alice,100),
(70,Jack),(70,Tom),(80,Tom),(90,Jone),(100,Alice),
(70,Error),(70,Error),(80,Tom),(90,Jone),(100,Alice),

*/

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;
//your code starts here

template <class Key,class T,class Pred = greater<Key> >
class MyMultimap:public multimap<Key,T,Pred> {
	public:
		
		void Set(Key k,T v) {
			typename multimap<Key,T,Pred>::iterator l = 
			multimap<Key,T,Pred>::lower_bound(k);
			typename multimap<Key,T,Pred>::iterator u = 
			multimap<Key,T,Pred>::upper_bound(k);
			for(;l!=u;++l) {
				l->second = v;
			}
		}
};

template <class F,class S>
ostream & operator << (ostream & o,const pair<F,S> & s) {
	o << "(" << s.first  << "," << s.second << ")";
	return o;
}
//your code ends here
struct Student 
{
	string name;
	int score;
};
template <class T>
void Print(T first,T last) {
	for(;first!= last; ++ first)
		cout << * first << ",";
	cout << endl;
}
int main()
{
	
	Student s[] = { {"Tom",80},{"Jack",70},
					{"Jone",90},{"Tom",70},{"Alice",100} };
	
	MyMultimap<string,int> mp;
	for(int i = 0; i<5; ++ i)
		mp.insert(make_pair(s[i].name,s[i].score));
	Print(mp.begin(),mp.end()); //�������Ӵ�С���

	mp.Set("Tom",78); //��������Ϊ"Tom"��ѧ���ĳɼ�������Ϊ78
	Print(mp.begin(),mp.end());
	
	
	
	MyMultimap<int,string,less<int> > mp2;
	for(int i = 0; i<5; ++ i)
		mp2.insert(make_pair(s[i].score,s[i].name));
	
	Print(mp2.begin(),mp2.end()); //���ɼ���С�������
	mp2.Set(70,"Error");          //�����гɼ�Ϊ70��ѧ�������ֶ���Ϊ"Error"
	Print(mp2.begin(),mp2.end());
	
	return 0;
}

