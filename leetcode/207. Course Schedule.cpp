// There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0, and to take course 0 you should
//              also have finished course 1. So it is impossible.
 

// Constraints:

// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// You may assume that there are no duplicate edges in the input prerequisites.
// 1 <= numCourses <= 10^5

class graphD {
public:
    graphD(int V) {
        v=V;
        adj=new vector<int>[v];
    }
    void addEdge(int u,int v) {
        adj[u].push_back(v);
    }
    bool isCyclicUtil(int u, vector<int8_t>& visited) {
        visited[u]=1;
        for(auto& v:adj[u])
            if(visited[v]==1 || (visited[v]==0 && isCyclicUtil(v,visited)))
                return true;
        visited[u]=2;
        return false;
    }
    bool isCyclic() {
        vector<int8_t> visited(v,0);
        for(int i=0;i<v;++i)
            if(visited[i]==0 && isCyclicUtil(i,visited))
                return true;
        return false;
    }
private:
    int v;
    vector<int>* adj;
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graphD g(numCourses);
        for(auto& edge:prerequisites)
            g.addEdge(edge[1],edge[0]);
        return !g.isCyclic();
    }
};
