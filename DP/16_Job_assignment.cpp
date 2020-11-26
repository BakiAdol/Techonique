#include<bits/stdc++.h>

/**
 * Job Assignment
 * There are n job and n people. You are given cost of assign a people in each job. Your task is to
 * calculate the minimum cost of assing each person in a job. Diffrent people can assign in diffrent job.
 * */

using namespace std;

int cost[4][4]={{9,6,7,8},
			  {3,2,7,3},
			  {1,9,4,2},
			  {6,5,4,3}};
int n;
int memo[20][(1<<21)];

int f(int pos, int mask)
{
	if(pos==n) return 0;
	
	int &ret=memo[pos][mask];
	if(ret!=-1) return ret;
	
	int ans=INT_MAX;
	
	for(int i=0;i<n;i++)
	{
		if(!(mask&(1<<i)))
		{
			ans=min(ans,cost[pos][i]+f(pos+1,mask|(1<<i)));
		}
	}
	
	return ret=ans;
}

int main()
{
	memset(memo,-1,sizeof(memo));
	n=4;
	
	cout << f(0,0) << endl;

	return 0;
}

