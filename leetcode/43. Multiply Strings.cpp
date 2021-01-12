// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

// Example 1:

// Input: num1 = "2", num2 = "3"
// Output: "6"
// Example 2:

// Input: num1 = "123", num2 = "456"
// Output: "56088"
 

// Constraints:

// 1 <= num1.length, num2.length <= 200
// num1 and num2 consist of digits only.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.length(),n2=num2.length();
        string ans(n1+n2,'0');
        for(int i=n1-1;i>=0;--i){
            for(int j=n2-1;j>=0;--j){
                int8_t digit=(num1[i]-'0')*(num2[j]-'0')+(ans[i+j+1]-'0');
                ans[i+j+1]='0'+(digit%10);
                ans[i+j]+=digit/10;
            }
        }
        for(int i=0;i<n1+n2;++i)
            if(ans[i]!='0')
                return ans.substr(i);
        return "0";
    }
};
