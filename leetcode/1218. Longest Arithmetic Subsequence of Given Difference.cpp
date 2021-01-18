// Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

 

// Example 1:

// Input: arr = [1,2,3,4], difference = 1
// Output: 4
// Explanation: The longest arithmetic subsequence is [1,2,3,4].
// Example 2:

// Input: arr = [1,3,5,7], difference = 1
// Output: 1
// Explanation: The longest arithmetic subsequence is any single element.
// Example 3:

// Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
// Output: 4
// Explanation: The longest arithmetic subsequence is [7,5,3,1].
 

// Constraints:

// 1 <= arr.length <= 10^5
// -10^4 <= arr[i], difference <= 10^4

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int m=*min_element(arr.begin(),arr.end());
        int M=*max_element(arr.begin(),arr.end());
        int dp[M-m+1];
        fill(dp,dp+M-m+1,0);
        for(auto& x:arr){
            if(x-d>=m && x-d<=M)
                dp[x-m]=1+dp[x-m-d];
            else
                dp[x-m]=1;
        }
        return *max_element(dp,dp+M-m+1);
    }
};