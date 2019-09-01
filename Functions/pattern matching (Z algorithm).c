#include<stdio.h>
#include<string.h>
#define ll long long int
void getZarr(char str[],ll Z[],ll n){
	ll L,R,k;
	L=R=0;
	for(ll i=1;i<n;i++){
		if(i>R){
			L=R=i;
			while(R<n && str[R-L]==str[R])
				R++;
			Z[i]=R-L;
			R--;
		}
		else{
			k=i-L;
			if(Z[k]<R-i+1)
				Z[i]=Z[k];
			else{
				L=i;
				while(R<n && str[R-L]==str[R])
					R++;
				Z[i]=R-L;
				R--;
			}
		}
	}
}
void Z_algorithm(char s[],char pattern[]){
	ll l=strlen(pattern)+strlen(s)+1;
	char concat[l];
	strcat(concat,pattern);
	strcat(concat,"$");
	strcat(concat,s);
	ll Z[l]; 
	getZarr(concat,Z,l);
	for(ll i=0;i<l;i++)
		if(Z[i]==strlen(pattern)) 
			printf("Pattern found at index %lld\n",i-strlen(pattern)-1);
}
int main(void){
	char s[]="GEEKS FOR GEEKS";
	char pattern[]="GEEK";
	Z_algorithm(s,pattern);
	return 0;
}
