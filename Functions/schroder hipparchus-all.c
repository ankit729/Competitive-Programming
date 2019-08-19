#include<stdio.h>
#define ll long long int
ll schroder_hipparchus(ll n){
    ll m[n+1];
    m[0]=m[1]=1;
    for(ll i=2;i<=n;i++)
        m[i]=((6*i-9)*m[i-1]-(i-3)*m[i-2])/i;
    return m[n];
}
int main(void){
	ll n;
	scanf("%lld",&n);
	printf("%lld",schroder_hipparchus(n));
	return 0;
}
