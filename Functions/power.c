#include<stdio.h>
#define ull unsigned long long int
#define ll long long int
#define MOD 1000000007
ull power2(ull x,ull y,ull m){
    ull res=1;
    x=x%m;
    while(y>0){
        if(y&1)
            res=(res*x)%m;
        y=y>>1;
        x=(x*x)%m;
    }
    return res;
}
ull power3(ull a,ull b,ull c,ull m){
    ull ans=power2(b,c,m-1);
    return power2(a,ans,m);
}
int main(void){
	ull a=2,b=3,c=4;
	power3(a,b,c,MOD);
	return 0;
}
