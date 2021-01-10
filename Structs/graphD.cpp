class graphD {
public:
    graphD(int V) {
        v=V;
        adj=new vector<int>[v];
    }
    void addEdge(int u,int v) {
        adj[u].push_back(v);
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
    bool isCyclicUtil(int u, vector<int8_t>& visited) {
        visited[u]=1;
        for(auto& v:adj[u])
            if(visited[v]==1 || (visited[v]==0 && isCyclicUtil(v,visited)))
                return true;
        visited[u]=2;
        return false;
    }
};
