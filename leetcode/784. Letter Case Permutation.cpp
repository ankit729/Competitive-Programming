// Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

// Return a list of all possible strings we could create. You can return the output in any order.

 

// Example 1:

// Input: S = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]
// Example 2:

// Input: S = "3z4"
// Output: ["3z4","3Z4"]
// Example 3:

// Input: S = "12345"
// Output: ["12345"]
// Example 4:

// Input: S = "0"
// Output: ["0"]
 

// Constraints:

// S will be a string with length between 1 and 12.
// S will consist only of letters or digits.

class Solution {
public:
    vector<string> letterCasePermutation(string& s) {
        vector<int> pos;
        int c=0;
        for(int i=0;s[i];++i){
            if(isalpha(s[i]))
                c++,pos.push_back(i),s[i]=tolower(s[i]);
        }
        int n=(1<<c);
        vector<string> ans(n,s);
        for(int i=0,step=1;i<c;++i,step<<=1)
            for(int j=0,temp=step;j<n;j+=step,temp=step)
                while(temp--)
                    ans[j++][pos[i]]-=32;
        return ans;
    }
};
