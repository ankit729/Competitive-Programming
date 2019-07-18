#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
#define ll long long int
ll psize=0,psize2;
ll prime[1000000];
int ppush(p)
{
    prime[psize++]=p;
    return 0;
}
int ppush2(p)
{
    prime[psize2++]=p;
    return 0;
}
void simpleSieve(ll limit)
{
    ll mark[limit+1];
    for(ll i=0;i<limit+1;i++)
        mark[i]=1;
    for(ll p=2;p*p<limit;p++)
        if(mark[p]==1)
            for(ll i=p*2;i<limit;i+=p)
                mark[i]=0;
    for(ll p=2;p<limit;p++)
        if(mark[p]==1)
            ppush(p);
}
void segmentedSieve(ll n)
{
    ll limit=1000000;
    simpleSieve(limit);
    psize2=psize;
    ll low=limit;
    ll high=2*limit;
    while(low<n)
    {
        if(high>=n)
           high=n;
        ll mark[limit+1];
        for(ll i=0;i<limit+1;i++)
            mark[i]=1;
        for(ll i=0;i<psize;i++)
        {
            ll loLim=floor(low/prime[i])*prime[i];
            if(loLim<low)
                loLim+=prime[i];
            for(ll j=loLim;j<high;j+=prime[i])
                mark[j-low]=0;
        }
        for(ll i=low;i<high;i++)
            if(mark[i-low]==1)
                ppush2(i);
        low=low+limit;
        high=high+limit;
    }
}
int main()
{
    ll n=10000000;
    segmentedSieve(n);
    return 0;
}