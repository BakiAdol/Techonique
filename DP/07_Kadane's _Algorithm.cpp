
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

