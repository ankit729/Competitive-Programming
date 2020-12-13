// There are N piles of stones arranged in a row.  The i-th pile has stones[i] stones.

// A move consists of merging exactly K consecutive piles into one pile, and the cost of this move is equal to the total number of stones in these K piles.

// Find the minimum cost to merge all piles of stones into one pile.  If it is impossible, return -1.

 

// Example 1:

// Input: stones = [3,2,4,1], K = 2
// Output: 20
// Explanation: 
// We start with [3, 2, 4, 1].
// We merge [3, 2] for a cost of 5, and we are left with [5, 4, 1].
// We merge [4, 1] for a cost of 5, and we are left with [5, 5].
// We merge [5, 5] for a cost of 10, and we are left with [10].
// The total cost was 20, and this is the minimum possible.
// Example 2:

// Input: stones = [3,2,4,1], K = 3
// Output: -1
// Explanation: After any merge operation, there are 2 piles left, and we can't merge anymore.  So the task is impossible.
// Example 3:

// Input: stones = [3,5,1,2,6], K = 3
// Output: 25
// Explanation: 
// We start with [3, 5, 1, 2, 6].
// We merge [5, 1, 2] for a cost of 8, and we are left with [3, 8, 6].
// We merge [3, 8, 6] for a cost of 17, and we are left with [17].
// The total cost was 25, and this is the minimum possible.
 

// Note:

// 1 <= stones.length <= 30
// 2 <= K <= 30
// 1 <= stones[i] <= 100

class Solution {
public:
    int mergeStones(vector<int> nums, int K) {
        int n=nums.size();
        if(n==1)
            return 0;
        if((n-1)%(K-1))
            return -1;
        for(int i=1;i<n;++i)
            nums[i]+=nums[i-1];
        nums.insert(nums.begin(),0);
        int dp[n+1][n+1];
        for(int i=0;i<K;++i)
            for(int l=0,r=i;r<=n;++l,++r)
                dp[l][r]=0;
        
        for(int len=K;len<=n;++len){
            for(int l=1,r=len;r<=n;++l,++r){
                dp[l][r]=INT_MAX;
                for(int i=l;i<r;i+=K-1)
                    dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]);
                if((len-1)%(K-1)==0)
                    dp[l][r]+=nums[r]-nums[l-1];
            }
        }
        return dp[1][n];
    }
};
