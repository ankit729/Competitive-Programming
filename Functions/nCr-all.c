#include<stdio.h>
#include<string.h>
#define ll long long int
int min(ll a,ll b){
    return (a<b)?a:b;
}
ll nCr(ll n,ll r){
    if(n<r)
        return 0;
    if(r>n-r)
        r=n-r;
    ll C[n+1][r+1];
    ll i,j;
    for(i=0;i<=n;i++){
        for(j=min(i,r);j>=0;j--){
            if(j==0 || j==i)
                C[i][j]=1;
            else
                C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    return C[n][r];
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