#include<stdio.h>
#define ll long long int
ll schroder(ll n){
    ll m[n+1];
    m[0]=1;
    m[1]=2;
    for(ll i=2;i<=n;i++){
        m[i]=3*m[i-1];
        for(ll j=1;j<=i-2;j++)
            m[i]+=m[j]*m[i-j-1];
    }
    return m[n];
}
int main(void){
	ll n;
	scanf("%lld",&n);
	printf("%lld",schroder(n));
	return 0;
}
