class Solution {
public:
    bool makesquare(vector<int>& ms) {
        long int sum=accumulate(ms.begin(),ms.end(),0L);
        sort(ms.begin(),ms.end(),greater<int>());
        if(sum&3)
            return false;
        sum>>=2;
        this->sum=sum;
        fill(sums,sums+4,0);
        return check(ms,0);
    }
private:
    int sums[4]={},sum;
    bool check(vector<int>& ms, int i) {
        if(i==ms.size())
            return true;
        for(int j=0;j<4;++j){
            if(ms[i]+sums[j]>sum)
                continue;
            int k=j;
            while(--k>=0)
                if(sums[j]==sums[k])
                    break;
            if(k>=0)
                continue;
            sums[j]+=ms[i];
            if(check(ms,i+1))
                return true;
            sums[j]-=ms[i];
        }
        return false;
    }
};
