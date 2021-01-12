// Return the result of evaluating a given boolean expression, represented as a string.

// An expression can either be:

// "t", evaluating to True;
// "f", evaluating to False;
// "!(expr)", evaluating to the logical NOT of the inner expression expr;
// "&(expr1,expr2,...)", evaluating to the logical AND of 2 or more inner expressions expr1, expr2, ...;
// "|(expr1,expr2,...)", evaluating to the logical OR of 2 or more inner expressions expr1, expr2, ...
 

// Example 1:

// Input: expression = "!(f)"
// Output: true
// Example 2:

// Input: expression = "|(f,t)"
// Output: true
// Example 3:

// Input: expression = "&(t,f)"
// Output: false
// Example 4:

// Input: expression = "|(&(t,f,t),!(t))"
// Output: false
 

// Constraints:

// 1 <= expression.length <= 20000
// expression[i] consists of characters in {'(', ')', '&', '|', '!', 't', 'f', ','}.
// expression is a valid expression representing a boolean, as given in the description.

class Solution {
public:
    bool parseBoolExpr(string e) {
        stack<char> st;
        for(auto ch:e){
            if(ch==',' || ch=='(')
                continue;
            if(ch==')'){
                bool t=false,f=false;
                ch=st.top();
                while(ch=='t' || ch=='f'){
                    t|=ch=='t';
                    f|=ch=='f';
                    st.pop();
                    ch=st.top();
                }
                st.pop();
                if(ch=='!')
                    ch=t?'f':'t';
                else if(ch=='&')
                    ch=!f?'t':'f';
                else
                    ch=t?'t':'f';
                st.push(ch);
            }
            else
                st.push(ch);
        }
        return st.top()=='t';
    }
};
