// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// Note: For the purpose of this problem, we define empty string as valid palindrome.

// Example 1:

// Input: "A man, a plan, a canal: Panama"
// Output: true
// Example 2:

// Input: "race a car"
// Output: false

class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,h=s.size()-1;
        while(l<h){
            while(l<h && !isalnum(s[l]))
                l++;
            while(l<h && !isalnum(s[h]))
                h--;
            if(tolower(s[l++])!=tolower(s[h--]))
                return false;
        }
        return true;
    }
};
