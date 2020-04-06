/**
 * Square a sorted array in sorted order
 * Numbers = {-3,-2, -1, 0, 1, 2}
 * Sorted  = {0, 1, 1, 4, 4, 9}
 * */
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n=6;
	int numbers[]={-3,-2,-1,0,1,2};
	int sortedSquare[n];
	int left=0,right=n-1,pos=n;
	
	while(left<=right)
	{
		int leftSquare=numbers[left]*numbers[left];
		int rightSquare=numbers[right]*numbers[right];
		
		if(leftSquare>rightSquare)
		{
			sortedSquare[--pos]=leftSquare;
			left++;
		}
		else
		{
			sortedSquare[--pos]=rightSquare;
			right--;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		printf("%d ",sortedSquare[i]);
	}
	
    return 0;
}
