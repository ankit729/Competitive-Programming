#include<stdio.h>
#include<stdlib.h>
#define ll long long int
ll divisibility_check(ll num,ll k){
	ll arr[k][2];
	ll m=0;
	for(ll i=0;i<k;i++){
		for(ll j=0;j<2;j++){
			arr[i][j]=m++;
			if(m==k)
				m=0;
		}
	}
	ll msb_pos=0,n=num;
	while(n>0){
		msb_pos++;
		n=n>>1;
	}
	ll transitioning_index=0;
	while(msb_pos>=0){
		if(num>>msb_pos&1==1)
			transitioning_index=arr[transitioning_index][1];
		else
			transitioning_index=arr[transitioning_index][0];
		msb_pos--;
	}
	return (transitioning_index==0)?1:0;
}
int main(void){
    ll t;
    scanf("%lld",&t);
    while(t--){
        ll dividend,divisor;
        scanf("%lld %lld",&dividend,&divisor);
        printf("%lld\n",divisibility_check(dividend,divisor));
    }
	return 0;
}