/**
 * Given an array choose a subsequense and maximaize the expression but couldn't take two consicutive element
 * Given array A[]
 * Choosen subsequense from A is S[]
 * Expression : S1 - s2 + S3 - S4 + S5
 * */
#include<bits/stdc++.h>

using namespace std;

int A[]={1,5,-3,6,7,2,-4,9,3,7};
int n=10;

int memo[100][2];

int sum(int pos, bool sign)
{
	if(pos>=n) return 0;
	
	int &ret = memo[pos][sign];
	if(ret!=-1) return ret;
	
	// if pos is taken then pos+1 will not take so jump pos+2 
	return ret=max(sum(pos+1,sign),sign ? sum(pos+2,0)+A[pos] : sum(pos+2,1)-A[pos]);
}

int main()
{
	memset(memo,-1,sizeof(memo));
	
	cout << sum(0,1) << endl;

	return 0;
}
