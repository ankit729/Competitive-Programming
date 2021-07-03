// Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.

// It is guaranteed that there will be a rectangle with a sum no larger than k.

 

// Example 1:


// Input: matrix = [[1,0,1],[0,-2,3]], k = 2
// Output: 2
// Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).
// Example 2:

// Input: matrix = [[2,2,-1]], k = 3
// Output: 3
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -100 <= matrix[i][j] <= 100
// -10^5 <= k <= 10^5
 

// Follow up: What if the number of rows is much larger than the number of columns?

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int R=mat.size(),C=mat[0].size(),ans=INT_MIN;
        int sum[R];
        for(int left=0;left<C;++left){
            fill(sum,sum+R,0);
            for(int right=left;right<C;++right){
                int kadane=0,kadaneM=INT_MIN;
                for(int r=0;r<R;++r){
                    sum[r]+=mat[r][right];
                    kadane=max(kadane+sum[r],sum[r]);
                    kadaneM=max(kadaneM,kadane);
                }
                if(kadaneM<=k){
                    ans=max(ans,kadaneM);
                    continue;
                }
                set<int> st;
                st.insert(0);
                int curr=0;
                for(int r=0;r<R;++r){
                    curr+=sum[r];
                    auto it=st.lower_bound(curr-k);
                    if(it!=st.end() && curr-*it>ans){
                        ans=curr-*it;
                        if(ans==k)
                            return ans;
                    }
                    st.insert(curr);
                }
            }
        }
        return ans;
    }
};
