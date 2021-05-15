// A valid number can be split up into these components (in order):

// A decimal number or an integer.
// (Optional) An 'e' or 'E', followed by an integer.
// A decimal number can be split up into these components (in order):

// (Optional) A sign character (either '+' or '-').
// One of the following formats:
// At least one digit, followed by a dot '.'.
// At least one digit, followed by a dot '.', followed by at least one digit.
// A dot '.', followed by at least one digit.
// An integer can be split up into these components (in order):

// (Optional) A sign character (either '+' or '-').
// At least one digit.
// For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

// Given a string s, return true if s is a valid number.

 

// Example 1:

// Input: s = "0"
// Output: true
// Example 2:

// Input: s = "e"
// Output: false
// Example 3:

// Input: s = "."
// Output: false
// Example 4:

// Input: s = ".1"
// Output: true
 

// Constraints:

// 1 <= s.length <= 20
// s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.

class Solution {
public:
    bool isNumber(string s) {
        int state=0;
        for(auto& ch:s){
            switch(state){
                case 0: if(ch=='+' || ch=='-') state=1;
                    else if(isdigit(ch)) state=2;
                    else if(ch=='.') state=4;
                    else return false;
                    break;
                case 1: if(isdigit(ch)) state=2;
                    else if(ch=='.') state=4;
                    else return false;
                    break;
                case 2: if(isdigit(ch));
                    else if(ch=='.') state=3;
                    else if(ch=='e' || ch=='E') state=6;
                    else return false;
                    break;
                case 3: if(isdigit(ch)) state=5;
                    else if(ch=='e' || ch=='E') state=6;
                    else return false;
                    break;
                case 4: if(isdigit(ch)) state=5;
                    else return false;
                    break;
                case 5: if(isdigit(ch));
                    else if(ch=='e' || ch=='E') state=6;
                    else return false;
                    break;
                case 6: if(ch=='+' || ch=='-') state=7;
                    else if(isdigit(ch)) state=8;
                    else return false;
                    break;
                case 7: if(isdigit(ch)) state=8;
                    else return false;
                    break;
                case 8: if(isdigit(ch));
                    else return false;
                    break;
            }
        }
        return state==2 || state==3 || state==5 || state==8;
    }
};
