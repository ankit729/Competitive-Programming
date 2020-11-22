// Validate if a given string can be interpreted as a decimal number.

// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
// " -90e3   " => true
// " 1e" => false
// "e3" => false
// " 6e-1" => true
// " 99e2.5 " => false
// "53.5e93" => true
// " --6 " => false
// "-+3" => false
// "95a54e53" => false

// Note: It is intended for the problem statement to be ambiguous. It would be best if you gathered all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:

// Numbers 0-9
// Exponent - "e"
// Positive/negative sign - "+"/"-"
// Decimal point - "."
// Of course, the context of these characters also matters in the input.

 

// Example 1:

// Input: s = "0"
// Output: true
// Example 2:

// Input: s = "3"
// Output: true
 

// Constraints:

// 1 <= s.length <= 20
// s consists of only English letters, digits, space ' ', plus '+', minus '-', or dot '.'.

class Solution {
public:
    bool isNumber(string s) {
        int state=0;
        int l=0,r=s.length()-1;
        while(l<r && s[l]==' ')
            l++;
        while(r>l && s[r]==' ')
            r--;
        for(int i=l;i<=r;i++){
            char x=s[i];
            switch(state){
                case 0: if(x=='+' || x=='-') state=1;
                    else if(isdigit(x)) state=2;
                    else if(x=='.') state=4;
                    else return false;
                    break;
                case 1: if(isdigit(x)) state=2;
                    else if(x=='.') state=4;
                    else return false;
                    break;
                case 2: if(isdigit(x));
                    else if(x=='.') state=3;
                    else if(x=='e') state=6;
                    else return false;
                    break;
                case 3: if(isdigit(x)) state=5;
                    else if(x=='e') state=6;
                    else return false;
                    break;
                case 4: if(isdigit(x)) state=5;
                    else return false;
                    break;
                case 5: if(isdigit(x));
                    else if(x=='e') state=6;
                    else return false;
                    break;
                case 6: if(x=='+' || x=='-') state=7;
                    else if(isdigit(x)) state=8;
                    else return false;
                    break;
                case 7: if(isdigit(x)) state=8;
                    else return false;
                    break;
                case 8: if(isdigit(x));
                    else return false;
                    break;
            }
        }
        return state==2 || state==3 || state==5 || state==8;
    }
};
