// Given a string s representing an expression, implement a basic calculator to evaluate it.

// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

// Example 1:

// Input: s = "1 + 1"
// Output: 2
// Example 2:

// Input: s = " 2-1 + 2 "
// Output: 3
// Example 3:

// Input: s = "(1+(4+5+2)-3)+(6+8)"
// Output: 23
 

// Constraints:

// 1 <= s.length <= 3 * 10^5
// s consists of digits, '+', '-', '(', ')', and ' '.
// s represents a valid expression.

class Solution {
public:
    int calculate(string s) {
        stack<pair<int,char>> st;
        int sum=0,curr=0;
        char op='+';
        for(auto& ch:s){
            if(ch==' ')
                continue;
            if(isdigit(ch))
                curr=curr*10+(ch-'0');
            else if(ch=='+' || ch=='-'){
                sum=eval(sum,curr,op);
                curr=0;
                op=ch;
            }
            else if(ch=='('){
                st.push({sum,op});
                sum=0;
                op='+';
            }
            else{
                sum=eval(sum,curr,op);
                auto [tsum,top]=st.top();
                st.pop();
                sum=eval(tsum,sum,top);
                curr=0;
            }
        }
        return eval(sum,curr,op);
    }
private:
    int eval(int a, int b, char op) {
        if(op=='+')
            return a+b;
        return a-b;
    }
};
