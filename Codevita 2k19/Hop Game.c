#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long int
int max(ll a,ll b){
    if(a>b)
        return a;
    return b;
}
int main(void){
	ll n,i;
	scanf("%lld",&n);
	ll a[n+1],dp[n+1][3];
	char buffer[1000];
	char *token;
	dp[0][0]=dp[0][1]=dp[0][2]=0;
	scanf("%s",buffer);
	token=strtok(buffer,",");
	i=1;
	while(token){
	    a[i++]=atoll(token);
	    token=strtok(NULL,",");
	}
	for(i=1;i<=n;i++){
	    dp[i][0]=max(dp[i-1][2],dp[i-1][2])+a[i];
	    dp[i][1]=dp[i-1][1]+a[i];
	    if(i>=2){
	        dp[i][0]=max(dp[i][0],max(dp[i-2][0],dp[i-2][2])+2*a[i]);
	        dp[i][1]=max(dp[i][1],dp[i-2][1]+2*a[i]);
	    }
	    if(i>=3)
	        dp[i][2]=max(dp[i][1],dp[i-3][1]+3*a[i]);
	}
	ll ans=max(dp[n][0],max(dp[n][1],dp[n][2]));
	printf("%lld",ans);
	return 0;
}
