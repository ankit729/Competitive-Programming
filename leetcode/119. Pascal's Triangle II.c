// Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

// Note that the row index starts from 0.


// In Pascal's triangle, each number is the sum of the two numbers directly above it.

// Example:

// Input: 3
// Output: [1,3,3,1]
// Follow up:

// Could you optimize your algorithm to use only O(k) extra space?

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int n, int* rr){
    *rr=n+1;
    int* ra=malloc((n+1)*sizeof(int));
    for(int i=0;i<=n;i++)
        ra[i]=1;
    for(int i=2;i<=n;i++)
        for(int j=i-1;j>0;j--)
            ra[j]+=ra[j-1];
    return ra;
}
