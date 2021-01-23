// You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

 

// Example 1:

// Input: nums = [5,2,6,1]
// Output: [2,1,1,0]
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
 

// Constraints:

// 0 <= nums.length <= 10^5
// -10^4 <= nums[i] <= 10^4

class Solution {
    struct trienode {
        int count=0;
        trienode* zero=NULL;
        trienode* one=NULL;
    };
public:
    vector<int> countSmaller(vector<int> nums) {
        int n=nums.size();
        trienode* root=new trienode();
        root->zero=new trienode();
        root->one=new trienode();
        while(n--){
            int count=0;
            bitset<32> bs(nums[n]);
            trienode* cp;
            cp=(bs[31])?root->one:root->zero;
            for(int i=30;i>=0;--i){
                cp->count++;
                if(!bs[i]){
                    if(!cp->zero)
                        cp->zero=new trienode();
                    cp=cp->zero;
                }
                else{
                    if(cp->zero)
                        count+=cp->zero->count;
                    if(!cp->one)
                        cp->one=new trienode();
                    cp=cp->one;
                }
            }
            cp->count++;
            nums[n]=(!bs[31])?count+root->one->count:count;
        }
        del(root);
        return nums;
    }
private:
    void del(trienode* root) {
        if(!root)
            return;
        del(root->zero);
        del(root->one);
        delete(root);
    }
};
