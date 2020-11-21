// Top-Down approach
int dp[1000][1000];
int LCS(string first, int lastInd1, string second, int lastInd2)
{
    if(lastInd1 < 0 || lastInd2<0) return 0;
    
    if(dp[lastInd1][lastInd2]!=-1) return dp[lastInd1][lastInd2];
    
    if(first[lastInd1]==second[lastInd2])
    {
        return dp[lastInd1][lastInd2] = 1 + LCS(first,lastInd1-1,second,lastInd2-1);
    }
    else
    {
        return dp[lastInd1][lastInd2] = max(LCS(first,lastInd1-1,second,lastInd2),
                   LCS(first,lastInd1,second,lastInd2-1));
    }
}
// Bottom-Up Approach / Memorization
int LCS(string first, string second)
{
    int lenf=first.length(),lens=second.length();
    int arr[lenf+1][lens+1];
    for(int i=0;i<=lenf;i++)
    {
        for(int j=0;j<=lens;j++)
        {
            if(i==0 || j==0) arr[i][j]=0;
            else if(first[i-1]==second[j-1])
            {
                arr[i][j]=arr[i-1][j-1]+1;
            }
            else
            {
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    return arr[lenf][lens];
}

