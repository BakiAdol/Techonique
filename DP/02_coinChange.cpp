/*
* Minimum coin need for make chane a certain ammount, unsing recursive approach
* Complexity O(2^coins) probably
*/
int minimumCoin(int amount, int coins[], int numOfCoins)
{
    if(amount==0) return 0;
    int res=INT_MAX;
    for(int coin=0;coin<numOfCoins;coin++)
    {
        if(coins[coin]<=amount)
        {
            int sub_res=minimumCoin(amount-coins[coin],coins,numOfCoins);

            if(sub_res<res) res=sub_res+1;
        }
    }
    return res;
}
//--------------------------------------------------------------------------------------------
/*
* Minimum coin need for make chane a certain ammount, unsing Bottom-Up Dynamic Techonic
* Complexity O(amount*coins)
*/
int minimumCoin(int amount, int coins[], int numOfCoins)
{
    int requariedCoin[amount+1];
    requariedCoin[0]=0;

    for(int am=1;am<=amount;am++)
    {
        requariedCoin[am]=INT_MAX;
        for(int coin=0;coin<numOfCoins;coin++)
        {
            requariedCoin[am]=min(requariedCoin[am],requariedCoin[am-coins[coin]]+1);
        }
    }
    return requariedCoin[amount];
}
//--------------------------------------------------------------------------------------------

/*
* Recursive approach
* Total waya of make amount using coins(coins not followed order)
* Complexity O(2^n)
*/
int coinCombo(int amount, int coins[], int lenOfCoins)
{
    if(amount==0) return 1;
    if(amount<0) return 0;
    int combo=0;
    for(int i=0;i<lenOfCoins;i++)
    {
        combo+= coinCombo(amount-coins[i],coins,lenOfCoins);
    }
    return combo;
}
//--------------------------------------------------------------------------------------------

/*
* Recursive approach
* Total waya of make amount using coins(coins followed order)
* Complexity O(2^n)
*/
int coinCombo(int amount, int coins[], int lenOfCoins, int courrent)
{
    if(amount==0) return 1;
    if(amount<0) return 0;
    int combo=0;
    for(int i=courrent;i<lenOfCoins;i++)
    {
        combo+=coinCombo(amount-coins[i],coins,lenOfCoins,i);
    }
    return combo;
}
//--------------------------------------------------------------------------------------------

/*
* Dynamic Programing Bottom-Up approach
* Total waya of make amount using coins(coins followed order)
* 
*/
int coinCombo(int amount, int coins[], int lenOfCoins)
{
    int dp[lenOfCoins+1][amount+1];

    for(int am=0;am<=amount;am++) dp[0][am]=0;
    for(int coin=0;coin<=lenOfCoins;coin++) dp[coin][0]=1;

    for(int coin=1;coin<=lenOfCoins;coin++)
    {
        for(int am=1;am<=amount;am++)
        {
            if(coins[coin-1]<=am)
            {
                dp[coin][am]=dp[coin-1][am]+dp[coin][am-coins[coin-1]];
                continue;
            }
            dp[coin][am]=dp[coin-1][am];
        }
    }

    return dp[lenOfCoins][amount];
}
//--------------------------------------------------------------------------------------------

