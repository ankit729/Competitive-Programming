class monoQueue {
    deque<pair<int,int>> mq;
public:
    void push(int val) {
        int count=0;
        while(!mq.empty() && mq.back().first<=val){
            count+=mq.back().second+1;
            mq.pop_back();
        }
        mq.emplace_back(val,count);
    }
    void pop() {
        if(mq.front().second>0)
            mq.front().second--;
        else
            mq.pop_front();
    }
    int max() {
        return mq.front().first;
    }
};
