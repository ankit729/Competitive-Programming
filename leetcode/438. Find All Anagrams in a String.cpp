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
        int ns=s.length(),np=p.length();
        vector<int> ans;
        if(np>ns)
            return {};
        int c1[26]={},c2[26]={};
        for(int i=0;i<np;++i)
            c1[p[i]-'a']++,c2[s[i]-'a']++;
        int total=0;
        for(int i=0;i<26;++i)
            if(c1[i]==c2[i])
                total++;
        if(total==26)
            ans.push_back(0);
        for(int l=0,r=np;r<ns;++l,++r){
            int L=s[l]-'a',R=s[r]-'a';
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
                ans.push_back(l+1);
        }
        return ans;
    }
};
