// Given a string s containing an out-of-order English representation of digits 0-9, return the digits in ascending order.

 

// Example 1:

// Input: s = "owoztneoer"
// Output: "012"
// Example 2:

// Input: s = "fviefuro"
// Output: "45"
 

// Constraints:

// 1 <= s.length <= 10^5
// s[i] is one of the characters ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
// s is guaranteed to be valid.

class Solution {
public:
    string originalDigits(string s) {
        string ans;
        int freq[26]={};
        for(auto& ch:s)
            freq[ch-'a']++;
        vector<int> digits={0,2,4,6,8,3,7,5,1,9};
        vector<string> words={"zero","two","four","six","eight","three","seven","five","one","nine"};
        vector<char> ch={'z','w','u','x','g','h','s','v','o','i'};
        int count[10];
        for(int i=0;i<10;++i){
            count[digits[i]]=freq[ch[i]-'a'];
            for(auto& ch:words[i])
                freq[ch-'a']-=count[digits[i]];
        }
        for(int i=0;i<10;++i)
            ans+=string(count[i],'0'+i);
        return ans;
    }
};
