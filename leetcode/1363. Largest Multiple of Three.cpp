// Given an integer array of digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order.

// Since the answer may not fit in an integer data type, return the answer as a string.

// If there is no answer return an empty string.

 

// Example 1:

// Input: digits = [8,1,9]
// Output: "981"
// Example 2:

// Input: digits = [8,6,7,1,0]
// Output: "8760"
// Example 3:

// Input: digits = [1]
// Output: ""
// Example 4:

// Input: digits = [0,0,0,0,0,0]
// Output: "0"
 

// Constraints:

// 1 <= digits.length <= 10^4
// 0 <= digits[i] <= 9
// The returning answer must not contain unnecessary leading zeros.

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        string ans;
        int freq[10]={},sum=0;
        int l1[]={1,4,7,2,5,8};
        for(auto& x:digits)
            freq[x]++,sum+=x;
        while(sum%3!=0){
            int i=(sum%3==1)?0:3;
            for(int j=0;j<6;++j){
                int x=l1[i];
                if(freq[x]){
                    freq[x]--;
                    sum-=x;
                    break;
                }
                i=(i+1)%6;
            }
        }
        for(int i=9;i>=0;--i)
            ans+=string(freq[i],'0'+i);
        return (ans.length() && ans[0]=='0')?"0":ans;
    }
};
