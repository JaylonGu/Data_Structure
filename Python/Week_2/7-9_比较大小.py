'''
本题要求将输入的任意3个整数从小到大输出。

输入格式:
输入在一行中给出3个整数，其间以空格分隔。

输出格式:
在一行中将3个整数从小到大输出，其间以“->”相连。

输入样例:
4 2 8
输出样例:
2->4->8
'''

x = input().split()
x = list(int(i) for i in x)
x.sort()
print("{}->{}->{}".format(x[0],x[1],x[2]))