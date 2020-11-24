// Implement a basic calculator to evaluate a simple expression string.

// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

// Example 1:

// Input: "3+2*2"
// Output: 7
// Example 2:

// Input: " 3/2 "
// Output: 1
// Example 3:

// Input: " 3+5 / 2 "
// Output: 5
// Note:

// You may assume that the given expression is always valid.
// Do not use the eval built-in library function.

class Solution {
public:
    int calculate(string s) {
        int n=s.length();
        while(s[n-1]==' ')
            n--;
        if(n==0)
            return 0;
        int curr=0,last=0,ans=0;
        char op='+';
        for(int i=0;i<n;++i){
            if(s[i]==' ')
                continue;
            if(isdigit(s[i])){
                do
                    curr=curr*10+(s[i++]-'0');
                while(i<n && isdigit(s[i]));
                i--;
            }
            if(i==n-1 || !isdigit(s[i])){
                if(op=='+' || op=='-'){
                    ans+=last;
                    last=(op=='+')?curr:-curr;
                }
                switch(op){
                    case '*': last*=curr;break;
                    case '/': last/=curr;break;
                }
                op=s[i];
                curr=0;
            }
        }
        return ans+=last;
    }
};
