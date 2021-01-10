class FenwickTree {
    int M;
    int count[100001];
public:
    FenwickTree(vector<int>& nums) {
        M=*max_element(nums.begin(),nums.end());
        fill(count,count+M+1,0);
    }
    int get(int x) {
        int ans=0;
        while(x>0){
            ans+=count[x];
            x-=(x&-x);
        }
        return ans;
    }
    void update(int x) {
        while(x<=M){
            count[x]++;
            x+=(x&-x);
        }
    }
};
