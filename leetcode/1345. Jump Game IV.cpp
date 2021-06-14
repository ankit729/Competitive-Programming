// Given an array of integers arr, you are initially positioned at the first index of the array.

// In one step you can jump from index i to index:

// i + 1 where: i + 1 < arr.length.
// i - 1 where: i - 1 >= 0.
// j where: arr[i] == arr[j] and i != j.
// Return the minimum number of steps to reach the last index of the array.

// Notice that you can not jump outside of the array at any time.

 

// Example 1:

// Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
// Output: 3
// Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
// Example 2:

// Input: arr = [7]
// Output: 0
// Explanation: Start index is the last index. You don't need to jump.
// Example 3:

// Input: arr = [7,6,9,6,9,6,9,7]
// Output: 1
// Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
// Example 4:

// Input: arr = [6,1,9]
// Output: 2
// Example 5:

// Input: arr = [11,22,7,7,7,7,7,7,7,22,13]
// Output: 3
 

// Constraints:

// 1 <= arr.length <= 5 * 10^4
// -10^8 <= arr[i] <= 10^8

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n<=1)
            return 0;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;++i)
            mp[arr[i]].push_back(i);
        bool visited[n];
        memset(visited,false,sizeof(visited));
        visited[0]=visited[n-1]=true;
        vector<int> st[3];int front=0,back=1,temp=2;
        st[front].push_back(0);
        st[back].push_back(n-1);
        int ans=0;
        while(!st[front].empty()){
            if(st[front].size()>st[back].size())
                swap(front,back);
            for(auto& x:st[front]){
                if(find(st[back].begin(),st[back].end(),x-1)!=st[back].end())
                    return ans+1;
                if(x>0 && !visited[x-1])
                    visited[x-1]=true,st[temp].push_back(x-1);
                if(find(st[back].begin(),st[back].end(),x+1)!=st[back].end())
                    return ans+1;
                if(x+1<n && !visited[x+1])
                    visited[x+1]=true,st[temp].push_back(x+1);
                for(auto& y:mp[arr[x]]){
                    if(find(st[back].begin(),st[back].end(),y)!=st[back].end())
                        return ans+1;
                    if(!visited[y] && ((y>0 && arr[y-1]!=arr[y]) || arr[y]!=arr[y+1]))
                        st[temp].push_back(y);
                    if(!visited[y])
                        visited[y]=true;
                    
                }
                mp.erase(arr[x]);
            }
            ans++;
            st[front].clear();
            swap(front,temp);
        }
        return n-1;
    }
};
