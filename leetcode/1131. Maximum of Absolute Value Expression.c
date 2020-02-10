// Given two arrays of integers with equal lengths, return the maximum value of:

// |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

// where the maximum is taken over all 0 <= i, j < arr1.length.

 

// Example 1:

// Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
// Output: 13
// Example 2:

// Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
// Output: 20
 

// Constraints:

// 2 <= arr1.length == arr2.length <= 40000
// -10^6 <= arr1[i], arr2[i] <= 10^6

int max(int a,int b){
    return (a>b)?a:b;
}
int min(int a,int b){
    return (a<b)?a:b;
}
int maxAbsValExpr_solve(int s1,int s2,int* arr1,int* arr2,int r){
    int MAX=INT_MIN,MIN=INT_MAX;
    for(int i=0;i<r;i++){
        MIN=min(MIN,s1*arr1[i]+s2*arr2[i]+i);
        MAX=max(MAX,s1*arr1[i]+s2*arr2[i]+i);
    }
    return MAX-MIN;
}
int maxAbsValExpr(int* arr1,int r1,int* arr2,int r2){
    int ans=0;
    ans=max(maxAbsValExpr_solve(-1,-1,arr1,arr2,r1),ans);
    ans=max(maxAbsValExpr_solve(-1,1,arr1,arr2,r1),ans);
    ans=max(maxAbsValExpr_solve(1,-1,arr1,arr2,r1),ans);
    ans=max(maxAbsValExpr_solve(1,1,arr1,arr2,r1),ans);
    return ans;
}
