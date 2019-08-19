#include<stdio.h>
#define ll long long int
ll stepping_numbers(ll n){
    ll dp[n][10];
    for(ll i=0;i<=9;i++)
        dp[0][i]=1;
    for(ll i=1;i<n;i++){
        dp[i][0]=dp[i-1][1];
        for(ll j=1;j<=8;j++)
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
        dp[i][9]=dp[i-1][8];
    }
    ll ans=0;
    for(ll i=1;i<=9;i++)
        ans+=dp[n-1][i];
    return ans;
}
int main(void){
	ll n;
	scanf("%lld",&n);
	printf("%lld",stepping_numbers(n));
	return 0;
}
