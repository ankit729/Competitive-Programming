// Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.

// If there is no non-empty subarray with sum at least K, return -1.

 

// Example 1:

// Input: A = [1], K = 1
// Output: 1
// Example 2:

// Input: A = [1,2], K = 4
// Output: -1
// Example 3:

// Input: A = [2,-1,2], K = 3
// Output: 3
 

// Note:

// 1 <= A.length <= 50000
// -10 ^ 5 <= A[i] <= 10 ^ 5
// 1 <= K <= 10 ^ 9

class Solution {
public:
    int shortestSubarray(vector<int> nums, int K) {
        int n=nums.size();
        for(int i=1;i<n;++i)
            nums[i]+=nums[i-1];
        deque<int> q;
        int ans=n+1;
        for(int i=0;i<n;++i){
            if(nums[i]>=K)
                ans=min(ans,i+1);
            while(!q.empty() && nums[i]-nums[q.front()]>=K){
                ans=min(ans,i-q.front());
                q.pop_front();
            }
            while(!q.empty() && nums[i]<=nums[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        return ans==n+1?-1:ans;
    }
};
