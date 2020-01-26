#include <bits/stdc++.h>

using namespace std;

int dp[20][20];

int ncr(int n, int r)
{
    if(n==r) return 1;
    if(r==1) return n;
    if(dp[n][r]) return dp[n][r];
    return dp[n][r]=ncr(n-1,r-1)+ncr(n-1,r);
}

int main()
{
    cout << "Combination of 5 numbers from 10 numbers: "<< ncr(10,5) << endl;
    return 0;
}


