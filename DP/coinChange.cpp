// total waya of make amount using coins not followed order
// Complexity O(2^n)
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

// total waya of make amount using coins followed order
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
