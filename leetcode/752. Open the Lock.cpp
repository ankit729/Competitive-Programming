// You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

// The lock initially starts at '0000', a string representing the state of the 4 wheels.

// You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

// Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

 

// Example 1:

// Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
// Output: 6
// Explanation:
// A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
// Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
// because the wheels of the lock become stuck after the display becomes the dead end "0102".
// Example 2:

// Input: deadends = ["8888"], target = "0009"
// Output: 1
// Explanation:
// We can turn the last wheel in reverse to move from "0000" -> "0009".
// Example 3:

// Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
// Output: -1
// Explanation:
// We can't reach the target without getting stuck.
// Example 4:

// Input: deadends = ["0000"], target = "8888"
// Output: -1
 

// Constraints:

// 1 <= deadends.length <= 500
// deadends[i].length == 4
// target.length == 4
// target will not be in the list deadends.
// target and deadends[i] consist of digits only.

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target=="0000")
            return 0;
        int ans=0;
        unordered_set<int> dead,q[3];
        int front=0,back=1,temp=2;
        for(auto& s:deadends)
            dead.insert(stoi(s));
        if(dead.count(0))
            return -1;
        bool visited[10000];
        memset(visited,false,sizeof(visited));
        q[front].insert(0);visited[0]=true;
        q[back].insert(stoi(target));visited[stoi(target)]=true;
        while(!q[front].empty()){
            if(q[front].size()>q[back].size())
                swap(front,back);
            for(auto& num:q[front]){
                string s=get(num);
                int sn;
                for(int i=0;i<4;++i){
                    s[i]=s[i]=='9'?'0':s[i]+1;
                    sn=stoi(s);
                    if(q[back].count(sn))
                        return ans+1;
                    if(!dead.count(sn) && !visited[sn])
                        q[temp].insert(sn),visited[sn]=true;
                    
                    s[i]=s[i]<'2'?s[i]+8:s[i]-2;
                    sn=stoi(s);
                    if(q[back].count(sn))
                        return ans+1;
                    if(!dead.count(sn) && !visited[sn])
                        q[temp].insert(sn),visited[sn]=true;
                    
                    s[i]=s[i]=='9'?'0':s[i]+1;
                }
            }
            q[front].clear();
            swap(front,temp);
            ans++;
        }
        return -1;
    }
private:
    string get(int n) {
        string ans=to_string(n);
        ans=string(4-ans.length(),'0')+ans;
        return ans;
    }
};
