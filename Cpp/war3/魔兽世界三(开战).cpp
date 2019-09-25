/*
1:魔兽世界三(开战)
查看提交统计提问
总时间限制: 2000ms 内存限制: 65536kB
描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市，城市从西向东依次编号为1,2,3 .... N ( N <= 20)。红魔军的司令部算作编号为0的城市，蓝魔军的司令部算作编号为N+1的城市。司令部有生命元，用于制造武士。


两军的司令部都会制造武士。武士一共有dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。


双方的武士编号都是从1开始计算。红方制造出来的第n 个武士，编号就是n。同样，蓝方制造出来的第n 个武士，编号也是n。


武士在刚降生的时候有一个初始的生命值，生命值在战斗中会发生变化，如果生命值减少到0（生命值变为负数时应当做变为0处理），则武士死亡（消失）。

武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。

sword的攻击力是使用者当前攻击力的20%(去尾取整)。

bomb的攻击力是使用者当前攻击力的40%(去尾取整)，但是也会导致使用者受到攻击，对使用者的攻击力是对敌人取整后的攻击力的1/2(去尾取整)。Bomb一旦使用就没了。

arrow的攻击力是使用者当前攻击力的30%(去尾取整)。一个arrow用两次就没了。



武士降生后就朝对方司令部走，在经过的城市如果遇到敌人（同一时刻每个城市最多只可能有1个蓝武士和一个红武士），就会发生战斗。战斗的规则是：

在奇数编号城市，红武士先发起攻击

在偶数编号城市，蓝武士先发起攻击

战斗开始前，双方先对自己的武器排好使用顺序，然后再一件一件地按顺序使用。编号小的武器，排在前面。若有多支arrow，用过的排在前面。排好序后，攻击者按此排序依次对敌人一件一件地使用武器。如果一种武器有多件，那就都要用上。每使用一件武器，被攻击者生命值要减去武器攻击力。如果任何一方生命值减为0或小于0即为死去。有一方死去，则战斗结束。

双方轮流使用武器，甲用过一件，就轮到乙用。某一方把自己所有的武器都用过一轮后，就从头开始再用一轮。如果某一方没有武器了，那就挨打直到死去或敌人武器用完。武器排序只在战斗前进行，战斗中不会重新排序。

如果双方武器都用完且都还活着，则战斗以平局结束。如果双方都死了，也算平局。

有可能由于武士自身攻击力太低，而导致武器攻击力为0。攻击力为0的武器也要使用。如果战斗中双方的生命值和武器的状态都不再发生变化，则战斗结束，算平局。

战斗的胜方获得对方手里的武器。武士手里武器总数不超过10件。缴获武器时，按照武器种类编号从小到大缴获。如果有多件arrow，优先缴获没用过的。

如果战斗开始前双方都没有武器，则战斗视为平局。如果先攻击方没有武器，则由后攻击方攻击。

不同的武士有不同的特点。

编号为n的dragon降生时即获得编号为n%3 的武器。dragon在战斗结束后，如果还没有战死，就会欢呼。


编号为n的ninjia降生时即获得编号为n%3 和(n+1)%3的武器。ninja 使用bomb不会让自己受伤。


编号为n的iceman降生时即获得编号为n%3 的武器。iceman每前进一步，生命值减少10%(减少的量要去尾取整)。


编号为n的lion降生时即获得编号为n%3 的武器。lion 有“忠诚度”这个属性，其初始值等于它降生之后其司令部剩余生命元的数目。每前进一步忠诚度就降低K。忠诚度降至0或0以下，则该lion逃离战场,永远消失。但是已经到达敌人司令部的lion不会逃跑。lion在己方司令部可能逃跑。


wolf降生时没有武器，但是在战斗开始前会抢到敌人编号最小的那种武器。如果敌人有多件这样的武器，则全部抢来。Wolf手里武器也不能超过10件。如果敌人arrow太多没法都抢来，那就先抢没用过的。如果敌人也是wolf，则不抢武器。


以下是不同时间会发生的不同事件：


在每个整点，即每个小时的第0分， 双方的司令部中各有一个武士降生。


红方司令部按照iceman、lion、wolf、ninja、dragon 的顺序制造武士。


蓝方司令部按照lion、dragon、ninja、iceman、wolf 的顺序制造武士。


制造武士需要生命元。


制造一个初始生命值为m 的武士，司令部中的生命元就要减少m 个。


如果司令部中的生命元不足以制造某本该造的武士，那就从此停止制造武士。


在每个小时的第5分，该逃跑的lion就在这一时刻逃跑了。


在每个小时的第10分：所有的武士朝敌人司令部方向前进一步。即从己方司令部走到相邻城市，或从一个城市走到下一个城市。或从和敌军司令部相邻的城市到达敌军司令部。


在每个小时的第35分：在有wolf及其敌人的城市，wolf要抢夺对方的武器。


在每个小时的第40分：在有两个武士的城市，会发生战斗。


在每个小时的第50分，司令部报告它拥有的生命元数量。


在每个小时的第55分，每个武士报告其拥有的武器情况。


武士到达对方司令部后就算完成任务了，从此就呆在那里无所事事。


任何一方的司令部里若是出现了敌人，则认为该司令部已被敌人占领。

任何一方的司令部被敌人占领，则战争结束。战争结束之后就不会发生任何事情了。


给定一个时间，要求你将从0点0分开始到此时间为止的所有事件按顺序输出。事件及其对应的输出样例如下：


1) 武士降生

输出样例：000:00 blue dragon 1 born

表示在0点0分，编号为1的蓝魔dragon武士降生


如果造出的是lion，那么还要多输出一行，例:

000:00 blue lion 1 born

Its loyalty is 24

表示该lion降生时的忠诚度是24


2) lion逃跑

输出样例：000:05 blue lion 1 ran away

表示在0点5分，编号为1的蓝魔lion武士逃走


3) 武士前进到某一城市


输出样例：



000:10 red iceman 1 marched to city 1 with 20 elements and force 30

表示在0点10分，红魔1号武士iceman前进到1号城市，此时他生命值为20,攻击力为30

对于iceman,输出的生命值应该是变化后的数值


4) wolf抢敌人的武器

000:35 blue wolf 2 took 3 bomb from red dragon 2 in city 4

表示在0点35分，4号城市中，红魔1号武士wolf 抢走蓝魔2号武士dragon 3个bomb。为简单起见，武器不写复数形式


5) 报告战斗情况

战斗只有3种可能的输出结果：


000:40 red iceman 1 killed blue lion 12 in city 2 remaining 20 elements

表示在0点40分，1号城市中，红魔1号武士iceman 杀死蓝魔12号武士lion后，剩下生命值20


000:40 both red iceman 1 and blue lion 12 died in city 2

注意，把红武士写前面

000:40 both red iceman 1 and blue lion 12 were alive in city 2

注意，把红武士写前面


6) 武士欢呼

输出样例：003:40 blue dragon 2 yelled in city 4


7) 武士抵达敌军司令部

输出样例：001:10 red iceman 1 reached blue headquarter with 20 elements and force 30

（此时他生命值为20,攻击力为30）对于iceman,输出的生命值和攻击力应该是变化后的数值


8) 司令部被占领

输出样例：003:10 blue headquarter was taken


9)司令部报告生命元数量

000:50 100 elements in red headquarter

000:50 120 elements in blue headquarter

表示在0点50分，红方司令部有100个生命元，蓝方有120个


10)武士报告情况

000:55 blue wolf 2 has 2 sword 3 bomb 0 arrow and 7 elements

为简单起见，武器都不写复数形式。elements一律写复数，哪怕只有1个


交代武器情况时，次序依次是：sword,bomb, arrow。


输出事件时：


首先按时间顺序输出；

同一时间发生的事件，按发生地点从西向东依次输出. 武士前进的事件, 算是发生在目的地。

在一次战斗中有可能发生上面的 5 至 6 号事件。这些事件都算同时发生，其时间就是战斗开始时间。一次战斗中的这些事件，序号小的应该先输出。

两个武士同时抵达同一城市，则先输出红武士的前进事件，后输出蓝武士的。

对于同一城市，同一时间发生的事情，先输出红方的，后输出蓝方的。

显然，8号事件发生之前的一瞬间一定发生了7号事件。输出时，这两件事算同一时间发生，但是应先输出7号事件

虽然任何一方的司令部被占领之后，就不会有任何事情发生了。但和司令部被占领同时发生的事件，全都要输出。



输入
第一行是t,代表测试数据组数

每组样例共三行。

第一行，4个整数 M,N,K, T。其含义为：
每个司令部一开始都有M个生命元( 1 <= M <= 100000)
两个司令部之间一共有N个城市( 1 <= N <= 20 )
lion每前进一步，忠诚度就降低K。(0<=K<=100)
要求输出从0时0分开始，到时间T为止(包括T) 的所有事件。T以分钟为单位，0 <= T <= 6000

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于200

第三行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的攻击力。它们都大于0小于等于200
输出
对每组数据，先输出一行：

Case n:

如对第一组数据就输出 Case 1:

然后按恰当的顺序和格式输出到时间T为止发生的所有事件。每个事件都以事件发生的时间开头，时间格式是“时: 分”，“时”有三位，“分”有两位。
样例输入
1
20 1 10 400
20 20 30 10 20
5 5 5 5 5
样例输出
Case 1:
000:00 blue lion 1 born
Its loyalty is 10
000:10 blue lion 1 marched to city 1 with 10 elements and force 5
000:50 20 elements in red headquarter
000:50 10 elements in blue headquarter
000:55 blue lion 1 has 0 sword 1 bomb 0 arrow and 10 elements
001:05 blue lion 1 ran away
001:50 20 elements in red headquarter
001:50 10 elements in blue headquarter
002:50 20 elements in red headquarter
002:50 10 elements in blue headquarter
003:50 20 elements in red headquarter
003:50 10 elements in blue headquarter
004:50 20 elements in red headquarter
004:50 10 elements in blue headquarter
005:50 20 elements in red headquarter
005:50 10 elements in blue headquarter
提示
请注意浮点数精度误差问题。OJ上的编译器编译出来的可执行程序，在这方面和你电脑上执行的程序很可能会不一致。5 * 0.3 的结果，有的机器上可能是 15.00000001，去尾取整得到15,有的机器上可能是14.9999999，去尾取整后就变成14。因此,本题不要写 5 * 0.3，要写 5 * 3 / 10。
来源
Guo Wei
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int life[5]; // dragon 、ninja、iceman、lion、wolf
int atk[5];
string wrname[5]{"dragon","ninja","iceman","lion","wolf"};
string wpname[3]{"sword","bomb","arrow"};

// 每个司令部一开始都有M个生命元
// 两个司令部之间一共有N个城市
// lion每前进一步，忠诚度就降低K
// 要求输出从0时0分开始，到时间T为止(包括T) 的所有事件
int M,N,T;

class worrier{
public:
    int life, atk, city, id;
    int weapon[4]{0}; // sword,bomb,arrow,arrow_used
    int wp_amount;
    
    int getweapon(int n){

    }
};

class dragon: public worrier{

};

class ninja: public worrier{

};

class iceman: public worrier{

};

class lion: public worrier{
public:
    static int K;
};

int lion::K=0;

class wolf: public worrier{

};

inline void Input(){
    cin>>M>>N>>lion::K>>T;
    for(int i=0;i<5;++i) cin>>life[i];
    for(int i=0;i<5;++i) cin>>atk[i];
}

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;++i){
        Input();
        cout<<"Case "<<i<<":\n";

    }
    return 0;
}