// Given a string s, find the length of the longest substring without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
// Example 4:

// Input: s = ""
// Output: 0
 

// Constraints:

// 0 <= s.length <= 5 * 10^4
// s consists of English letters, digits, symbols and spaces.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        bitset<128> mask;
        int l=0;
        for(int r=0;s[r];++r){
            if(mask[s[r]]){
                while(l<r && s[l]!=s[r])
                    mask.flip(s[l++]);
                mask.flip(s[l++]);
            }
            mask.flip(s[r]);
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
