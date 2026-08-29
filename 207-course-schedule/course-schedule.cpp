class Solution {
public:
    bool dirCycleHelper(int src, vector<int> &vis, vector<int> &recPath, vector<vector<int>>& graph){
        vis[src] = true;
        recPath[src] = true;

       for(int i=0; i<graph.size(); i++){
        int u = graph[i][1];
        int v = graph[i][0];
        if(u == src){
            if(!vis[v]){
                if(dirCycleHelper(v, vis, recPath, graph)){
                    return true;
                }
            } else {
                if(recPath[v]){
                    return true;
                }
            }
        }
       }
        recPath[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& graph) {
        int V = numCourses;
        vector<int> vis(V, false);
        vector<int> recPath(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dirCycleHelper(i, vis, recPath, graph)){
                    return false;
                } 
            }
        }

return true;
    }
};