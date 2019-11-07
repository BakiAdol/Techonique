
//Max Contiguous Subarray Sum, Linear array
// Complexity O(n)
void CSS()
{
    int n=9;
    int arr[]={-2,1,-3,4,-1,2,1,-5,4};

    int first=0,last=0;
    int recentSum=arr[0];
    int maxSum=arr[0];
    for(int i=1;i<n;i++)
    {
        if(recentSum+arr[i]>arr[i])
        {
            recentSum+=arr[i];
            if(recentSum>maxSum)
            {
                maxSum=recentSum;
                last=i;
            }
        }
        else
        {
            recentSum=arr[i];
            if(maxSum<recentSum)
            {
                maxSum=recentSum;
                first=last=i;
            }
        }
    }
    cout << "First index = " << first << endl;
    cout << "Last index = " << last << endl;
    cout << "Maximum Sum = " << maxSum << endl;
}

//----------------------------------------------------------------------------------------------//

// Maximum sum rectangle in a 2D matrix

#include <bits/stdc++.h>

using namespace std;

#define row 4
#define col 5

void kadane(int rowSome[], int* maxSum, int* top, int* bottom)
{

    int currentSum=rowSome[0];
    *maxSum=rowSome[0];
    *top=0;
    *bottom=0;

    for(int i=1;i<row;i++)
    {
        if(currentSum+rowSome[i]>rowSome[i])
        {
            currentSum+=rowSome[i];
            if(*maxSum<currentSum)
            {
                *maxSum=currentSum;
                *bottom=i;
            }
        }
        else
        {
            currentSum=rowSome[i];
            if(*maxSum<currentSum)
            {
                *maxSum=currentSum;
                *top=*bottom=i;
            }
        }
    }

}

void maxRectangleSum(int mat[row][col])
{
    int maxRectSum=INT_MIN,currentMaxSum;
    int fLeft, fRight, fTop, fBottom, currentTop, currentBottom;
    int rowSum[row];

    for(int left=0;left<col;left++)
    {
        memset(rowSum,0,sizeof(rowSum));
        for(int right=left;right<col;right++)
        {
            for(int i=0;i<row;i++)
            {
                rowSum[i]+=mat[i][right];
            }

            kadane(rowSum, &currentMaxSum, &currentTop, &currentBottom);

            if(maxRectSum<currentMaxSum)
            {
                maxRectSum=currentMaxSum;
                fTop=currentTop;
                fBottom=currentBottom;
                fLeft=left;
                fRight=right;
            }
        }
    }
    cout << "Top Left Corner = (" << fTop << ", " << fLeft << ")" << endl;
    cout << "Bottom Right Corner = (" << fBottom << ", " << fRight << ")" << endl;
    cout << "Maximum Rectangle Sum = " << maxRectSum << endl;
}

int main()
{
    int mat[row][col] = {{ 1,  2, -1, -4, -20},
                       {  -8, -3,  4,  2,   1},
                       {   3,  8, 10,  1,   3},
                       {  -4, -1,  1,  7,  -6}};
                       
    maxRectangleSum(mat);

    return 0;
}


