/**
*    How many ways you can make n, using 1 to n numbers. Followed order.
*    n=5
*    2+3=5
*    1+4=5
*    5  =5
*    Total 3 ways 5 can make.
**/
#include <bits/stdc++.h>

using namespace std;

long long mem[510][510];

long long make(int previous, int remain)
{
    if(remain==0) return 1;
    if(previous>=remain) return 0;
    if(mem[previous][remain]) return mem[previous][remain];
    long long res=0;
    for(int i=previous+1;i<=remain;i++)
    {
        res+=make(i,remain-i);
    }
    return mem[previous][remain]=res;
}

int main()
{
    int n;
    cin >> n;
    cout << make(0,n) << endl;
    return 0;
}

