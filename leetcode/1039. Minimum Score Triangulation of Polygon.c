// Given N, consider a convex N-sided polygon with vertices labelled A[0], A[i], ..., A[N-1] in clockwise order.

// Suppose you triangulate the polygon into N-2 triangles.  For each triangle, the value of that triangle is the product of the labels of the vertices, and the total score of the triangulation is the sum of these values over all N-2 triangles in the triangulation.

// Return the smallest possible total score that you can achieve with some triangulation of the polygon.

 

// Example 1:

// Input: [1,2,3]
// Output: 6
// Explanation: The polygon is already triangulated, and the score of the only triangle is 6.
// Example 2:



// Input: [3,7,4,5]
// Output: 144
// Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.  The minimum score is 144.
// Example 3:

// Input: [1,3,1,4,1,5]
// Output: 13
// Explanation: The minimum score triangulation has score 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.
 

// Note:

// 3 <= A.length <= 50
// 1 <= A[i] <= 100

int min(int a,int b){
    return (a<b)?a:b;
}
int minScoreTriangulation_Util(int* A,int r,int l,int h,int dp[r][r]){
    if(dp[l][h]!=INT_MAX)
        return dp[l][h];
    if(h-l+1==3){
        dp[l][h]=A[l]*A[l+1]*A[l+2];
        return dp[l][h];
    }
    int a=INT_MAX;
    int mul= A[l]*A[h];
    for(int i=l+1;i<h;i++)
        a=min(a, A[i]*mul + minScoreTriangulation_Util(A,r,l,i,dp) + minScoreTriangulation_Util(A,r,i,h,dp));
    dp[l][h]=a;
    return a;
}
int minScoreTriangulation(int* A,int r){
    int dp[r][r];
    for(int i=0;i<r;i++)
        for(int j=i+1;j<r;j++)
            dp[i][j]=(j-i+1==2)?0:INT_MAX;
    return minScoreTriangulation_Util(A,r,0,r-1,dp);
}
