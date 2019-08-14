#include<stdio.h>
#define ll long long int
int gcd(ll a,ll b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}
ll power(ll x,ll y,ll m){
    ll res=1;
    x=x%m;
    while(y>0){
        if(y&1)
            res=(res*x)%m;
        y=y>>1;
        x=(x*x)%m;
    }
    return res;
}
ll modInverse(ll a,ll m){
	ll g=gcd(a,m);
	if(g!=1)
		return -1;
	else
		return power(a,m-2,m);
}
int main(void){
    ll MOD=1000000007;
    printf("%lld",modInverse(102131531,MOD));
	return 0;
}
