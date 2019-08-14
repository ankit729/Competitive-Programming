#include<stdio.h>
#define ull unsigned long long int
#define ll long long int
#define MOD 1000000007
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
ll power3(ll a,ll b,ll c,ll m){
    ll ans=power(b,c,m-1);
    return power(a,ans,m);
}
int main(void){
	ll a=2,b=3,c=4;
	power3(a,b,c,MOD);
	return 0;
}
