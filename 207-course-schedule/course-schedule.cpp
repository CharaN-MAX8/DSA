class Solution {
public:
    bool isCycle(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>> &graph){
        vis[src] = true;
        recPath[src] = true;

        for(int v : graph[src]){
            if(!vis[v]){
                if(isCycle(v, vis, recPath, graph)) return true;
            } else {
                if(recPath[v]) return true;
            }
        }

        recPath[src] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> graph(V);

        for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(isCycle(i, vis, recPath, graph)) return false;
            }
        }

        return true;
    }
};