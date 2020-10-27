#include<bits/stdc++.h>

using namespace std;

bool memo[100][500];

bool subsetSum(vector<int> nums, int sum)
{
	nums.insert(nums.begin(),0);
	int len=nums.size();
	
	for(int i=0;i<=len;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			if(j==0) memo[i][j]=true;
			else if(i==0) memo[i][j]=false;
			else if(nums[i]>j) memo[i][j]=memo[i-1][j];
			else memo[i][j]=memo[i-1][j-nums[i]] or memo[i-1][j];
		}
	}
	
	return memo[len][sum];
}

int main()
{
	vector<int> v={1,5,9,3};
	
	cout << subsetSum(v,10) << endl;
	
	return 0;
}

