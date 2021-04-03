// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 

// Example 1:

// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".
// Example 2:

// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".
// Example 3:

// Input: s = ""
// Output: 0
 

// Constraints:

// 0 <= s.length <= 3 * 10^4
// s[i] is '(', or ')'.

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length(),ans=0;
        int l=0,r=0;
        for(int i=0;i<n;++i){
            if(s[i]=='(')
                l++;
            else
                r++;
            if(l==r)
                ans=max(ans,l+r);
            else if(r>l)
                l=r=0;
        }
        l=r=0;
        for(int i=n-1;i>=0;--i){
            if(s[i]==')')
                l++;
            else
                r++;
            if(l==r)
                ans=max(ans,l+r);
            else if(r>l)
                l=r=0;
        }
        return ans;
    }
};
