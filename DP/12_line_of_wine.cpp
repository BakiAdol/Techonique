/**
 * There are many wine in a line. Each year you can sell one leftmost or rightmost unsoled wine and when
 * you sell wine you get i'th wine initial price time year. What is the maximum proce you can get if you
 * sell one leftmost or right most wine in a year? 
 * */
#include <bits/stdc++.h>
using namespace std;

int price[]={2,4,6,2,5};
int n=5;

int memo[50][50];

/**
 * If we take left wine then remainin wine is second wine to n and if we take n'th wine then remaining
 * wine is first wine to n-1 wine. In this we we can figur out the maximu price we can get.	
 * An obiously we take max(take left, take right);
 * */

int cal(int left, int right, int y)
{
	if(memo[left][right]) return memo[left][right];

	if(left==right) return memo[left][right]=price[left]*y;
	
	return memo[left][right]=max(y*price[left]+cal(left+1,right,y+1),y*price[right]+cal(left,right-1,y+1));
}

int main(){
    
    cout << cal(0,n-1,1) << endl;
    
    return 0;
}
