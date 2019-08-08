/*
003:月度开销
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
农夫约翰是一个精明的会计师。他意识到自己可能没有足够的钱来维持农场的运转了。他计算出并记录下了接下来 N (1 ≤ N ≤ 100,000) 天里每天需要的开销。

约翰打算为连续的M (1 ≤ M ≤ N) 个财政周期创建预算案，他把一个财政周期命名为fajo月。每个fajo月包含一天或连续的多天，每天被恰好包含在一个fajo月里。

约翰的目标是合理安排每个fajo月包含的天数，使得开销最多的fajo月的开销尽可能少。



输入
第一行包含两个整数N,M，用单个空格隔开。
接下来N行，每行包含一个1到10000之间的整数，按顺序给出接下来N天里每天的开销。
输出
一个整数，即最大月度开销的最小值。
样例输入
7 5
100
400
300
100
500
101
400
样例输出
500
提示
若约翰将前两天作为一个月，第三、四两天作为一个月，最后三天每天作为一个月，则最大月度开销为500。其他任何分配方案都会比这个值更大。
*/

#include <cstdio>

int main(){
    // freopen("in_3","r",stdin);
    int N,M;
    scanf("%d %d",&N,&M);
    int* pay=new int[N];
    for(int i=0;i<N;++i) scanf("%d",&pay[i]);
    int max=pay[0],sum=pay[0];
    for(int i=1;i<N;++i){
        if(pay[i]>max) max=pay[i];
        sum+=pay[i];
    }
    int L=max, R=sum, mid, minmax=sum;

    int count=0;

    while(L<=R){
        mid=L+(R-L)/2;

        int fnum=1, fee=0;
        for(int i=0;i<N;++i){
            if(fee+pay[i]>mid){
                fee=pay[i];
                fnum++;
            }else
            {
                fee+=pay[i];
            }            
        }

        // printf("L=%d, R=%d, mid=%d, minmax=%d, fnum=%d\n",L,R,mid,minmax,fnum);

        if(fnum>M) L=mid+1;
        else{
            R=mid-1;
            minmax=mid;
        } 
    }

    printf("%d",minmax);
    return 0;
}