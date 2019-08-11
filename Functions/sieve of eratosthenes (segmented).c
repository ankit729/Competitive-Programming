#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#define ll long long int
int psize=0,psize2=0;
int prime[60000000];
void simpleSieve(ll limit){
    bool mark[limit+1];
    memset(mark,true,sizeof(mark));
    for(ll i=4;i<limit;i+=2)
        mark[i]=false;
    for(ll i=3;i*i<limit;i+=2)
        if(mark[i])
            for(ll j=i*i;j<limit;j+=i)
                mark[j]=false;
    prime[psize++]=2;
    for(ll i=3;i<limit;i+=2)
        if(mark[i])
            prime[psize++]=i;
}
void segmentedSieve(ll n){
    ll limit=floor(sqrt(n))+1;
    simpleSieve(limit);
    psize2=psize;
    ll low=limit;
    ll high=2*limit;
    while(low<n){
        if(high>n)
           high=n;
        bool mark[high-low+1];
        memset(mark,true,sizeof(mark));
        for(ll i=0;i<psize;i++){
            ll loLim=floor(low/prime[i])*prime[i];
            if(loLim<low)
                loLim+=prime[i];
            for(ll j=loLim;j<high;j+=prime[i])
                mark[j-low]=false;
        }
        for(ll i=low;i<high;i++)
            if(mark[i-low]==true)
                prime[psize2++]=i;
        low=low+limit;
        high=high+limit;
    }
}
int main(void){
    ll n=1000000000;
    segmentedSieve(n);
    return 0;
}
