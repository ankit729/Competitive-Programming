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
    int longestValidParentheses(string& s) {
        int ans=0;
        int l=0,r=0;
        for(auto it=s.begin();it!=s.end();++it){
            if(*it=='(')
                l++;
            else
                r++;
            if(l==r)
                ans=max(ans,r<<1);
            else if(r>=l)
                l=r=0;
        }
        l=r=0;
        for(auto it=s.rbegin();it!=s.rend();++it){
            if(*it=='(')
                l++;
            else
                r++;
            if(l==r)
                ans=max(ans,l<<1);
            else if(l>=r)
                l=r=0;
        }
        return ans;
    }
};
