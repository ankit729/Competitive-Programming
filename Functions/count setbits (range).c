#include<stdio.h>
#include<math.h>
#define ll long long int
#define integer_size 32
ll setbits[integer_size+1];
ll countBitsUtil(ll a,ll b){
    if(b<=1)
        return b;
    ll sa=1+log2(a);
    ll sb=1+log2(b);
    if(sa<sb){
        ll x,y,z;
        ll ma=(1<<(sa-1));
        x=(a&(a-1)==0)?setbits[sa]-setbits[sa-1]:(ma<<1)-a+countBitsUtil(a-ma,ma-1);
        y=setbits[sb-1]-setbits[sa];
        ll mb=(1<<(sb-1));
        z=(b&(b+1)==0)?setbits[sb]-setbits[sb-1]:b-mb+1+countBitsUtil(1,b-mb);
        return x+y+z;
    }
    else{
        ll mid=(1<<(sa-1));
        return b-a+1+countBitsUtil(a-mid+(a==mid),b-mid);
    }
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
    return countBitsUtil(a,b);
}
void pre(){
    setbits[0]=0;
    for(ll i=1;i<=integer_size;i++)
        setbits[i]=2*setbits[i-1]+(1<<(i-1));
    return 0;
}
int main(void){
    pre();
    ll t;
    scanf("%lld",&t);
    while(t--){
        ll low,high;
        scanf("%lld %lld",&low,&high);
        printf("%lld\n",countBits(low,high));
    }
	return 0;
}
