/*
* Fractional Knapsack
*/
         price  weight
typedef pair<int, int> pp;

bool cmp(pp a, pp b)
{
    return a.first*b.second > b.first*a.second;
}

int fractionalKnapsack(vector<pp> items, int W) 
{
    int totalValue=0;
    sort(items.begin(),items.end(),cmp);
    for(int i=0;i<(int)items.size() && W>0;i++)
    {
        cout << items[i].first << endl;
        int take=min(W,items[i].second);
        totalValue+=items[i].first*take;  // given price per kg/weight
        W-=take;
    }
    return totalValue;
}
//........................................................................................
