#include<stdio.h>
#define ll long long int
int min(ll a,ll b){
    if(a<b)
        return a;
    return b;
}
ll getNthUglyNo(ll k,ll primes[],ll n){
	ll ugly[n],index[k],next_multiple[k];
	for(ll i=0;i<k;i++){
	    index[i]=0;
	    next_multiple[i]=primes[i];
	}
	ll next_ugly_no=1;
	ugly[0]=1;
	for(ll i=1;i<n;i++){
	    next_ugly_no=next_multiple[0];
	    for(ll j=1;j<k;j++)
	        next_ugly_no=min(next_ugly_no,next_multiple[j]);
    	ugly[i]=next_ugly_no;
    	for(ll j=0;j<k;j++){
        	if(next_ugly_no==next_multiple[j]){
        		index[j]++;
        		next_multiple[j]=ugly[index[j]]*primes[j];
        	}
    	}
	}
	return next_ugly_no;
}
int main(void){
    ll k;
    scanf("%lld",&k);
    ll primes[k];
    for(ll i=0;i<k;i++)
        scanf("%lld",&primes[i]);
	ll n;
	scanf("%lld",&n);
	printf("%lld",getNthUglyNo(k,primes,n));
	return 0;
}
