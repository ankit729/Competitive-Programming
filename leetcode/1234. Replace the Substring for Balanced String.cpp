// You are given a string containing only 4 kinds of characters 'Q', 'W', 'E' and 'R'.

// A string is said to be balanced if each of its characters appears n/4 times where n is the length of the string.

// Return the minimum length of the substring that can be replaced with any other string of the same length to make the original string s balanced.

// Return 0 if the string is already balanced.

 

// Example 1:

// Input: s = "QWER"
// Output: 0
// Explanation: s is already balanced.
// Example 2:

// Input: s = "QQWE"
// Output: 1
// Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.
// Example 3:

// Input: s = "QQQW"
// Output: 2
// Explanation: We can replace the first "QQ" to "ER". 
// Example 4:

// Input: s = "QQQQ"
// Output: 3
// Explanation: We can replace the last 3 'Q' to make s = "QWER".
 

// Constraints:

// 1 <= s.length <= 10^5
// s.length is a multiple of 4
// s contains only 'Q', 'W', 'E' and 'R'.

class freq {
public:
    int Q=0,W=0,E=0,R=0;
    freq() {
        
    }
    void update(char ch, int val) {
        switch(ch){
            case 'Q':Q+=val;break;
            case 'W':W+=val;break;
            case 'E':E+=val;break;
            case 'R':R+=val;break;
        }
    }
};

class Solution {
public:
    int balancedString(string s) {
        int n=s.length(),ans=n;
        int target=(n>>2);
        freq a;
        for(auto& ch:s)
            a.update(ch,1);
        for(int l=0,r=0;l<n;++l){
            while(r<n && (a.Q>target || a.W>target || a.E>target || a.R>target))
                a.update(s[r++],-1);
            if(a.Q<=target && a.W<=target && a.E<=target && a.R<=target)
                ans=min(ans,r-l);
            else
                break;
            a.update(s[l],1);
        }
        return ans;
    }
};
