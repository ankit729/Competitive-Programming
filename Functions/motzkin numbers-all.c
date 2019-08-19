#include<stdio.h>
#define ll long long int
ll motzkin(ll n){
    ll m[n+1];
    m[0]=m[1]=1;
    for(ll i=2;i<=n;i++)
        m[i]=((2*i+1)*m[i-1]+(3*i-3)*m[i-2])/(i+2);
    return m[n];
}
int main(void){
	ll n;
	scanf("%lld",&n);
	printf("%lld",motzkin(n));
	return 0;
}
