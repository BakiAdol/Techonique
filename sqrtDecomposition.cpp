///-----------------Square Root Decomposition--------------------------------///

/*
    n=9;
    array{3, 8, 1, 9, 5, 4, 6, 7, 2}
    Here two operation 1. Update index valu and 2. Find the sum of this array

    Approach 1:
        1.1. Update :
             array[index] = new value; Time Complexity O(1)
        1.2 Sum :
            iterate 0 to n Sum+=array[i]; Time Complexity O(n)

    Approach 2:
        1.1. Update :
            array{3,  8,  1,  9,  5,  4,  6,  7,  2}
            Sum  {3, 11, 12, 21, 26, 30, 36, 43, 45}
            updare arry value index base and also update Sum array value
            Time Complexity O(n)

        2.2 Sum :
            Sum[n-1]; Time Complexity O(1)

      Approach 3:
            "Square Root Decomposition Techonique"
             Time Complexity O(sqrt(n))
*/

#include<bits/stdc++.h>

using namespace std;

int blockSize;
int blocks[100];
int ar[]={3, 8, 1, 9, 5, 4, 6, 7, 2};

void update(int pos, int data)
{
	blocks[pos/blockSize]+=data-ar[pos];
	ar[pos]=data;
}

int query(int l, int r)
{
	int sum=0;
	int l_block=l/blockSize;
	int r_block=r/blockSize;
	
	if(l_block==r_block)
	{
		for(int i=l;i<=r;i++) sum+=ar[i];
	}
	else
	{
		for(int i=l,f=(l_block+1)*blockSize;i<f;i++)
		{
			sum+=ar[i];
		}
		for(int i=l_block+1;i<r_block;i++)
		{
			sum+=blocks[i];
		}
		for(int i=r_block*blockSize;i<=r;i++)
		{
			sum+=ar[i];
		}
	}
	
	return sum;
}

void ini(int n)
{
	int pos=-1;
	blockSize=sqrt(n);
	
	for(int i=0;i<n;i++)
	{
		if(i%blockSize==0) pos++;
		
		blocks[pos]+=ar[i];
	}
}

int main()
{
    ini(9);
    
    printf("%d\n",query(2,6));
    
    update(3,100);
    
    printf("%d\n",query(3,3));
    printf("%d\n",query(0,8));
	
	return 0;
}


