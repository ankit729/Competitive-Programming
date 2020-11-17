// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
 

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false
// Example 4:

// Input: s = "([)]"
// Output: false
// Example 5:

// Input: s = "{[]}"
// Output: true
 

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        for(auto x:s){
            if(x=='(' || x=='{' || x=='[')
                a.push(x);
            else{
                if(!a.empty() && ((a.top()=='(' && x==')') || (a.top()=='{' && x=='}') || (a.top()=='[' && x==']')))
                    a.pop();
                else
                    return false;
            }
        }
        return a.empty();
    }
};
