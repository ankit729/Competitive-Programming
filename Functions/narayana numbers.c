#include<stdio.h>
#include<string.h>
#define ll long long int
ll nCr(ll n,ll r){
    if(n<r)
        return 0;
    if(r>n-r)
        r=n-r;
	ll res=1;
	for(ll i=0;i<r;++i){
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
ll narayana_number(ll n,ll k){
    return k*pow(nCr(n,k),2)/(n*(n-k+1));
}
int main(void){
    ll t;
    scanf("%lld",&t);
    while(t--){
    	ll n,k;
    	scanf("%lld %lld",&n,&k);
    	printf("%lld\n",narayana_number(n,k));
    }
	return 0;
}
