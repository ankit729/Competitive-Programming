// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

// Example:

// Input: 

// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0

// Output: 4

int max(int a,int b){
    return (a>b)?a:b;
}
int min(int a,int b){
    return (a<b)?a:b;
}
int maximalSquare(char** M, int r, int* c){
    if(r==0 || c[0]==0)
        return 0;
    int ans=0,prev=0,dp[c[0]+1];
    for(int j=0;j<=c[0];j++)
        dp[j]=0;
    for(int i=0;i<r;i++)
        for(int j=0;j<c[i];j++){
            int temp=dp[j+1];
            if(M[i][j]-'0'){
                dp[j+1]=1+min(prev,min(dp[j+1],dp[j]));
                ans=max(ans,dp[j+1]);
            }
            else
                dp[j+1]=0;
            prev=temp;
        }
    return ans*ans;
}
