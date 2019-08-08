/*
003:石头剪子布
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
石头剪子布，是一种猜拳游戏。起源于中国，然后传到日本、朝鲜等地，随着亚欧贸易的不断发展它传到了欧洲，到了近现代逐渐风靡世界。简单明了的规则，使得石头剪子布没有任何规则漏洞可钻，单次玩法比拼运气，多回合玩法比拼心理博弈，使得石头剪子布这个古老的游戏同时用于“意外”与“技术”两种特性，深受世界人民喜爱。 

游戏规则：石头打剪刀，布包石头，剪刀剪布。 

现在，需要你写一个程序来判断石头剪子布游戏的结果。

输入
输入包括N+1行：
第一行是一个整数N，表示一共进行了N次游戏。1 <= N <= 100。
接下来N行的每一行包括两个字符串，表示游戏参与者Player1，Player2的选择（石头、剪子或者是布）：
S1 S2
字符串之间以空格隔开S1,S2只可能取值在{"Rock", "Scissors", "Paper"}（大小写敏感）中。
输出
输出包括N行，每一行对应一个胜利者（Player1或者Player2），或者游戏出现平局，则输出Tie。
样例输入
3
Rock Scissors
Paper Paper
Rock Paper
样例输出
Player1
Tie
Player2
提示
Rock是石头，Scissors是剪刀，Paper是布。
*/

#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        char p1[10],p2[10];
        cin>>p1>>p2;
        if(p1[0]==p2[0]) cout<<"Tie"<<endl;
        else if(p1[0]=='R') {
            if(p2[0]=='S') cout<<"Player1"<<endl;
            if(p2[0]=='P') cout<<"Player2"<<endl;
        }else if(p1[0]=='S'){
            if(p2[0]=='R') cout<<"Player2"<<endl;
            if(p2[0]=='P') cout<<"Player1"<<endl;
        }else{
            if(p2[0]=='R') cout<<"Player1"<<endl;
            if(p2[0]=='S') cout<<"Player2"<<endl;
        }
    }
    return 0;
}
