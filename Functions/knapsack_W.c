#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define W_MAX 1000000001;
int V_MAX=0;
int dp[100001][100];
int min(int a,int b){
    return (a<b)?a:b;
}
int max(int a,int b){
    return (a>b)?a:b;
}
int knapsack_W_solveDp(int r,int i,int* w,int* val,int n){
	if(r<=0)
		return 0;
	if(i==n)
		return W_MAX;
	if(dp[r][i]>=0)
		return dp[r][i];
	return dp[r][i]=min(knapsack_W_solveDp(r,i+1,w,val,n),w[i]+knapsack_W_solveDp(r-val[i],i+1,w,val,n));
}
int knapsack_W_maxWeight(int* w,int* val,int n,int W){
    bool ispossible[V_MAX+1];
    memset(ispossible,false,sizeof(ispossible));
    ispossible[0]=true;
    int M=0;
    for(int i=0;i<n;i++)
        for(int j=M+val[i];j>=val[i];j--)
            if(ispossible[j-val[i]]){
                ispossible[j]=true;
                M=max(M,j);
            }
	for(int i=V_MAX;i>=0;i--)
	    if(ispossible[i])
		    if(knapsack_W_solveDp(i,0,w,val,n)<=W)
                return i;
	return 0;
}
void knapsack_W_pre(int n){
    for(int i=0;i<=V_MAX;i++)
        for(int j=0;j<n;j++)
            dp[i][j]=-1;
}
int knapsack_W(int w[],int val[],int n,int W){
    for(int i=0;i<n;i++)
        V_MAX+=val[i];
    knapsack_W_pre(n);
    return knapsack_W_maxWeight(w,val,n,W);
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
