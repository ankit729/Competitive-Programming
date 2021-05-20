// Let's define a function countUniqueChars(s) that returns the number of unique characters on s, for example if s = "LEETCODE" then "L", "T","C","O","D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.

// On this problem given a string s we need to return the sum of countUniqueChars(t) where t is a substring of s. Notice that some substrings can be repeated so on this case you have to count the repeated ones too.

// Since the answer can be very large, return the answer modulo 10 ^ 9 + 7.

 

// Example 1:

// Input: s = "ABC"
// Output: 10
// Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
// Evey substring is composed with only unique letters.
// Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
// Example 2:

// Input: s = "ABA"
// Output: 8
// Explanation: The same as example 1, except countUniqueChars("ABA") = 1.
// Example 3:

// Input: s = "LEETCODE"
// Output: 92
 

// Constraints:

// 0 <= s.length <= 10^4
// s contain upper-case English letters only.

class Solution {
    const int MOD=1e9+7;
public:
    int uniqueLetterString(string s) {
        int n=s.length(),ans=0;
        if(n==0)
            return ans;
        int index[26],right[n];
        fill(index,index+26,n);
        for(int i=n-1;i>=0;--i){
            int ind=s[i]-'A';
            right[i]=index[ind];
            index[ind]=i;
        }
        fill(index,index+26,-1);
        for(int i=0;i<n;++i){
            ans=(ans+(i-index[s[i]-'A'])*(right[i]-i))%MOD;
            index[s[i]-'A']=i;
        }
        return ans;
    }
};
