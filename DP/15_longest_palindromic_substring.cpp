/**
 * Longest Palindromic Substring
 * */
#include<bits/stdc++.h>

using namespace std;

string str;

int memo[1005][1005];

bool f(int s, int e)
{
	if(s>=e) return 1;
	
	int &ret=memo[s][e];
	if(ret!=-1) return ret;
	
	if(str[s]==str[e]) ret = f(s+1,e-1);
	else ret=0;
	
	return ret;
}

int main()
{
	memset(memo,-1,sizeof(memo));
	
	str="abcbdedbcdebed";
	
	int len=str.length();
	
	int l=0,r=0;
	
	for(int i=0;i<len;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if(f(i,j))
			{
				if(r-l<j-i) l=i,r=j;
			}
		}
	}
	
	while(l<=r) cout << str[l++];
	cout << endl;

	return 0;
}

