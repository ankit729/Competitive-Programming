// Given a string s, you can convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

 

// Example 1:

// Input: s = "aacecaaa"
// Output: "aaacecaaa"
// Example 2:

// Input: s = "abcd"
// Output: "dcbabcd"
 

// Constraints:

// 0 <= s.length <= 5 * 10^4
// s consists of lowercase English letters only.

class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        string rs(s);
        reverse(rs.begin(),rs.end());
        string s_new=s+"#"+rs;
        int n_new=(n<<1)|1;
        vector<int> f(n_new,0);
        for(int i=1;i<n_new;i++){
            int t=f[i-1];
            while(t>0 && s_new[i]!=s_new[t])
                t=f[t-1];
            if(s_new[i]==s_new[t])
                t++;
            f[i]=t;
        }
        return rs.substr(0,n-f[n_new-1])+s;
    }
};
