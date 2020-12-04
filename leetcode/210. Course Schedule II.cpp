// There are a total of n courses you have to take labelled from 0 to n - 1.

// Some courses may have prerequisites, for example, if prerequisites[i] = [ai, bi] this means you must take the course bi before the course ai.

// Given the total number of courses numCourses and a list of the prerequisite pairs, return the ordering of courses you should take to finish all courses.

// If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
// Example 2:

// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
// So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
// Example 3:

// Input: numCourses = 1, prerequisites = []
// Output: [0]
 

// Constraints:

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= numCourses * (numCourses - 1)
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// ai != bi
// All the pairs [ai, bi] are distinct.

class graphD {
    int v;
    vector<int>* adj;
public:
    graphD(int V) {
        v=V;
        adj=new vector<int>[v];
    }
    void addEdge(int u,int v) {
        adj[u].emplace_back(v);
    }
    bool isCyclicUtil(int u, vector<int8_t>& visited, vector<int>& order) {
        visited[u]=1;
        for(int v:adj[u])
            if(visited[v]==1 || (visited[v]==0 && isCyclicUtil(v,visited,order)))
                return true;
        visited[u]=2;
        order.push_back(u);
        return false;
    }
    bool isCyclic(vector<int>& order) {
        vector<int8_t> visited(v,0);
        for(int i=0;i<v;++i)
            if(visited[i]==0 && isCyclicUtil(i,visited,order))
                return true;
        return false;
    }
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graphD g(numCourses);
        for(auto& edge:prerequisites)
            g.addEdge(edge[1],edge[0]);
        vector<int> order;
        if(!g.isCyclic(order)){
            reverse(order.begin(),order.end());
            return order;
        }
        return {};
    }
};
auto fastIO=[](){std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
