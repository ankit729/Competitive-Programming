#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define ll long long int
int main(void){
	ll limit;
	scanf("%lld",&limit);
	bool prime[limit+1];
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for(ll j=4;j<=limit;j+=2)
		prime[j]=!prime[j];
	for(ll i=3;i*i<=limit;i+=2)
		if(prime[i]==true)
			for(ll j=i*i;j<=limit;j+=i)
				prime[j]=!prime[j];
	return 0;
}
