// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

// Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

// The order of output does not matter.

// Example 1:

// Input:
// s: "cbaebabacd" p: "abc"

// Output:
// [0, 6]

// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:

// Input:
// s: "abab" p: "ab"

// Output:
// [0, 1, 2]

// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".

class Solution {
public:
    vector<int> findAnagrams(string& s, string& p) {
        int np=p.length();
        vector<int> ans;
        int c[26]={};
        for(auto& ch:p)
            c[ch-'a']++;
        for(int l=0,r=0,total=np;s[r];++r){
            if(--c[s[r]-'a']>=0)
                total--;
            while(s[l] && c[s[l]-'a']<0)
                c[s[l++]-'a']++;
            if(total==0 && r-l+1==np)
                ans.push_back(l);
        }
        return ans;
    }
};
