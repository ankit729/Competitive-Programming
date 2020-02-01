// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Example:

// Input:
// [
//   ["1","0","1","0","0"],
//   ["1","0","1","1","1"],
//   ["1","1","1","1","1"],
//   ["1","0","0","1","0"]
// ]
// Output: 6

int max(int a,int b){
    return (a>b)?a:b;
}
int min(int a,int b){
    return (a<b)?a:b;
}
int largestRectangleArea(int* h,int n){
    if(n==0)
        return 0;
    int ans=0;
    int stack[n],top=-1;
    int i=0;
    while(i<n){
        if(top==-1 || h[i]>=h[stack[top]])
            stack[++top]=i++;
        else{
            ans=max(ans,h[stack[top]]*((top==0)?i:i-stack[top-1]-1));
            top--;
        }
    }
    while(top>=0){
        ans=max(ans,h[stack[top]]*((top==0)?i:i-stack[top-1]-1));
        top--;
    }
    return ans;
}
int maximalRectangle(char** m,int r,int* c){
    if(r==0 || c[0]==0)
        return 0;
    int ans=0;
    int dp[c[0]];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<r;i++){
        for(int j=0;j<c[i];j++)
            dp[j]=(m[i][j]-'0')?dp[j]+1:0;
        ans=max(ans,largestRectangleArea(dp,c[i]));
    }
    return ans;
}
