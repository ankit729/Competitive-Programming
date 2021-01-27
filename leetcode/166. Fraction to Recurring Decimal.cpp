// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in parentheses.

// If multiple answers are possible, return any of them.

// It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

 

// Example 1:

// Input: numerator = 1, denominator = 2
// Output: "0.5"
// Example 2:

// Input: numerator = 2, denominator = 1
// Output: "2"
// Example 3:

// Input: numerator = 2, denominator = 3
// Output: "0.(6)"
// Example 4:

// Input: numerator = 4, denominator = 333
// Output: "0.(012)"
// Example 5:

// Input: numerator = 1, denominator = 5
// Output: "0.2"
 

// Constraints:

// -2^31 <= numerator, denominator <= 2^31 - 1
// denominator != 0

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long int num=numerator,den=denominator;
        string ans;
        if(den<0)
            num=-num,den=-den;
        if(num<0)
            ans+='-',num=-num;
        if(num>=den){
            ans+=to_string((long int) num/den);
            num%=den;
        }
        else
            ans+=to_string(0);
        if(num==0)
            return ans;
        ans+='.';
        string ans2;
        unordered_map<int,int> mp;
        int l=0;
        while(num>0){
            if(mp.count(num)){
                ans2.insert(ans2.begin()+mp[num],'(');
                ans2+=')';
                return ans+ans2;
            }
            mp[num]=l++;
            num*=10;
            ans2+=to_string((long int) num/den);
            num%=den;
        }
        return ans+ans2;
    }
};
