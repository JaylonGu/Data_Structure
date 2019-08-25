/*01:分段函数
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
编写程序，计算下列分段函数y=f(x)的值。

y=-x+2.5; 0 <= x < 5

y=2-1.5(x-3)(x-3); 5 <= x < 10

y=x/2-1.5; 10 <= x < 20

输入
一个浮点数N,0 <= N < 20
输出
输出N对应的分段函数值：f(N)。结果保留到小数点后三位。
样例输入
1.0
样例输出
1.500
*/

#include <cstdio>

int main(){
    float x,y;
    scanf("%f",&x);
    if(x<5){
        y=-x+2.5;
    }else if(x<10){
        y=2-1.5*(x-3)*(x-3);
    }else{
        y=x/2-1.5;
    }

    printf("%.3f",y);

    return 0;
}