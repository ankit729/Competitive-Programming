#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define ll long long int
int sieve_of_eratosthenes(int limit,bool prime[limit]){
	memset(prime,true,(limit+1)*sizeof(bool));
	prime[0]=prime[1]=false;
	for(ll i=4;i<=limit;i+=2)
		prime[i]=false;
	for(ll i=3;i*i<=limit;i+=2)
		if(prime[i]==true)
			for(ll j=i*i;j<=limit;j+=i)
				prime[j]=false;
	for(ll i=0;i<=limit;i++)
		if(prime[i])
			printf("%lld\t",i);
}
int main(void){
	ll limit;
	scanf("%lld",&limit);
	bool prime[limit+1];
	sieve_of_eratosthenes(limit,prime);
	return 0;
}
