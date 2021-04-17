// Given a positive integer N, how many ways can we write it as a sum of consecutive positive integers?

// Example 1:

// Input: 5
// Output: 2
// Explanation: 5 = 5 = 2 + 3
// Example 2:

// Input: 9
// Output: 3
// Explanation: 9 = 9 = 4 + 5 = 2 + 3 + 4
// Example 3:

// Input: 15
// Output: 4
// Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
// Note: 1 <= N <= 10 ^ 9.

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans=0;
        n<<=1;
        for(int i=1;i*i<n;++i)
            if(n%i==0 && !((n/i-1+i)&1))
                ans++;
        return ans;
    }
};
