//By Guo Wei
/*
Ϊ��ʹ�ñ������ÿ���ÿһ���¶�Ա����ѡ������ʵ����Ϊ�ӽ����˱�����������˫����ʵ��ֵ֮��ľ���ֵԽСԽ�ã�����������˵�ʵ��ֵ���������ͬ��������ѡ����������Ǹ�����Ȼ��Ű�˱ر�Ű�ã���
*/
#include <list>
#include <string>
#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
multimap<unsigned int,unsigned int> fights;
int main()
{
	unsigned int  n,id,force;
	//freopen("d:\\tmp\\warm.txt","r",stdin);
	scanf("%d",&n);
	fights.insert(make_pair(1000000000,1));
	while(n--)
	{
		scanf("%d%d",&id,&force);
		//pair< multimap<unsigned int,unsigned int>::iterator,bool > sp;
		multimap<unsigned int,unsigned int>::iterator sp,tmpp;
		sp = fights.insert(make_pair(force,id));
		multimap<unsigned int,unsigned int>::iterator p1,p2;
		if( sp == fights.begin()) {
			tmpp = fights.begin(); 
			tmpp ++;
			printf("%d %d\n",sp->second, tmpp->second);
		}
		else if( sp == (--fights.end()) ) {
			tmpp = sp; 
			tmpp --;

			printf("%d %d\n",sp->second, (tmpp)->second);
		}
		else {
			p1 = sp;
			p1 --;
			p2 = sp;
			p2 ++;	
			if( sp->first - p1->first  > ( p2->first - sp->first) )
				printf("%d %d\n",sp->second,p2->second);
			else
				printf("%d %d\n",sp->second,p1->second);
		}

	}

}
