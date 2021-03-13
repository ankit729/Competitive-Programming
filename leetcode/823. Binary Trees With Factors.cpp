// Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

// We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

// Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

 

// Example 1:

// Input: arr = [2,4]
// Output: 3
// Explanation: We can make these trees: [2], [4], [4, 2, 2]
// Example 2:

// Input: arr = [2,4,5,10]
// Output: 7
// Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
 

// Constraints:

// 1 <= arr.length <= 1000
// 2 <= arr[i] <= 10^9

#define ll long long int
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& nums) {
        int MOD=1e9+7,n=nums.size();
        ll ans=0;
        sort(nums.begin(),nums.end());
        unordered_map<int,ll> mp;
        for(int i=0;i<n;++i)
            mp[nums[i]]=1;
        for(int i=0;i<n;++i){
            for(int j=0;j<=i;++j){
                ll prod=(ll) nums[j]*nums[i];
                if(prod>nums.back())
                    break;
                if(mp.count(prod))
                    mp[prod]=(mp[prod]+mp[nums[j]]*mp[nums[i]]*(1+(j!=i)))%MOD;
            }
        }
        for(auto& x:mp)
            ans=(ans+x.second)%MOD;
        return ans;
    }
};
