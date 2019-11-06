
//Max Contiguous Subarray Sum, Linear array
// Complexity O(n)
void CSS()
{
    int n=9;
    int res[]={-2,1,-3,4,-1,2,1,-5,4};
    int oldMax=res[0],newMax=res[0];
    for(int i=1;i<n;i++)
    {
        oldMax=max(oldMax+res[i],res[i]);
        newMax=max(oldMax,newMax);
    }
    cout << newMax << endl;
}
