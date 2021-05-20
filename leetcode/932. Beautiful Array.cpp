// For some fixed n, an array nums is beautiful if it is a permutation of the integers 1, 2, ..., n, such that:

// For every i < j, there is no k with i < k < j such that nums[k] * 2 = nums[i] + nums[j].

// Given n, return any beautiful array nums.  (It is guaranteed that one exists.)

 

// Example 1:

// Input: n = 4
// Output: [2,1,4,3]
// Example 2:

// Input: n = 5
// Output: [3,1,2,5,4]
 

// Note:

// 1 <= n <= 1000

class Solution {
public:
    vector<int> beautifulArray(int n) {
        mp.resize(n+1);
        return helper(n);
    }
private:
    vector<vector<int>> mp;
    vector<int> helper(int n) {
        if(n==1)
            return {1};
        if(!mp[n].empty())
            return mp[n];
        int odd=((n+1)>>1);
        vector<int> left=helper(odd),right=helper(n-odd);
        for(auto& x:left)
            x=((x<<1)-1);
        for(auto& x:right)
            x<<=1;
        left.insert(left.end(),right.begin(),right.end());
        return mp[n]=move(left);
    }
};
