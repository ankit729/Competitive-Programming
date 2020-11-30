class Solution {
    #define pis pair<int,string>
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto& s:words)
            mp[s]++;
        auto compare=[&](pis& l, pis& r){
            if(l.first==r.first)
                return l.second>r.second;
            return l.first<r.first;
        };
        priority_queue<pis,vector<pis>,decltype(compare)> pq(compare);
        for(auto& x:mp)
            pq.push({x.second,x.first});
        vector<string> ans(k);
        int i=0;
        while(k--){
            ans[i++]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};
