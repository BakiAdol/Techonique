
void LIS(int arr[], int n)
{
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        auto it = lower_bound(v.begin(),v.end(),arr[i]);
        if(it==v.end()) v.push_back(arr[i]);
        else v[it-v.begin()]=arr[i];
    }

    cout << v.size() << endl;
}

