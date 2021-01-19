// Given a string s, return the longest palindromic substring in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
// Example 3:

// Input: s = "a"
// Output: "a"
// Example 4:

// Input: s = "ac"
// Output: "a"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters (lower-case and/or upper-case),

class Solution {
public:
    string longestPalindrome(string& s) {
        int n=s.length();
        n=1+(n<<1);
        int L[n];
        int M=0,Mi=0;
        for(int i=1,C=0,R=0;i<n;++i){
            L[i]=(i<R)?min(L[(C<<1)-i],R-i):0;
            while(i+L[i]<n && i-L[i]>0 && (!((i+L[i]+1)&1) || s[(i+L[i]+1)>>1]==s[(i-L[i]-1)>>1]))
                L[i]++;
            if(L[i]>M)
                M=L[i],Mi=i;
            if(i+L[i]>R)
                C=i,R=i+L[i];
        }
        return s.substr((Mi-M)>>1,M);
    }
};
