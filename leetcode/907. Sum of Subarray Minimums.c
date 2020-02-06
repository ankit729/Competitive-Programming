// Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

// Since the answer may be large, return the answer modulo 10^9 + 7.

 

// Example 1:

// Input: [3,1,2,4]
// Output: 17
// Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 

// Note:

// 1 <= A.length <= 30000
// 1 <= A[i] <= 30000

int MOD=1000000007;
int sumSubarrayMins(int* A,int r){
    int ans=0;
    int stack[r+1][2],top=0;
    stack[top][0]=-1;
    stack[top++][1]=0;
    for(int i=0;i<r;i++){
        while(top>1 && A[stack[top-1][0]]>=A[i])
            top--;
        stack[top][0]=i;
        stack[top][1]=(A[stack[top][0]]*(stack[top][0]-stack[top-1][0])+stack[top-1][1])%MOD;
        ans=(ans+stack[top++][1])%MOD;
    }
    return ans;
}
