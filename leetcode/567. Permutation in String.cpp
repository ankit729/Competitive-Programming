// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

// Example 1:

// Input: s1 = "ab" s2 = "eidbaooo"
// Output: True
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input:s1= "ab" s2 = "eidboaoo"
// Output: False
 

// Constraints:

// The input strings only contain lower case letters.
// The length of both given strings is in range [1, 10,000].

class Solution {
public:
    bool checkInclusion(string& s1, string& s2) {
        int n=s1.length();
        int c[26]={};
        for(auto& ch:s1)
            c[ch-'a']++;
        for(int l=0,r=0,total=n;s2[r];++r){
            if(--c[s2[r]-'a']>=0)
                total--;
            while(l<=r && c[s2[l]-'a']<0)
                c[s2[l++]-'a']++;
            if(total==0 && r-l+1==n)
                return true;
        }
        return false;
    }
};
