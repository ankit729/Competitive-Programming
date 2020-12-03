void computeLPSArray(string pat, int M, int* lps){
	int len=0,i=1;
	lps[0]=0;
	while(i<M){
		if(pat[i]==pat[len])
			lps[i++]=++len;
		else{
			if(len!=0)
				len=lps[len-1];
			else 
				lps[i++]=0;
		}
	}
}
bool KMPSearch(string pat, string txt){ 
	int M=pat.length(),N=txt.length();
	int lps[M];
	computeLPSArray(pat,M,lps);
	int i=0,j=0;
	while(i<N){
		if(pat[j]==txt[i]){
			j++;
			i++;
		}
		if(j==M){
			//cout<<i-j;
			return true;
			j=lps[j-1];
		}
		else if(i<N && pat[j]!=txt[i]){
			if(j!=0)
				j=lps[j-1];
			else
				i++;
		}
	}
	return false;
}
