// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

 

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
// Example 3:

// Input: nums = [1,-1], k = 1
// Output: [1,-1]
// Example 4:

// Input: nums = [9,11], k = 2
// Output: [11]
// Example 5:

// Input: nums = [4,-2], k = 2
// Output: [4]
 

// Constraints:

// 1 <= nums.length <= 10^5
// -10^4 <= nums[i] <= 10^4
// 1 <= k <= nums.length

class monoQueue {
    deque<pair<int,int>> mq;
public:
    void push(int val) {
        int count=0;
        while(!mq.empty() && mq.back().first<=val){
            count+=mq.back().second+1;
            mq.pop_back();
        }
        mq.emplace_back(val,count);
    }
    void pop() {
        if(mq.front().second>0)
            mq.front().second--;
        else
            mq.pop_front();
    }
    int max() {
        return mq.front().first;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n-k+1);
        monoQueue mq;
        for(int i=0;i<k-1;++i)
            mq.push(nums[i]);
        for(int i=k-1,j=0;i<n;++i,++j){
            mq.push(nums[i]);
            ans[j]=mq.max();
            mq.pop();
        }
        return ans;
    }
};
