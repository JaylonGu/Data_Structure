/*
002:求一元二次方程的根
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
利用公式x1 = (-b + sqrt(b*b-4*a*c))/(2*a), x2 = (-b - sqrt(b*b-4*a*c))/(2*a)求一元二次方程ax2+ bx + c =0的根，其中a不等于0。

输入
输入一行，包含三个浮点数a, b, c（它们之间以一个空格分开），分别表示方程ax2 + bx + c =0的系数。
输出
输出一行，表示方程的解。
若b2 = 4 * a * c,则两个实根相等，则输出形式为：x1=x2=...。
若b2 > 4 * a * c,则两个实根不等，则输出形式为：x1=...;x2 = ...，其中x1>x2。
若b2 < 4 * a * c，则有两个虚根，则输出：x1=实部+虚部i; x2=实部-虚部i，即x1的虚部系数大于等于x2的虚部系数，实部为0时不可省略。实部 = -b / (2*a), 虚部 = sqrt(4*a*c-b*b) / (2*a)

所有实数部分要求精确到小数点后5位，数字、符号之间没有空格。
样例输入
样例输入1
1.0 2.0 8.0

样例输入2
1 0 1
样例输出
样例输出1
x1=-1.00000+2.64575i;x2=-1.00000-2.64575i

样例输出2
x1=0.00000+1.00000i;x2=0.00000-1.00000i
*/

#include <iostream>
#include <cmath>
#define eps 1e-6
using namespace std;

double real(double a, double b){
    double x=-b/(2*a);
    if(x>-eps) x=abs(x);
    return x;
}

double img(double a,double delta){
    double x=sqrt(delta)/(2*a);
    return abs(x);
}

int main(){
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    double delta=b*b-4*a*c;
    if(delta>eps) printf("x1=%.5f;x2=%.5f",real(a,b)+img(a,delta),real(a,b)-img(a,delta));
    else if(delta < -eps) printf("x1=%.5f+%.5fi;x2=%.5f-%.5fi",real(a,b),img(a,-delta),real(a,b),img(a,-delta));
    else printf("x1=x2=%.5f",real(a,b));
    return 0;
}