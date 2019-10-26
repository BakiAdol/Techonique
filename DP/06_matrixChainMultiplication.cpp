
int MCM(int dim[], int len)
{
    int mat[len][len];
    for(int i=0;i<len;i++) mat[i][i]=0;

    for(int i=2;i<len;i++)
    {
        for(int j=1;j<len-i+1;j++)
        {
            int k=i+j-1;
            mat[j][k]=INT_MAX;
            for(int l=j;l<=k-1;l++)
            {
                int cost=mat[j][l] + mat[l+1][k] + dim[j-1]*dim[l]*dim[k];
                if(cost<mat[j][k]) mat[j][k]=cost;
            }
        }
    }
    return mat[1][len-1];
}
