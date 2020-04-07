ll binomialCoeff(ll n,ll k){
	ll res=1;
	if(k>n-k)
		k=n-k;
	for(ll i=0;i<k;i++){
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}
ll catalan(ll n){
	return binomialCoeff(2*n,n)/(n+1);
}
