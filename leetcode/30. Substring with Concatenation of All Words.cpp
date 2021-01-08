// You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

// You can return the answer in any order.

 

// Example 1:

// Input: s = "barfoothefoobarman", words = ["foo","bar"]
// Output: [0,9]
// Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
// The output order does not matter, returning [9,0] is fine too.
// Example 2:

// Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
// Output: []
// Example 3:

// Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
// Output: [6,9,12]
 

// Constraints:

// 1 <= s.length <= 10^4
// s consists of lower-case English letters.
// 1 <= words.length <= 5000
// 1 <= words[i].length <= 30
// words[i] consists of lower-case English letters.

class Solution {
public:
    vector<int> findSubstring(string& s, vector<string>& words) {
        int len=s.length(),n=words.size(),m=words[0].length();
        vector<int> ans;
        unordered_map<string,int> freq;
        for(auto& word:words)
            freq[word]++;
        for(int i=0;i<m;++i){
            int l=0,r=-1;
            vector<string> wf;
            unordered_map<string,int> seen;
            for(int j=i;j<=len-m;j+=m){
                string word=s.substr(j,m);
                if(freq.count(word)){
                    seen[word]++;
                    wf.push_back(word);
                    r++;
                    while(seen[word]>freq[word])
                        seen[wf[l++]]--;
                    if(r-l+1==n)
                        ans.push_back(j-(n-1)*m);
                }
                else{
                    seen.clear();
                    wf.clear();
                    l=0;
                    r=-1;
                }
            }
        }
        return ans;
    }
};
