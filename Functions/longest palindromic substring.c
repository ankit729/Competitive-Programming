#include<stdio.h>
#include<string.h>
#define ll long long int
int min(int a,int b){
	if(a<b)
	    return a;
	return b;
}
void findLongestPalindromicString(char s[],ll N){
	if(N==0)
		return;
	N=2*N+1;
	ll L[N];
	L[0]=0;
	L[1]=1;
	ll C=1,R=2,i,iMirror,maxLPSLength=1,maxLPSCenterPosition=1,diff;
	//printf("%d %d ",L[0],L[1]);
	for(i=2;i<N;i++){
		iMirror=(C<<1)-i;
		L[i]=0;
		diff=R-i;
		if(diff>0)
			L[i]=min(L[iMirror],diff);
		while((i+L[i]<N && i-L[i]>0) && (!((i+L[i]+1)&1) || (s[(i+L[i]+1)>>1]==s[(i-L[i]-1)>>1])))
			L[i]++;
		if(L[i]>maxLPSLength){
			maxLPSLength=L[i];
			maxLPSCenterPosition=i;
		}
		if(i+L[i]>R){
			C=i;
			R=i+L[i];
		}
		//printf("%d ",L[i]); 
	}
	//printf("\n");
	ll start=(maxLPSCenterPosition-maxLPSLength)>>1;
	ll end=start+maxLPSLength-1;
	for(i=start;i<=end;i++)
		printf("%c",s[i]);
	printf("\n");
}
int main(void){
    ll t;
    scanf("%lld",&t);
    while(t--){
        ll N;
        char s[100];
        scanf("%s",s);
        N=strlen(s);
        findLongestPalindromicString(s,N);
    }
    return 0;
}
