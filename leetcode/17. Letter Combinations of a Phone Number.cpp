// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].

class Solution {
public:
    vector<string> letterCombinations(string& digits) {
        if(digits.empty())
            return vector<string>();
        vector<string> letters={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        bool flag=true;
        vector<string> ans[2];
        ans[!flag]={""};
        for(auto& x:digits){
            int num=x-'2';
            for(auto& s:ans[!flag])
                for(auto& ch:letters[num])
                    ans[flag].push_back(s+ch);
            flag=!flag;
            ans[flag].clear();
        }
        return ans[!flag];
    }
};
