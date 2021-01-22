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
        int n1=s1.length(),n2=s2.length();
        if(n1>n2)
            return false;
        int c1[26]={},c2[26]={};
        for(int i=0;i<n1;++i)
            c1[s1[i]-'a']++,c2[s2[i]-'a']++;
        int total=0;
        for(int i=0;i<26;++i)
            if(c1[i]==c2[i])
                total++;
        if(total==26)
            return true;
        for(int l=0,r=n1;r<n2;++l,++r){
            int L=s2[l]-'a',R=s2[r]-'a';
            c2[L]--;
            if(c1[L]==c2[L])
                total++;
            else if(c1[L]-1==c2[L])
                total--;
            c2[R]++;
            if(c1[R]==c2[R])
                total++;
            else if(c1[R]+1==c2[R])
                total--;
            if(total==26)
                return true;
        }
        return false;
    }
};
