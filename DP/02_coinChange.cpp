#include <bits/stdc++.h>

using namespace std;

// Minimum coin need to make a certain amount top-down dynamic programming approach
int memo[10000];
int minimumCoinToMakeChangeTopDown(int amount, vector<int> coins)
{
    if(amount==0) return 0;
    int cou=amount+1;
    if(memo[amount]!=0) return memo[amount];
    for(int coin:coins)
    {
        if(coin>amount) continue;
        cou = min(cou,minimumCoinToMakeChangeTopDown(amount-coin,coins)+1);
    }
    return memo[amount]=cou;
}

// Minimum coin need to make a certain amount bottom-up dynamic programming approach
int minimumCoinToMakeChangeBottomUp(int amount, vector<int> coins)
{
    vector<int> memo(amount+5,amount);
    memo[0]=0;
    for(int i=1;i<=amount;i++)
    {
        for(int coin:coins)
        {
            if(coin>i) continue;
            memo[i]=min(memo[i],memo[i-coin]+1);
        }
    }
    return memo[amount];
}

// Total unique way to make change amount top-down dynamic programming approach
vector<vector<int>> memo2(20, vector<int> (10000, -1));
int totalUniqueWayToMakeChangeTopDown(int amount, vector<int> coins, int pos=0)
{
    if(amount==0) return 1;
    if(amount<0) return 0;
    if(memo2[pos][amount]!=-1) return memo2[pos][amount];
    int way=0;
    for(int i=pos;i<(int)coins.size();i++)
    {
        way+=totalUniqueWayToMakeChangeTopDown(amount-coins[i],coins,i);
    }
    return memo2[pos][amount]=way;
}

// Total unique way to make change amount bottom-up dynamic programming approach
int totalUniqueWayToMakeChangeBottomUp(int amount, vector<int> coins)
{
    int lenOfCoin = coins.size();
    vector<vector<int>> memo(lenOfCoin+2, vector<int> (10000));

    for(int i=0;i<=amount;i++) memo[0][i]=0;
    for(int i=0;i<=lenOfCoin;i++) memo[i][0]=1;

    for (int coin=0;coin<lenOfCoin;coin++)
    {
        for (int am=1; am<=amount;am++)
        {
            memo[coin+1][am] = memo[coin][am]+(coins[coin]>am ? 0 : memo[coin+1][am-coins[coin]]);
        }
    }
    
    return memo[lenOfCoin][amount];
}


int main()
{
    vector<int> coins={1,2,5};
    int amount=20;
    cout << "Minimu coin need to make change(Top-Down) = " << minimumCoinToMakeChangeTopDown(amount,coins) << endl;
    cout << "Minimu coin need to make change(Bottom-Up) = " << minimumCoinToMakeChangeBottomUp(amount,coins) << endl;
    cout << "Total unique way to make change(Top-Down) = " << totalUniqueWayToMakeChangeTopDown(amount,coins) << endl;
    cout << "Total unique way to make change(Bottom-Up) = " << totalUniqueWayToMakeChangeBottomUp(amount,coins) << endl;

    return 0;
}
