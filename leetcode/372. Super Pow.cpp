// Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

 

// Example 1:

// Input: a = 2, b = [3]
// Output: 8
// Example 2:

// Input: a = 2, b = [1,0]
// Output: 1024
// Example 3:

// Input: a = 1, b = [4,3,3,8,5,2]
// Output: 1
// Example 4:

// Input: a = 2147483647, b = [2,0,0]
// Output: 1198
 

// Constraints:

// 1 <= a <= 2^31 - 1
// 1 <= b.length <= 2000
// 0 <= b[i] <= 9
// b doesn't contain leading zeros.

class Solution {
public:
    static const int MOD=1337;
    int superPow(int a, vector<int>& b) {
        int ans=1;
        a%=MOD;
        for(int i=b.size()-1;i>=0;i--){
            ans=(ans*myPow(a,b[i]))%MOD;
            a=myPow(a,10);
        }
        return ans;
    }
private:
    int myPow(int x, int n) {
        int ans=1;
        while(n){
            if(n&1)
                ans=(ans*x)%MOD;
            x=(x*x)%MOD;
            n>>=1;
        }
        return ans;
    }
};
