// 0/1 knapsack naive recursion approach

int weight[]={5,3,5,3,2};
int n=5;

int knapsack(int pos, int space)
{
    if(pos>=n or space==0) return 0; // base case, if knapsack is full or array index exceeded

    if(weight[pos]>space) return knapsack(pos+1,space); // if item weight is greater than knapsack weight

    return max(knapsack(pos+1,space),weight[pos]+knapsack(pos+1,space-weight[pos]));
    // return the maximum result of include this item or not include this item
}

// DP Top Down approach
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


//DP Bottom UP approach
#define lli 				long long int
int n,weight;
lli weights[100005],value[100005];
lli memo[105][100005];
lli bottomUp()
{
	for(lli i=0;i<=n;i++)
	{
		for(lli j=0;j<=weight;j++)
		{
			if(i==0 or j==0) memo[i][j]=0;
			else
			{
				if(weights[i]>j) memo[i][j]=memo[i-1][j];
				else memo[i][j]=max(memo[i-1][j-weights[i]]+value[i],memo[i-1][j]);
			}
		}
	}
	
	return memo[n][weight];
}



