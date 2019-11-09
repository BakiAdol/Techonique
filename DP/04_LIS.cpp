
int LIS(int arr[], int n)
{
    int lcs[n];

    for(int i=0;i<n;i++) lcs[i]=1;

    int maxLen=1;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j]) lcs[i]=max(lcs[i],lcs[j]+1);

        }
        maxLen=max(maxLen,lcs[i]);
    }
    return maxLen;
}

