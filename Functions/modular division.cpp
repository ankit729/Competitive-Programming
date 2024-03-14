ll gcdExtended(ll a, ll b, ll& x, ll& y) {
	if(a==0){
		x=0,y=1;
		return b;
	}
	ll x1,y1;
	ll g=gcdExtended(b%a,a,x1,y1);
	x=y1-(b/a)*x1;
	y=x1;
	return g;
}
ll modInverse(ll b, ll MOD) {
	ll x,y;
	ll g=gcdExtended(b,MOD,x,y);
	if(g!=1)
		return -1;
	return (x%MOD+MOD)%MOD;
}
ll modular_division(ll a, ll b, ll MOD) {
	a=a%MOD;
	ll inv=modInverse(b,MOD);
	if(inv==-1)
	    return -1;
	return (inv*a)%MOD;
}
