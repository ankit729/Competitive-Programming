// Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is less than or equal to k.

 

// Example 1:

// Input: s = "aaabb", k = 3
// Output: 3
// Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
// Example 2:

// Input: s = "ababbc", k = 2
// Output: 5
// Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 

// Constraints:

// 1 <= s.length <= 10^4
// s consists of only lowercase English letters.
// 1 <= k <= 10^5

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.length();
        int count[26]={0};
        int ans=0;
        unordered_set<char> filter;
        for(auto& c:s)
            count[c-'a']++;
        for(int i=0;i<26;++i)
            if(count[i] && count[i]<k)
                filter.insert(i+'a');
        if(filter.empty())
            return n;
        if(filter.size()==n)
            return 0;
        int l=0,r=0;
        while(l<n){
            while(l<n && filter.find(s[l])!=filter.end())
                l++;
            r=l+1;
            while(r<n && count[s[r]-'a']>=k)
                r++;
            ans=max(ans,longestSubstring(s.substr(l,r-l),k));
            l=r;
        }
        return ans;
    }
};
