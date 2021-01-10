class graphU {
public:
    graphU(int V) {
        v=V;
        adj=new vector<int>[v];
    }
    void addEdge(int u,int v) {
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    bool isCyclic() {
        vector<bool> visited(v,false);
        for(int i=0;i<v;++i)
            if(!visited[i] && isCyclicUtil(i,visited,-1))
                return true;
        return false;
    }
private:
    int v;
    vector<int>* adj;
    bool isCyclicUtil(int& u, vector<bool>& visited, int parent) {
        visited[u]=true;
        for(int v:adj[u]){
            if(!visited[v]){
                if(isCyclicUtil(v,visited,u))
                    return true;
            }
            else if(v!=parent)
                return true;
        }
        return false;
    }
};
