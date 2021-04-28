// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

// Return all critical connections in the network in any order.

 

// Example 1:



// Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
// Output: [[1,3]]
// Explanation: [[3,1]] is also accepted.
 

// Constraints:

// 2 <= n <= 10^5
// n - 1 <= connections.length <= 10^5
// 0 <= ai, bi <= n - 1
// ai != bi
// There are no repeated connections.

class graph {
    int V;
    vector<vector<int>> adj;
public:
    graph(int V) {
        this->V=V;
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> get() {
        vector<vector<int>> ans;
        vector<int> visited(V,-1);
        visited[0]=0;
        for(auto& nei:adj[0])
            if(0<helper(nei,0,visited,ans))
                ans.push_back({0,nei});
        return ans;
    }
private:
    int helper(int curr, int par, vector<int>& visited, vector<vector<int>>& ans) {
        if(visited[curr]!=-1)
            return visited[curr];
        int ret=visited[curr]=1+visited[par];
        for(auto& nei:adj[curr]){
            if(nei==par)
                continue;
            int temp=helper(nei,curr,visited,ans);
            ret=min(ret,temp);
            if(visited[curr]<temp)
                ans.push_back({min(curr,nei),max(curr,nei)});
        }
        return visited[curr]=ret;
    }
};

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph g(n);
        for(auto& x:connections)
            g.addEdge(x[0],x[1]);
        return g.get();
    }
};
