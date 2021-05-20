// Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

 

// Example 1:

// Input: expression = "2-1-1"
// Output: [0,2]
// Explanation:
// ((2-1)-1) = 0 
// (2-(1-1)) = 2
// Example 2:

// Input: expression = "2*3-4*5"
// Output: [-34,-14,-10,-10,10]
// Explanation:
// (2*(3-(4*5))) = -34 
// ((2*3)-(4*5)) = -14 
// ((2*(3-4))*5) = -10 
// (2*((3-4)*5)) = -10 
// (((2*3)-4)*5) = 10
 

// Constraints:

// 1 <= expression.length <= 20
// expression consists of digits and the operator '+', '-', and '*'.

class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        int n=s.length();
        return helper(s,0,n);
    }
private:
    map<pair<int,int>,vector<int>> mp;
    vector<int> helper(string& s, int l, int r) {
        if(mp.count({l,r}))
            return mp[{l,r}];
        vector<int> ans;
        for(int i=l;i<r;++i){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
                vector<int> left=helper(s,l,i),right=helper(s,i+1,r);
                for(auto& x:left)
                    for(auto& y:right)
                        ans.push_back(calc(x,y,s[i]));
            }
        }
        if(ans.empty())
            ans.push_back(stoi(s.substr(l,r-l)));
        return mp[{l,r}]=move(ans);
    }
    int calc(int a, int b, char op) {
        if(op=='+')
            return a+b;
        if(op=='-')
            return a-b;
        return a*b;
    }
};
