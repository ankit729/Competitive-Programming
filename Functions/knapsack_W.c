#include<stdio.h>
int max(int a,int b){
    return (a>b)?a:b;
}
int min(int a,int b){
    return (a<b)?a:b;
}
int knapsack_W(int w[],int val[],int n,int W){
    int V_MAX=0;
    for(int i=0;i<n;i++)
        V_MAX+=val[i];
    int minweight[V_MAX+1];
    for(int i=1;i<=V_MAX;i++)
        minweight[i]=W+1;
    minweight[0]=0;
    int M=0;
    for(int i=0;i<n;i++)
        for(int j=M+val[i];j>=val[i];j--){
            minweight[j]=min(minweight[j],w[i]+minweight[j-val[i]]);
            M=max(M,j);
        }
    for(int i=V_MAX;i>=0;i--)
        if(minweight[i]<=W)
            return i;
	return 0;
}
int main(void){
	int n,W;
	scanf("%d %d",&n,&W);
	int w[n],val[n];
	for(int i=0;i<n;i++)
	    scanf("%d %d",&w[i],&val[i]);
	printf("%d",knapsack_W(w,val,n,W));
	return 0;
}
