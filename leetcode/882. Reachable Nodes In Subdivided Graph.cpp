// Starting with an undirected graph (the "original graph") with nodes from 0 to N-1, subdivisions are made to some of the edges.

// The graph is given as follows: edges[k] is a list of integer pairs (i, j, n) such that (i, j) is an edge of the original graph,

// and n is the total number of new nodes on that edge. 

// Then, the edge (i, j) is deleted from the original graph, n new nodes (x_1, x_2, ..., x_n) are added to the original graph,

// and n+1 new edges (i, x_1), (x_1, x_2), (x_2, x_3), ..., (x_{n-1}, x_n), (x_n, j) are added to the original graph.

// Now, you start at node 0 from the original graph, and in each move, you travel along one edge. 

// Return how many nodes you can reach in at most M moves.

 

// Example 1:

// Input: edges = [[0,1,10],[0,2,1],[1,2,2]], M = 6, N = 3
// Output: 13
// Explanation: 
// The nodes that are reachable in the final graph after M = 6 moves are indicated below.

// Example 2:

// Input: edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], M = 10, N = 4
// Output: 23
 

// Note:

// 0 <= edges.length <= 10000
// 0 <= edges[i][0] < edges[i][1] < N
// There does not exist any i != j for which edges[i][0] == edges[j][0] and edges[i][1] == edges[j][1].
// The original graph has no parallel edges.
// 0 <= edges[i][2] <= 10000
// 0 <= M <= 10^9
// 1 <= N <= 3000
// A reachable node is a node that can be travelled to using at most M moves starting from node 0.

class Solution {
    #define pii pair<int,int>
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        vector<vector<pii>> graph(N);
        for(auto& edge:edges){
            int u=edge[0],v=edge[1],w=edge[2]+1;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,0});
        int dis[N];
        dis[0]=0;
        for(int i=1;i<N;++i)
            dis[i]=M+1;
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            for(auto& nn:graph[u]){
                int v=nn.first,w=nn.second;
                if(dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                    if(dis[v]<M)
                        pq.push({dis[v],v});
                }
            }
        }
        int ans=0;
        for(int x:dis)
            if(x<=M)
                ans++;
        for(auto& edge:edges){
            int u=edge[0],v=edge[1],w=edge[2];
            int du=(M-dis[u]>0?M-dis[u]:0),dv=(M-dis[v]>0?M-dis[v]:0);
            ans+=min(w,du+dv);
        }
        return ans;
    }
};
