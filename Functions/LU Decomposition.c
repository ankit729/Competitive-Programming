void LUDecomposition(ll n) 
{
    for(ll i=0;i<n;i++)
    {
        for(ll k=i;k<n;k++)
        {
            ll sum=0;
            for(ll j=0;j<i;j++)
                sum+=(lower[i][j]*upper[j][k]);
            upper[i][k]=A[i][k]-sum;
        }
        for(ll k=i;k<n;k++)
        {
            if(i==k)
                lower[i][i]=1;
            else
            {
                ll sum=0;
                for(ll j=0;j<i;j++)
                    sum+=(lower[k][j]*upper[j][i]);
                lower[k][i]=(A[k][i]-sum)/upper[i][i];
            }
        }
    }
    for(ll i=0;i<n;i++)
    {
        Y[i]=B[i];
        for(ll j=0;j<i;j++)
            Y[i]-=lower[i][j]*Y[j];
    }
    for(ll i=n-1;i>=0;i--)
    {
        X[i]=Y[i];
        for(ll j=i+1;j<n;j++)
            X[i]-=upper[i][j]*X[j];
        X[i]/=upper[i][i];
    }
}