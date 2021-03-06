// Let f(x) be the number of zeroes at the end of x!. (Recall that x! = 1 * 2 * 3 * ... * x, and by convention, 0! = 1.)

// For example, f(3) = 0 because 3! = 6 has no zeroes at the end, while f(11) = 2 because 11! = 39916800 has 2 zeroes at the end. Given k, find how many non-negative integers x have the property that f(x) = k.

// Example 1:
// Input: k = 0
// Output: 5
// Explanation: 0!, 1!, 2!, 3!, and 4! end with k = 0 zeroes.

// Example 2:
// Input: k = 5
// Output: 0
// Explanation: There is no x such that x! ends in k = 5 zeroes.
// Note:

// k will be an integer in the range [0, 10^9].

class Solution {
public:
    int preimageSizeFZF(int K) {
        int l=0,r=K;
        while(l<=r){
            int mid=l+((r-l)>>1);
            int temp=helper(mid);
            if(temp==K)
                return 5;
            if(temp<K)
                l=mid+1;
            else
                r=mid-1;
        }
        return 0;
    }
private:
    int helper(int a) {
        int ans=0;
        while(a>0){
            ans+=a;
            a/=5;
        }
        return ans;
    }
};
