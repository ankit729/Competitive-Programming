// Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

 

// Example 1:

// Input: n = 13
// Output: 6
// Example 2:

// Input: n = 0
// Output: 0
 

// Constraints:

// 0 <= n <= 2 * 10^9

class Solution {
public:
    int countDigitOne(int n) {
        long int ans=0;
        long int dp=0,prev=0,curr=1;
        while(n>0){
            int digit=n%10;
            if(digit>1)
                ans+=digit*dp+curr;
            else if(digit==1)
                ans+=dp+prev+1;
            dp=10*dp+curr;
            prev=digit*curr+prev;
            curr*=10;
            n/=10;
        }
        return ans;
    }
};
