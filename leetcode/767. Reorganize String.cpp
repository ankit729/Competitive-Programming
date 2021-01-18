// Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

// If possible, output any possible result.  If not possible, return the empty string.

// Example 1:

// Input: S = "aab"
// Output: "aba"
// Example 2:

// Input: S = "aaab"
// Output: ""
// Note:

// S will consist of lowercase letters and have length in range [1, 500].

class Solution {
public:
    string reorganizeString(string& s) {
        int n=s.length();
        string ans(n,'a');
        int count[26]={0};
        for(auto& ch:s)
            count[ch-'a']++;
        for(int i=0;i<26;++i){
            if(count[i]>(n+1)/2)
                return "";
            count[i]*=26;
            count[i]+=i;
        }
        sort(count,count+26,greater<int>());
        for(int i=0,j=0;i<26;++i){
            int cnt=count[i]/26;
            char ch='a'+(count[i]%26);
            while(cnt--){
                ans[j]=ch;
                j+=2;
                if(j>=n)
                    j=1;
            }
        }
        return ans;
    }
};
