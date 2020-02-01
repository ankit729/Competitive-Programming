// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 


// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 


// The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

// Example:

// Input: [2,1,5,6,2,3]
// Output: 10

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
