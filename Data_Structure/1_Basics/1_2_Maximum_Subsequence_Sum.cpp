/*
01-复杂度2 Maximum Subsequence Sum (25分)
Given a sequence of K integers { N
​1
​​ , N
​2
​​ , ..., N
​K
​​  }. A continuous subsequence is defined to be { N
​i
​​ , N
​i+1
​​ , ..., N
​j
​​  } where 1≤i≤j≤K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:
Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (≤10000). The second line contains K numbers, separated by a space.

Output Specification:
For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
*/

#include <iostream>
using namespace std;

int main(){
    int Num=0;
    cin>>Num;
    int arrary[Num];
    for(int i=0; i<Num; ++i){
        cin>>arrary[i];
    }

    int SubSum=0;
    int MaxSum=-1;
    int IniNum=0;
    int TempNum=0;
    int EndNum=0;

// MaxSum & EndNum
    for(int i=0; i<Num; ++i){
        SubSum+=arrary[i];
        if(SubSum>MaxSum){
            MaxSum=SubSum;
            EndNum=i;
            IniNum=TempNum;
        }
        else if (SubSum<0){
            SubSum=0;
            TempNum=i+1;
        }
    }
// All negative
    if(MaxSum<0){
        MaxSum=0;
        IniNum=0;
        EndNum=Num-1;
    }

    cout<<MaxSum<<" "<<arrary[IniNum]<<" "<<arrary[EndNum];
    return 0;
}