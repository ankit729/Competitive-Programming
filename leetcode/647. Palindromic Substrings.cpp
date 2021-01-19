// Given a string, your task is to count how many palindromic substrings in this string.

// The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

// Example 1:

// Input: "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
 

// Example 2:

// Input: "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

// Note:

// The input string length won't exceed 1000.

class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length(),ans=0;
        n=(n<<1)|1;
        int L[n];
        L[0]=0;
        for(int i=1,C=0,R=0;i<n;++i){
            L[i]=(i<R)?min(R-i,L[(C<<1)-i]):0;
            while(i+L[i]<n && i-L[i]>0 && (!((i+L[i]+1)&1) || s[(i+L[i]+1)>>1]==s[(i-L[i]-1)>>1]))
                L[i]++;
            ans+=((L[i]+1)>>1);
            if(i+L[i]>R)
                R=i+L[i],C=i;
        }
        return ans;
    }
};
