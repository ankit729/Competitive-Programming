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
int main(void){
    ll t;
    scanf("%lld",&t);
    while(t--){
    	ll n,r;
    	scanf("%lld %lld",&n,&r);
    	printf("%lld\n",nCr(n,r));
    }
	return 0;
}