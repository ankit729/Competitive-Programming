#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define ll  long long int
#define ull unsigned long long int
#define M_E 2.7182818284590452354
#define M_PI	3.14159265358979323846
ll digitsfactorial(ll n){
    if(n<0)
        return 0;
    if(n<=1)
        return 1;
    return 1+floor(n*log10(n/M_E)+log10(2*M_PI*n)/2.0);
}
int main(void){
	ll t;
	scanf("%lld",&t);
	while(t--){
	    ll n;
	    scanf("%lld",&n);
	    printf("%lld\n",digitsfactorial(n));
	}
	return 0;
}
