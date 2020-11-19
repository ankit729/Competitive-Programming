// Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

// Example 1:
// Input: "aba"
// Output: True
// Example 2:
// Input: "abca"
// Output: True
// Explanation: You could delete the character 'c'.
// Note:
// The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

class Solution {
public:
    bool validPalindrome(string s) {
        int n=s.size();
        for(int i=0,j=n-1;i<j;i++,j--)
            if(s[i]!=s[j])
                return check(s,i+1,j) || check(s,i,j-1);
        return true;
    }
private:
    bool check(string s, int i, int j) {
        for(;i<j;i++,j--)
            if(s[i]!=s[j])
                return false;
        return true;
    }
};
