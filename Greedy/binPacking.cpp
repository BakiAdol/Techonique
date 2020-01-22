
// Complexity O(n)
int nextFit(int weights[], int len, int binSize)
{
    int numberOfBins=0;
    int binSpace=0;
    for(int weight=0;weight<len;weight++)
    {
        if(weights[weight]<=binSpace)
        {
            binSpace-=weights[weight];
        }
        else
        {
            numberOfBins++;
            binSpace=binSize-weights[weight];
        }
    }
    return numberOfBins;
}

// Complexity O(n*n)
int firstFit(int weights[], int len, int binSize)
{
    vector<int> bins;
    bool b;
    for(int weight=0;weight<len;weight++)
    {
        b=true;
        for(int i=0;i<(int)bins.size();i++)
        {
            if(bins[i]>=weights[weight])
            {
                bins[i]-=weights[weight];
                b=false;
                break;
            }
        }
        if(b) bins.push_back(binSize-weights[weight]);
    }
    return bins.size();
}

int bestFit(int weights[], int len, int binSize)
{
    vector<int> bins;
    bool b;
    int best,minn;
    for(int weight=0;weight<len;weight++)
    {
        b=true;
        minn=binSize+1;
        best=0;
        for(int bin=0;bin<(int)bins.size();bin++)
        {
            if(bins[bin]>=weights[weight] && bins[bin]-weights[weight]<minn)
            {
                best=bin;
                minn=bins[bin]-weights[weight];
                b=false;
                break;
            }
        }
        if(b)
        {
            bins.push_back(binSize-weights[weight]);
        }
        else
        {
            bins[best]-=weights[weight];
        }
    }
    return bins.size();
}

int firstFitDec(int weights[], int len, int binSize)
{
    sort(weights,weights+len,greater<int>());
    return firstFit(weights,len,binSize);
}
