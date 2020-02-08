// 0/1 knapsack naive recursion approach

int weight[]={5,3,5,3,2};
int n=5;

int knapsack(int pos, int space)
{
    if(pos>=n or space==0) return 0; // base case, if knapsack is full of array index exceeded

    if(weight[pos]>space) return knapsack(pos+1,space); // if item weight is greater than knapsack weight

    return max(knapsack(pos+1,space),weight[pos]+knapsack(pos+1,space-weight[pos]));
    // return the maximum result of include this item or not include this item
}

// DP approach
int weight[]={0,5,7,2,6,8};
int n=5;
int dp[50][50]; // initially dp=[0];

int knapsack(int pos, int space) // first call pos=n
{
    if(dp[pos][space]) return dp[pos][space];

    if(pos==0 or space==0) return 0; // base case, if knapsack is full of array index is 0

    if(weight[pos]>space) return dp[pos][space]=knapsack(pos-1,space); // if item weight is greater than knapsack weight

    return dp[pos][space]=max(knapsack(pos-1,space),weight[pos]+knapsack(pos-1,space-weight[pos]));
    // return the maximum result of include this item or not include this item
}

