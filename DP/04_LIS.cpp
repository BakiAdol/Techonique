#include <bits/stdc++.h>
using namespace std;

int ar[]={2,8,3,5,9,6,7,10};
int n=8;

// dp iterative method
void LISiter()
{
	int lis[8];
	for(int i=0;i<n;i++) lis[i]=1;
	int max_length=0;
	for(int i=0;i<n;i++)
    {
		for(int j=0;j<i;j++)
		{
			if(ar[j]<ar[i]) lis[i]=max(lis[i],lis[j]+1);
		}
		max_length=max(max_length,lis[i]);
	}
	cout << "Longest Increasing Subsequence length is " << max_length << endl;
}

// dp memorize approach
int memo[8];

int LISmemo(int pos)
{
	if(pos==0) return 1;
	if(memo[pos]) return memo[pos];
	int tmp=0;
	for(int i=pos-1;i>=0;i--)
	{
		if(ar[i]<ar[pos]) tmp=max(tmp,LISmemo(i)); 
	}
	return memo[pos]=tmp+1;
}


int main(){
    
    LISiter();
    cout << "Longest Increasing Subsequence length is ";
    cout << LISmemo(n-1) << endl;
    
    return 0;
}
