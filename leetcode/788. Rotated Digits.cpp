// X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.  Each digit must be rotated - we cannot choose to leave it alone.

// A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other (on this case they are rotated in a different direction, in other words 2 or 5 gets mirrored); 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.

// Now given a positive number N, how many numbers X from 1 to N are good?

// Example:
// Input: 10
// Output: 4
// Explanation: 
// There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
// Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
// Note:

// N  will be in range [1, 10000].

class Solution {
public:
    int rotatedDigits(int n) {
        int ans=0;
        string s=to_string(n);
        n=s.length();
        bool flag=false;
        int type[]={0,0,1,2,2,1,1,2,0,1},
            diff[]={0,0,1,1,1,2,3,3,3,4},
            valid[]={1,2,3,3,3,4,5,5,6,7},
            same[]={1,2,2,2,2,2,2,2,3,3};
        for(int i=0;i<n-1;++i){
            int d=s[i]-'0';
            if(d>0)
                ans+=valid[d-1]*pow(7,n-1-i)-((flag)?0:same[d-1]*pow(3,n-1-i));
            if(type[d]==1)
                flag=true;
            else if(type[d]==2)
                return ans;
        }
        return ans+=(flag)?valid[s[n-1]-'0']:diff[s[n-1]-'0'];
    }
};
