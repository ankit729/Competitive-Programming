// Given a string s, count the number of distinct, non-empty subsequences of s .

// Since the result may be large, return the answer modulo 10^9 + 7.

 

// Example 1:

// Input: s = "abc"
// Output: 7
// Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".
// Example 2:

// Input: s = "aba"
// Output: 6
// Explanation: The 6 distinct subsequences are "a", "b", "ab", "ba", "aa" and "aba".
// Example 3:

// Input: s = "aaa"
// Output: 3
// Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
 

 

// Note:

// s contains only lowercase letters.
// 1 <= s.length <= 2000

class Solution {
    const int MOD=1e9+7;
public:
    int distinctSubseqII(string s) {
        int ans=1;
        int last[26]={},prev=1;
        for(auto& ch:s){
            ans=((prev<<1)%MOD-last[ch-'a']+MOD)%MOD;
            last[ch-'a']=prev;
            prev=ans;
        }
        ans--;
        return ans<0?ans+MOD:ans;
    }
};
