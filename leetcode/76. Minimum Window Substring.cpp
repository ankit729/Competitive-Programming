// Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".

// Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
 

// Constraints:

// 1 <= s.length, t.length <= 10^5
// s and t consist of English letters.


class Solution {
public:
    string minWindow(string& s, string& t) {
        int ans=INT_MAX,ansl=0;
        int c[52]={};
        for(auto& ch:t)
            c[getI(ch)]++;
        for(int l=0,r=0,total=t.length();s[r];++r){
            if(--c[getI(s[r])]>=0)
                total--;
            while(l<=r && c[getI(s[l])]<0)
                c[getI(s[l++])]++;
            if(total==0 && ans>r-l+1)
                ans=r-l+1,ansl=l;
        }
        return (ans==INT_MAX)?"":s.substr(ansl,ans);
    }
private:
    int getI(char ch) {
        return ch-65-((ch>=97)?6:0);
    }
};
