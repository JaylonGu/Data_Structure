//by Guo Wei
#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
map<int,set<int> > mp;
//second �� ʵ��Ϊ first��id�ļ��� 
int main()
{
	set<int> st;
	st.insert(1);
	mp.insert(make_pair(1000000000,st)); 
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n; ++i) {
		int id,power;
		scanf("%d%d",&id,&power);
		map<int,set<int> >::iterator pL = mp.lower_bound(power);
		if( pL == mp.end()) 
			//�������е��˵�ʵ������ powerС 
			printf("%d %d\n",id ,* (mp.rbegin()->second.begin()));
		else if( pL == mp.begin()) 
			//�������е��˵�ʵ�������ڵ��� power
			printf("%d %d\n",id,* (mp.begin()->second.begin()));
		else {
			if( pL->first == power) 
				printf("%d %d\n",id,* (pL->second.begin()));
			else {
				int d1 = abs(pL->first - power);
				map<int,set<int> >::iterator p = pL;
				--p;
				int d2 =  abs(p->first - power);
				if( d1 < d2 ) 
					printf("%d %d\n",id, * (pL->second.begin()));
				else if( d1 > d2) 
					printf("%d %d\n",id,* (p->second.begin()));
				else {
					printf("%d %d\n",id ,min(*(pL->second.begin()),*(p->second.begin())));
				}
			}
		}
		mp[power].insert(id);
	}
	return 0;
}
