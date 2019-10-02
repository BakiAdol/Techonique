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

#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

int arr[MAX];
int block[100];
int blockSize;

//Time Complexity O(1)
void update(int index, int data)
{
    int blockNumber = index/blockSize;
    block[blockNumber] += data - arr[index];
    arr[index]=data;
}

//Time Complexity O(sqrt(n))
int query(int f, int l)
{
    int sum=0;
    while(f<l && f%blockSize!=0 && f!=0)
    {
        sum+=arr[f++];
    }
    while(f+blockSize<=l)
    {
        sum+=block[f/blockSize];
        f+=blockSize;
    }
    while(f<=l)
    {
        sum+=arr[f++];
    }
    return sum;
}

void initialize(int ar[], int n)
{
    int blockIndex=-1;
    blockSize=sqrt(n);
    for(int i=0;i<n;i++)
    {
        arr[i]=ar[i];
        if(i%blockSize==0)
        {
            blockIndex++;
        }
        block[blockIndex]+=arr[i];
    }
}

int main()
{
    int ar[]={3, 8, 1, 9, 5, 4, 6, 7, 2};
    initialize(ar,9);
    cout << "Sum(1,8) = " << query(1,8) << endl;
    cout << "Sum(5,6) = " << query(5,6) << endl;
    cout << "Sum(0,4) = " << query(0,4) << endl;
    update(5,9);
    cout << "Sum(1,8) = " << query(1,8) << endl;
    return 0;
}

