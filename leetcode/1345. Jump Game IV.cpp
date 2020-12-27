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
        visited[0]=true;
        vector<int> st[2];bool flag=false;
        st[flag].push_back(0);
        int ans=0;
        while(!st[flag].empty()){
            for(auto& x:st[flag]){
                if(x>0 && !visited[x-1])
                    visited[x-1]=true,st[!flag].push_back(x-1);
                if(x+1==n-1)
                    return ans+1;
                if(!visited[x+1])
                    visited[x+1]=true,st[!flag].push_back(x+1);
                for(auto& y:mp[arr[x]]){
                    if(y==n-1)
                        return ans+1;
                    if(!visited[y])
                        visited[y]=true;
                    if((y>0 && arr[y-1]!=arr[y]) || arr[y]!=arr[y+1])
                        st[!flag].push_back(y);
                }
                mp.erase(arr[x]);
            }
            ans++;
            st[flag].clear();
            flag=!flag;
        }
        return n-1;
    }
};
