// Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors.

// If there is no such integer in the array, return 0.

 

// Example 1:

// Input: nums = [21,4,7]
// Output: 32
// Explanation:
// 21 has 4 divisors: 1, 3, 7, 21
// 4 has 3 divisors: 1, 2, 4
// 7 has 2 divisors: 1, 7
// The answer is the sum of divisors of 21 only.
 

// Constraints:

// 1 <= nums.length <= 10^4
// 1 <= nums[i] <= 10^5

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int x:nums)
            ans+=sumDivisors(x);
        return ans;
    }
private:
    int sumDivisors(int n) {
        int sum=1+n;
        bool flag=false;
        int sq=sqrt(n);
        if(sq*sq==n)
            return 0;
        for(int i=sq;i>=2;i--){
            if(n%i==0){
                if(flag)
                    return 0;
                flag=true;
                sum+=i+n/i;
            }
        }
        return (flag)?sum:0;
    }
};
