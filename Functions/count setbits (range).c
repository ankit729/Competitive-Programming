#include<stdio.h>
#include<math.h>
#define ll long long int
#define integer_size 32
ll countBitsUtil(ll a,ll b){
    if(a==1 && b==1)
        return 1;
    if(b==0)
        return 0;
    int size=log2(b)+1;
    ll mid=1<<(size-1);
    if(a<mid)
        return b-mid+1+countBitsUtil(a,mid-1)+countBitsUtil(1,b-mid);
    if(a==mid)
        return b-a+1+countBitsUtil(1,b-mid);
    return b-a+1+countBitsUtil(a-mid,b-mid);
}
ll countBits(ll a,ll b){
    if(a<0){
        if(b<0)
            return countBitsUtil((1<<integer_size)+a,(1<<integer_size)+b);
        if(b==0)
            return countBitsUtil((1<<integer_size)+a,(1<<integer_size)-1);
        return countBitsUtil((1<<integer_size)+a,(1<<integer_size)-1)+countBitsUtil(1,b);
    }
    if(a==0){
        if(b==0)
            return 0;
        return countBitsUtil(1,b);
    }
    if(a>0)
        return countBitsUtil(a,b);
}
int main(void){
    ll t;
    scanf("%lld",&t);
    while(t--){
        ll low,high;
        scanf("%lld %lld",&low,&high);
        printf("%lld\n",countBits(low,high));
    }
	return 0;
}
