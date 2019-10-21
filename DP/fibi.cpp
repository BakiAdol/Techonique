/*
  Naive approach
  Complexity O(2^n/2) probably
*/

int fibi(int n)
{
    if(n<3) return 1;
    return fibi(n-1)+fibi(n-2);
}

/*
  DP memorized approach
  Complexity O(n)
*/

long long arr[500];
long long fibi(long long n)
{
    if(arr[n]!=0) return arr[n];
    if(n<3) arr[n]=1;
    else arr[n]=fibi(n-1)+fibi(n-2);
    return arr[n];
}
