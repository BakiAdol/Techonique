/**
 * Two Sum and Theree Sum
 * */
#include <bits/stdc++.h>

using namespace std;

//This function is find if there are two elements sum is num in a sorted array.
bool twoSum(int ar[], int num, int left, int right)
{
	while(left<right)
	{
		if(ar[left]+ar[right]==num) return true;
		else if(ar[left]+ar[right]>num) right--;
		else left++; 
	}
	return false;
}

//This funcion find if there any there numbers whose sum is 0 in a sorted array.
bool triplets(int ar[], int length)
{
	for(int i=0;i<length-2;i++)
	{
		if(twoSum(ar,-ar[i],i+1,length-1)) return true;
	}
	return false;
}

int main()
{
	int ar[]={-3, -1, 0, 4, 6, 9};
	
	if(twoSum(ar,3,0,5)) cout << "Yes this array has two element those sum is 3" << endl;
	else cout << "There are no two element whose sum is 3" << endl;
	
	if(triplets(ar,6)) cout << "Yes this array has theree numbers whose sum is 0" << endl;
	else cout << "There not found any theree numbers whose sum is 0" << endl;
	
    return 0;
}
